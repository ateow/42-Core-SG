#pragma once
# include "libs.hpp"
#include "EpollServer.hpp"

struct FormData
{
    std::string filename;
    std::string content;
};

class request_data
{
    private:
        std::string request_text;
        std::string method;
        std::string target;
        std::string http_version;
        std::string host;
        int port;
        std::string user_agent;
        std::string accept;
        std::string accept_language;
        std::string accept_encoding;
        std::string connection;
        int content_length;
        std::string content_type;
        std::string body;
        int status_line;
        std::string cgi_bin;
        std::string boundary;
        std::string directory_listing;
        
    public:
        //construct
        //request_data();
        request_data(std::string type, ServerConfig &server, std::map<std::string, std::vector<char> > files);
        int parse_method();
        int parse_target();
        int parse_version();
        int parse_headers();
        int is_directory(std::string path);
        class ServerConfig config_para;
        std::map<std::string, std::vector<char> > uploads;
        std::vector<FormData> forms;
        std::string get_method();
        std::string get_target();
        std::string get_http_version();
        std::string get_host();
        int get_port();
        std::string get_user_agent();
        std::string get_accept();
        std::string get_accept_language();
        std::string get_accept_encoding();
        std::string get_connection();
        int get_status_line();
        int get_content_length();
        std::string get_content_type();
        std::string get_body();
        std::string get_cgi_bin();
        std::string get_directory_listing();
};
