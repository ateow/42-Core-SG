#include "EpollServer.hpp"
#include "request_parser.hpp"

request_data::request_data(std::string input, ServerConfig &server, std::map<std::string, std::vector<char> > files) : request_text(input)
{
    std::cout << "\n>>>>> Parsing HTTP request <<<<<" << std::endl;
    if (server.port == -1)
        this->status_line = 400;
    else
    {
        std::cout << input << std::endl;
        this->config_para = server;
        this->status_line = 200;
        this->content_length = 0;
        this->uploads = files;
        this->cgi_bin = "no";
        this->parse_method();
        this->parse_target();
        this->parse_version();
        this->parse_headers();
    }
}

int request_data::parse_method()
{
    size_t first_space_pos = request_text.find(' ');
    if (first_space_pos <= std::string::npos)
    {
        std::string tmp = request_text.substr(0,first_space_pos);
        for (size_t i = 0, size = this->config_para.route.accepted_methods.size(); i < size; ++i) 
        {
            if (tmp == this->config_para.route.accepted_methods[i])
            {
                this->method = tmp;
                return(0);
            }
        }
        int i = 0;
        while (tmp[i] != '\0')
        {
            if (std::isupper(tmp[i]) == 0) 
            {
                this->status_line = 400;
                this->method = "Invalid";
                return (1);
            }
            i++;
        }
        this->status_line = 405;
        this->method = "Invalid";
    }
    return (1);
}

int request_data::parse_target()
{
    std::string host_directory = this->config_para.route.root_directory;
    if (host_directory[host_directory.length() - 1] != '/')
        host_directory = host_directory + "/";
    std::string cgi_directory = this->config_para.route.cgi_path;
    size_t first_space_pos = request_text.find(' ');
    if (first_space_pos != std::string::npos) 
    {
        size_t second_space_pos = request_text.find(' ', first_space_pos + 1);
        if (second_space_pos != std::string::npos) 
        {

            std::string line = request_text.substr(first_space_pos + 1, second_space_pos - first_space_pos - 1);

            // ERROR Check:

            // (1) check for long URI
            if (line.length() >= 2000)
            {
                if (this->status_line == 200)
                    this->status_line = 414;
                this->target = "URI Too long";
            }
            
            // (2) check for URI injection and access
            int depth = 0;
            size_t pos = 0;
            while ((pos = line.find("../", pos)) != std::string::npos) 
            {
                if (pos == 0 || line[pos - 1] == '/')
                    depth--;
                pos += 3;
            }
            pos = 0;
            while ((pos = line.find("/", pos)) != std::string::npos) 
            {
                if (pos > 0 && line[pos - 1] != '/' && line[pos - 1] != '.')
                    depth++; // Increment depth for each occurrence of "/"
                pos++; 
            }
            if (depth < 0)
                this->target = "/";
            
            // (3) check if target resource is present. check CGI first then the rest
            if (this->config_para.route.cgi_enable == "true" && line.substr(0, 9) == "/cgi-bin/" && line.length() > 9)
            {
                // check if cgi exist
                // check if cgi workable
                // update target if no issue for respond to build
                std::ifstream file;
                if (line.find('?') == std::string::npos)
                    file.open((cgi_directory + line.substr(8)).c_str());
                else 
                {
                    file.open((cgi_directory + line.substr(8, line.find('?') - 8)).c_str());
                    this->body = line.substr(line.find('?') + 1);
                }   
                if (file.fail() && this->status_line == 200)
                    this->status_line = 404;
                this->target = cgi_directory + line.substr(8);
                if (line.find('?') != std::string::npos)
                    this->target = cgi_directory + line.substr(8, line.find('?') - 8);
                this->cgi_bin = "yes";          
            }
            else if (this->config_para.route.upload_enable == "true" && line.substr(0, 7) == "/upload" && line.length() == 7)
            {
                this->target = "/upload";
            }
            else
            {
                // check if should redirect
                std::vector<std::string>::iterator iter;
                for (iter = this->config_para.route.old_paths.begin(); iter != this->config_para.route.old_paths.end(); ++iter) 
                {
                    if (line == *iter)
                        line = this->config_para.route.redirect;
                }
                
                // (1) check if file exists. if file exist, build and return
                std::string full_path = host_directory + line;
                struct stat st;

                if (stat(full_path.c_str(), &st) == 0 && S_ISREG(st.st_mode)) 
                {
                    // The path corresponds to a regular file
                    std::ifstream file(full_path.c_str());
                    if (file.is_open()) // open file successfully
                        this->target = full_path; 
                    else // Failed to open file
                        this->status_line = 400;
                }
                // (2) if file dont exist, check if its a directory
                else if (this->is_directory(host_directory + line) != 0)
                {
                    if (line[line.length() - 1] != '/')
                        line = line + '/';
                    // (2.1) valid directory. if there is a default file, check if valid
                    if (!this->config_para.route.default_file.empty())
                    {
                        std::string linewdefaultfile = line + this->config_para.route.default_file;

                        std::ifstream file2((host_directory + linewdefaultfile).c_str());
                        // if default file is valid
                        if (!file2.fail())
                        {
                            this->target = host_directory + linewdefaultfile;
                            return (0);
                        }
                    }   
                    // (2.2) valid directory. no valid default file, check dir listing 
                    if (this->config_para.route.list_directory == "on")
                    {
                        this->directory_listing = host_directory + line.substr(1);
                        this->target = line;
                        if (line.empty() && this->status_line == 200)
                            this->status_line = 404;

                        return (0);
                    }
                } 
                // if all fails, update error
                else if (this->status_line == 200)
                    this->status_line = 404;
            }
        }
    }
    return (0);
}

int request_data::is_directory(std::string path)
{
    struct stat st;
    if (stat(path.c_str(), &st) != 0) 
        return 0;  // Path does not exist
    return S_ISDIR(st.st_mode);
}

int request_data::parse_version()
{
    size_t first_space_pos = request_text.find(' ');
    if (first_space_pos != std::string::npos) 
    {
        size_t second_space_pos = request_text.find(' ', first_space_pos + 1);
        if (second_space_pos != std::string::npos) 
        {
            size_t third_space_pos = request_text.find("\r\n");
            if (third_space_pos != std::string::npos) 
            {
                this->http_version = request_text.substr(second_space_pos + 1, third_space_pos - second_space_pos - 1);
            }
        }
    }
    return (0);
}

int request_data::parse_headers()
{
    std::string requesttxt = request_text;
    while (requesttxt != "\0")
    {
        requesttxt = requesttxt.substr(requesttxt.find("\r\n") + 2);
        std::string line = requesttxt.substr(0, requesttxt.find("\r\n"));
        // Body and exit after body
        if (line.length() == 0)
        {   
            line = requesttxt.substr(2);
            this->body += line;
            break;
        }
        // Host and Port
        if (line.substr(0, line.find(' ')) == "Host:")
        {
            std::string host = line.substr(line.find(' ') + 1);
            if (host.find(':') == std::string::npos)
            {
                this->host = host;
                this->port = 80;
                this->status_line = 400;
            }
            else
            {
                this->host = host.substr(0, host.find(':'));
                this->port = atoi(host.substr(host.find(':') + 1).c_str());
            }
        }
        // User-Agent
        else if (line.substr(0, line.find(' ')) == "User-Agent:")
        {
            this->user_agent = line.substr(line.find(' ') + 1);
        }
        // Accept
        else if (line.substr(0, line.find(' ')) == "Accept:")
        {
            this->accept = line.substr(line.find(' ') + 1);
        }
        // Accept-Language
        else if (line.substr(0, line.find(' ')) == "Accept-Language:")
        {
            this->accept_language = line.substr(line.find(' ') + 1);
        }
        // Accept-Encoding
        else if (line.substr(0, line.find(' ')) == "Accept-Encoding:")
        {
            this->accept_encoding = line.substr(line.find(' ') + 1);
        }
        // Connection
        else if (line.substr(0, line.find(' ')) == "Connection:")
        {
            this->connection = line.substr(line.find(' ') + 1);
        }
        // Content-Length
        else if (line.substr(0, line.find(' ')) == "Content-Length:")
        {
            this->content_length = atoi(line.substr(line.find(' ') + 1).c_str());
        }
        // Content-type
        else if (line.substr(0, line.find(' ')) == "Content-Type:")
        {
            this->content_type = line.substr(line.find(' ') + 1);
            if (this->content_type.substr(0, 19) == "multipart/form-data")
            {
                this->boundary = line.substr(line.find("boundary=") + 9);
                this->content_type = this->content_type.substr(0, this->content_type.find(";"));
            }
        }
    }
    long unsigned para_size = this->config_para.limit_client_body_size_bytes;
    if (this->body.size() * sizeof(char) > para_size && this->status_line == 200)
        this->status_line = 413;
    return (0);
}

std::string request_data::get_method()
{
    return(this->method);
}

std::string request_data::get_target()
{
    return(this->target);
}

std::string request_data::get_http_version()
{
    return(this->http_version);
}

std::string request_data::get_host()
{
    return(this->host);
}

int request_data::get_port()
{
    return(this->port);
}

std::string request_data::get_user_agent()
{
    return(this->user_agent);
}

std::string request_data::get_accept()
{
    return(this->accept);
}

std::string request_data::get_accept_language()
{
    return(this->accept_language);
}

std::string request_data::get_accept_encoding()
{
    return(this->accept_encoding);
}

std::string request_data::get_connection()
{
    return(this->connection);
}

int request_data::get_content_length()
{
    return(this->content_length);
}

std::string request_data::get_content_type()
{
    return(this->content_type);
}
std::string request_data::get_body()
{
    return(this->body);
}

int request_data::get_status_line()
{
    return(this->status_line);
}

std::string request_data::get_cgi_bin()
{
    return(this->cgi_bin);
}

std::string request_data::get_directory_listing()
{
    return(this->directory_listing);
}