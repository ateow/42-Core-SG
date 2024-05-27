#include "libs.hpp"
#include "EpollServer.hpp"

/*---------------------------------------------------------------------------*/
//Public functions
/*---------------------------------------------------------------------------*/

static void closeConnection(int fd, std::deque<int> &clientfds);

void EpollServer::checkRequests()
{
    std::map<std::time_t, incompleteRequest>::iterator it = incompleterequests.begin();
    while (it != incompleterequests.end())
    {
        std::time_t now = std::time(0);
        if (now - it->first > TIMEOUT_SECS)
        {
            incompleteRequest &request = it->second;
            closeConnection(request.fd, clientfds);
            incompleterequests.erase(it++);
        }
        else
            ++it;
    }
}

void EpollServer::runServer()
{
    struct epoll_event ev, events[MAX_EVENTS];
    struct sockaddr_in client_addr;
    socklen_t client_len = sizeof(client_addr);
    int numfds, connection;

    while (1)
    {
        numfds = epoll_wait(epollfd, events, MAX_EVENTS, EPOLL_TIMEOUT);
        if (numfds == -1)
        {
            if (errno == EINTR)
            {
                std::cout << "Shutting down server" << std::endl;
                return ;
            } 
            perror("epoll_wait");
            throw std::runtime_error("Error in epoll_wait");
        }
        else if (numfds == 0)
        {
            checkRequests();
            continue ;
        }

        for (int i = 0; i < numfds; i++)
        {
            std::cout << "====================================" << std::endl;
            std::cout << "Event on fd: " << events[i].data.fd << std::endl;
            if (std::find(socketfds.begin(), socketfds.end(), events[i].data.fd) != socketfds.end())
            {
                connection = accept(events[i].data.fd, reinterpret_cast<struct sockaddr*>(&client_addr), &client_len);
                if (connection == -1)
                {
                    perror("accept");
                    throw std::runtime_error("Error accepting new connection");
                }
                //setting timeout for connection
                struct timeval tv;
                tv.tv_sec = TIMEOUT_SECS;
                tv.tv_usec = 0;
                if (setsockopt(connection, SOL_SOCKET, SO_RCVTIMEO, &tv, sizeof(tv)) < 0)
                {
                    perror("setsockopt");
                    throw std::runtime_error("Error setting timeout for connection");
                }
                if (setsockopt(connection, SOL_SOCKET, SO_SNDTIMEO, &tv, sizeof(tv)) < 0)
                {
                    perror("setsockopt");
                    throw std::runtime_error("Error setting timeout for connection");
                }
                std::cout << "Accepted new connection: " << connection << std::endl;
                ev.events = EPOLLIN | EPOLLET;
                ev.data.fd = connection;
                if (epoll_ctl(epollfd, EPOLL_CTL_ADD, connection, &ev) == -1)
                {
                    perror("epoll_ctl: conn_sock");
                    throw std::runtime_error("Error adding new connection socket to epoll");
                }
                if (clientfds.size() >= MAX_CONNECTIONS)
                {
                    std::deque<int>::iterator it = clientfds.begin();
                    close(*it);
                    clientfds.pop_front();
                }
                clientfds.push_back(connection);
                //read from connection
                try
                {
                    readFromConnection(connection);
                }
                catch(const std::exception& e)
                {
                    std::cerr << e.what() << '\n';
                }

            }
            else if (events[i].events & EPOLLIN)
            {
                std::cout << "Existing connection!" << std::endl;
                try
                {
                    readFromConnection(events[i].data.fd);
                }
                catch(const std::exception& e)
                {
                    std::cerr << e.what() << '\n';
                }
                
            }

            std::cout << "====================================" << std::endl << std::endl;
        }
    }
}

/*---------------------------------------------------------------------------*/
//Initialising functions
/*---------------------------------------------------------------------------*/

EpollServer::EpollServer(WebServerConfig serverconfig) : epollfd(-1)
{
    config = serverconfig;
    initServer();
}

//destructor - clean up open fds
EpollServer::~EpollServer()
{
    uint64_t u = 1;
    write(shutdownfd, &u, sizeof(uint64_t));
    close(shutdownfd);
    for (size_t i = 0; i < this->config.servers.size(); ++i)
    {
        if (socketfds[i] != -1)
        {
            std::cout << "Closing socket: " << socketfds[i] << std::endl;
            close(socketfds[i]);
        }
    }
    for (std::deque<int>::iterator it = clientfds.begin(); it != clientfds.end(); ++it)
    {
        if (*it != -1)
        {
            std::cout << "Closing client connection: " << *it << std::endl;
            close(*it);
        }
    }
    if (epollfd != -1)
    {
        std::cout << "Closing epoll file descriptor: " << epollfd << std::endl;
        close(epollfd);
    }
}

void EpollServer::initServer()
{
    //input to epoll_create is a hint to the number of added file descriptors
    //for the kernel to decide how much space to initially allocate
    //kernel will allocate more if necessary, but still has to be greater than 0
    //for backwards compatibility
    epollfd = epoll_create(10);
    requestsizelimit = 0;
    if (epollfd == -1)
    {
        perror("epoll_create1");
        throw std::runtime_error("Failed to create epoll file descriptor");
    }
    shutdownfd = eventfd(0, EFD_NONBLOCK);
    if (shutdownfd == -1)
    {
        perror("eventfd");
        throw std::runtime_error("Failed to create shutdown file descriptor");
    }
    struct epoll_event ev;
    ev.events = EPOLLIN;
    ev.data.fd = shutdownfd;
    if (epoll_ctl(epollfd, EPOLL_CTL_ADD, shutdownfd, &ev) == -1)
    {
        perror("epoll_ctl: shutdownfd");
        throw std::runtime_error("Failed to add shutdown file descriptor to epoll");
    }

    size_t serversstarted = 0;
    for (size_t i = 0; i < this->config.servers.size(); ++i)
    {
        const ServerConfig &server = this->config.servers[i];

        std::cout << "Server " << i + 1 << ":\n";
        std::cout << "  Host: " << server.host << "\n";
        std::cout << "  Port: " << server.port << "\n";
        std::cout << "  Server Names: ";
        for (size_t j = 0; j < server.server_names.size(); ++j)
        {
            std::cout << server.server_names[j] << (j + 1 < server.server_names.size() ? ", " : "\n");
        }
        std::cout << "  Client Body Size Limit: " << server.limit_client_body_size << "\n";
        if (static_cast<size_t>(server.limit_client_body_size_bytes) > requestsizelimit)
            requestsizelimit = server.limit_client_body_size_bytes;
        std::cout << "  Default Error Pages:\n";
        for (std::map<int, std::string>::const_iterator it = server.default_error_pages.begin(); it != server.default_error_pages.end(); ++it)
        {
            std::cout << "    " << it->first << ": " << it->second << "\n";
        }
        try
        {
            addSocket(server);
            ports.push_back(server.port);
            serversstarted++;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }
    if (serversstarted == 0)
    {
        throw std::runtime_error("Failed to start any servers");
    }
    else
    {
        std::cout << "Started " << serversstarted << " servers" << std::endl;
    }
}

void EpollServer::addSocket(const ServerConfig &server)
{
    //int socket(int domain, int type, int protocol);
    //AF_INET - IPV4
    //SOCK_NONBLOCK - Set  the O_NONBLOCK file status flag on the open file descriptor. 
    //Using this flag saves extra calls to fcntl(2) to achieve the same result.
    int socketfd = socket(AF_INET, SOCK_STREAM | SOCK_NONBLOCK, 0);
    if (socketfd == -1)
    {
        perror("socket");
        throw std::runtime_error("Failed to create socket.\n");
    }
    int enable = 1;
    if (setsockopt(socketfd, SOL_SOCKET, SO_REUSEADDR, &enable, sizeof(int)) < 0)
    {
        perror("setsockopt(SO_REUSEADDR) failed");
        throw std::runtime_error("Failed to set socket options.\n");
    }
    socketfds.push_back(socketfd);
    std::cout << "Socket : " << socketfd << " created." << std::endl;

    //sockaddir_in is protocol specific, in this case IPV4
    struct sockaddr_in addr;
    std::memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;

    addr.sin_addr.s_addr = inet_addr(server.host.c_str());
    addr.sin_port = htons(server.port);

    if (bind(socketfd, reinterpret_cast<struct sockaddr*>(&addr), sizeof(addr)) == -1)
    {
        perror("bind");
        throw std::runtime_error("Failed to bind socket.\n");
    }
    std::cout << "Socket bound to port: " << server.port << std::endl;
    if (listen(socketfd, SOMAXCONN) == -1)
    {
        perror("listen");
        throw std::runtime_error("Failed to listen.\n");
    }
    struct epoll_event ev;
    ev.events = EPOLLIN;
    ev.data.fd = socketfd;
    if (epoll_ctl(epollfd, EPOLL_CTL_ADD, socketfd, &ev) == -1)
    {
        perror("epoll_ctl: listen_sock");
        throw std::runtime_error("Failed to add listening socket to epoll.\n");
    }
    std::cout << "Listening on port: " << server.port << std::endl << std::endl;
}

/*---------------------------------------------------------------------------*/
//Send and receive functions
/*---------------------------------------------------------------------------*/

static bool isReadingDone(std::vector<char> &buffer)
{
    std::string request;
    std::vector<char> body = buffer;

    while (request.find("\r\n\r\n") == std::string::npos && !body.empty())
    {
        request += body[0];
        body.erase(body.begin());
    }
    if (body.empty() && request.find("\r\n\r\n") == std::string::npos)
        return false;
    //if content-length present, body should contain that many bytes
    if (request.find("Content-Length: ") != std::string::npos)
    {
        size_t pos = request.find("Content-Length: ") + 16;
        size_t end = request.find("\r\n", pos);
        size_t length = atoi(request.substr(pos, end - pos).c_str());
        if (body.size() == length || length == std::numeric_limits<size_t>::max())
            return true;
    }
    if (request.find("Transfer-Encoding: chunked") != std::string::npos)
    {
        size_t pos = 0;
        while (pos < body.size())
        {
            // Find the end of the chunk size
            size_t size_end_pos = pos;
            while (size_end_pos < body.size() && body[size_end_pos] != '\r')
            {
                size_end_pos++;
            }
            // Ensure there's a valid \r\n after the chunk size
            if (size_end_pos >= body.size() || body[size_end_pos + 1] != '\n')
            {
                throw std::runtime_error("incorrect chunked encoding format");
            }

            // Extract the chunk size in hexadecimal
            std::string chunknumber(body.begin() + pos, body.begin() + size_end_pos);
            size_t chunksize;
            std::stringstream chunkstream(chunknumber);
            chunkstream >> std::hex >> chunksize;

            // Calculate the start of the chunk data
            size_t data_start_pos = size_end_pos + 2;

            // Ensure there's enough data for the chunk
            if (data_start_pos + chunksize > body.size())
            {
                throw std::runtime_error("incorrect chunked encoding format");
            }

            // Check for the terminating \r\n after the chunk data
            if (body[data_start_pos + chunksize] != '\r' || body[data_start_pos + chunksize + 1] != '\n')
            {
                throw std::runtime_error("incorrect chunked encoding format");
            }

            // Move to the next chunk
            pos = data_start_pos + chunksize + 2;

            // Check for the final chunk (size 0)
            if (chunksize == 0)
            {
                return true;
            }
        }
    }
    //no content-length present and no transfer-encoding, read until \r\n\r\n
    else if (request.find("\r\n\r\n") != std::string::npos)
    {
        return true;
    }
    return false;
}

static void closeConnection(int fd, std::deque<int> &clientfds)
{
    close(fd);
    std::cout << "Closing connection: " << fd << std::endl;
    for (std::deque<int>::iterator it = clientfds.begin(); it != clientfds.end(); ++it)
    {
        if (*it == fd)
        {
            clientfds.erase(it);
            break ;
        }
    }
}

static void checkIncompleteRequest(int fd, std::map<std::time_t, incompleteRequest> &incompleterequests, std::vector<char> &buffer, size_t &totalBytes)
{
    std::map<std::time_t, incompleteRequest>::iterator it = incompleterequests.begin();
    while (it != incompleterequests.end())
    {
        incompleteRequest &request = it->second;
        if (request.fd == fd)
        {
            buffer = request.buffer;
            totalBytes = buffer.size();
            incompleterequests.erase(it);
            break ;
        }
        else
            ++it;
    }
}

bool EpollServer::receiveData(int fd, std::vector<char> &buffer, size_t &totalBytes)
{
    size_t bytesExpected = 1024 * 128;
    int bytesRead = 0;

    //check if fd is in incomplete requests and continue with reading
    checkIncompleteRequest(fd, incompleterequests, buffer, totalBytes);
    //read from connection
    do
    {
        if (totalBytes > requestsizelimit)
            throw std::runtime_error("request size too big");
        buffer.resize(totalBytes + bytesExpected);
        bytesRead = recv(fd, buffer.data() + totalBytes, bytesExpected, MSG_DONTWAIT);
        if (bytesRead < 1)
            break ;
        totalBytes += bytesRead;
        buffer.resize(totalBytes);
        if (isReadingDone(buffer))
            break ;
    } while (static_cast<size_t>(bytesRead) > 0);

    buffer.resize(totalBytes);
    if (bytesRead == 0)
    {
        return false;
    }
    //if bytesRead is -1 store in incomplete requests
    if (bytesRead == -1 && !isReadingDone(buffer))
    {
        std::time_t now = std::time(0);
        incompleteRequest request;
        request.fd = fd;
        request.buffer = buffer;
        incompleterequests[now] = request;
        return false;
    }
    return true;
}

static void extractFormData(std::vector<char> buffer, std::map<std::string, std::vector<char> > &files, std::string boundary)
{
    size_t boundaryLength = boundary.length();
    std::string body;
    std::vector<char> fileBuffer;
    
    //append to body until blank line is found
    while (body.find("\r\n\r\n") == std::string::npos && !buffer.empty())
    {
        body += buffer[0];
        buffer.erase(buffer.begin());
    }
    //add to fileBuffer until boundary is found
    while ((fileBuffer.size() < boundaryLength || std::string(fileBuffer.end() - boundaryLength, fileBuffer.end()) != boundary) && !buffer.empty())
    {
        fileBuffer.push_back(buffer[0]);
        buffer.erase(buffer.begin());
    }
    //remove boundary from fileBuffer and add to body
    if (buffer.empty())
        return void(0);
    body += std::string(fileBuffer.end() - boundaryLength, fileBuffer.end());
    fileBuffer.erase(fileBuffer.end() - boundaryLength, fileBuffer.end());
    if (buffer.size() == 4)
    {
        body += std::string(buffer.begin(), buffer.end());
        buffer.clear();
    }
    files[body] = fileBuffer;
    return (!buffer.empty() ? extractFormData(buffer, files, boundary) : void(0));
}

static ServerConfig &getServer(int port, WebServerConfig &config)
{
    for (size_t i = 0; i < config.servers.size(); ++i)
    {
        if (config.servers[i].port == port)
        {
            return config.servers[i];
        }
    }
    throw std::runtime_error("Server not found or header mismatch");
}

bool EpollServer::readFromConnection(int fd)
{
    size_t totalBytes = 0;
    std::vector<char> buffer;
    std::map<std::string, std::vector<char> > files;

    std::cout << "Reading from fd " << fd << std::endl;
    try
    {
        if (receiveData(fd, buffer, totalBytes) == false)
        {
            std::cerr << "Empty or incomplete read" << std::endl;
            return false;
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    //headers are always separated from the body by \r\n\r\n
    //so we can split the buffer at that point
    std::string header;
    while (header.find("\r\n\r\n") == std::string::npos && !buffer.empty())
    {
        header += buffer[0];
        buffer.erase(buffer.begin());
    }
    //look for host in header to find the port
    std::string _server = header.substr(header.find("Host: ") + 6, header.find("\r\n", header.find("Host: ")) - header.find("Host: ") - 6);
    int port = std::atoi(_server.substr(_server.find(":") + 1).c_str());
    std::cout << "Port: " << port << std::endl;
    
    ServerConfig server;
    try
    {
        server = getServer(port, this->config);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    

    //look through buffer for "Content-Type: multipart/form-data"
    if (header.find("Content-Type: multipart/form-data") != std::string::npos)
    {
        std::cout << "File upload detected" << std::endl;
        size_t boundaryStart = header.find("boundary=");
        if (boundaryStart == std::string::npos)
        {
            std::cerr << "No boundary found in header" << std::endl;
            return false;
        }
        std::string boundary = "\r\n--" + header.substr(boundaryStart + 9, header.find("\r\n", boundaryStart) - boundaryStart - 9);
        extractFormData(buffer, files, boundary);
    }
    else
    {
        //whole buffer can be turned into string
        std::string body(buffer.begin(), buffer.end());
        header += body;
    } 
    if (header.empty())
    {
        std::cerr << "Empty header" << std::endl;
        return false;
    }
    request_data input = request_data(header.c_str(), server, files);
    respond_builder output = respond_builder(&input);
    try
    {
        std::string httpResponse = output.build_respond_data();
        std::cout << httpResponse << std::endl;
        writeToConnection(fd, httpResponse.c_str(), httpResponse.length());
        if (header.find("Connection: keep-alive") == std::string::npos)
        {
            closeConnection(fd, clientfds);
            return true;
        }
        return true;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        closeConnection(fd, clientfds);
        return false;
    }
}

void EpollServer::writeToConnection(int fd, const char* buffer, size_t size)
{
    size_t sentBytes = 0;
    size_t totalBytes = 0;

    while (totalBytes < size)
    {
        sentBytes = send(fd, buffer + totalBytes, size - totalBytes, 0);
        if (sentBytes == static_cast<size_t>(-1))
        {
            perror("write");
            throw std::runtime_error("Error writing to connection");
        }
        totalBytes += sentBytes;
    }
    if (totalBytes != size)
    {
        throw std::runtime_error("Failed to send all bytes to connection");
    }
}
