#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <cstdlib> // For atoi
#include "libs.hpp"
#define ERROR400 "./errors/400.html"
#define ERROR404 "./errors/404.html"
#define ERROR405 "./errors/405.html"
#define ERROR413 "./errors/413.html"
#define ERROR414 "./errors/414.html"
#define ERROR500 "./errors/500.html"

void trim(std::string& s);

class RouteConfig {
public:
    std::string root_directory;
    std::string default_file;
    std::string list_directory;
    std::vector<std::string> accepted_methods;
    std::vector<std::string> old_paths;
    std::string redirect;
    std::string cgi_enable;
    std::string cgi_path;
    std::string upload_enable;
    std::string upload_path;
};

class ServerConfig {
public:
    std::string host;
    int port;
    std::string s_name;
    std::vector<std::string> server_names;
    std::map<int, std::string> default_error_pages;
    std::string limit_client_body_size;
    long long int limit_client_body_size_bytes;
    RouteConfig route; 
	ServerConfig();
};

class WebServerConfig {
public:
    std::vector<ServerConfig> servers;
    // std::string chunk_handling;
    void parseConfig(const std::string& filename);
};
int execute_cgi(const std::string& script_path, const std::string& post_data, std::string* output, int timeout_sec);
int checkConfig(WebServerConfig& config);
int is_directory(std::string path);