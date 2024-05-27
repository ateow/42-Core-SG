#pragma once
#ifndef _EPOLLSERVER_HPP_
# define _EPOLLSERVER_HPP_

# define MAX_EVENTS 10
# define MAX_CONNECTIONS 10
# define TIMEOUT_SECS 10
# define EPOLL_TIMEOUT 1000 //in milliseconds
# include "libs.hpp"
# include "load_config.hpp"
# include "request_parser.hpp"
# include "respond_builder.hpp"

class WebServerConfig;
class ServerConfig;

struct incompleteRequest
{
    int fd;
    std::vector<char> buffer;
};

class EpollServer
{
    public:
        EpollServer(WebServerConfig serverconfig);
        ~EpollServer();
        void runServer();

        int signalHandler(int signum);
        
    private:
        int epollfd;
        int shutdownfd;
        size_t requestsizelimit;
        std::map<std::time_t, incompleteRequest> incompleterequests;
        std::deque<int> clientfds;
        std::vector<int> socketfds;
        std::vector<int> ports;

        WebServerConfig config;

        //methods
        void checkRequests();
        void initServer();
        void addSocket(const ServerConfig &server);
        bool receiveData(int fd, std::vector<char> &buffer, size_t &totalBytes);
        bool readFromConnection(int fd);
        void writeToConnection(int fd, const char* buffer, size_t size);
};

#endif
