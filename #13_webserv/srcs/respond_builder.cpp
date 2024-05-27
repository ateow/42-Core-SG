#include "libs.hpp"
#include "respond_builder.hpp"

int execute_cgi(const std::string& script_path, const std::string& post_data, std::string* output);

respond_builder::respond_builder(request_data *input)
{
    std::cout << "\n>>>>> Generating http respond <<<<<<" << std::endl;
    this->content_length = 0;
    this->request_info = input;
    this->connection = input->get_connection();
    if (input->get_status_line() == 400)
        this->build_400_respond();
    else if (input->get_status_line() == 404)
        this->build_404_respond();
    else if (input->get_status_line() == 405)
        this->build_405_respond();
    else if (input->get_status_line() == 413)
        this->build_413_respond();
    else if (input->get_status_line() == 414)
        this->build_414_respond();
    else if (!input->get_directory_listing().empty())
        this->build_directory_respond();
    else if (input->get_cgi_bin() == "yes")
    {
        std::string result; 
        // status based on CGI success or not
        int exec_status = execute_cgi(input->get_target(), input->get_body(), &result, 5); 
        if (exec_status == 404)
            this->build_404_respond();
        else if (exec_status == 500)
            this->build_500_respond();
        else
        {
            this->status = 200;
            this->status_line = "HTTP/1.1 200 OK";
            this->respond_body = result;
            this->content_length = this->respond_body.length();
            this->content_type = "text/html";
        }
    }
    else if (input->get_method() == "GET")
    {
        this->status = 200;
        this->status_line = "HTTP/1.1 200 OK";
        std::ifstream file((input->get_target()).c_str());
        std::ostringstream ss;
        ss << file.rdbuf();
        this->respond_body = ss.str();
        this->content_length = this->respond_body.length();
        this->content_type = "text/html";
    }
    else if (input->get_method() == "DELETE")
    {
        // Attempt to delete the file
        if (std::remove(input->get_target().c_str()) != 0)
        {
            this->build_400_respond();
        } 
        else
        {
            this->status = 200;
            this->status_line = "HTTP/1.1 200 OK";
        }
    }
    else if (input->get_method() == "POST" && input->get_content_type() == "multipart/form-data" && input->get_target() == "/upload" && input->config_para.route.upload_enable == "true")
    {
        std::map<std::string, std::vector<char> >::iterator iter;
        // check if file is too large
        long long int file_size = 0;
        for (iter = input->uploads.begin(); iter != input->uploads.end(); ++iter)
            file_size += iter->second.size();
        if (file_size > input->config_para.limit_client_body_size_bytes)
        {
            this->build_413_respond();
            return;
        }

        // start uploading
        for (iter = input->uploads.begin(); iter != input->uploads.end(); ++iter) 
        {
            // check if there is a file with filename
            size_t filenamePos = iter->first.find("filename=\"");
            filenamePos += 10; // Move past "filename=\""
            size_t filenameEndPos = iter->first.find("\"", filenamePos);
            std::string filename = iter->first.substr(filenamePos, filenameEndPos - filenamePos);
            if (filename.empty())
                continue;
            
            // check for existing file name and change filename accordingly
            DIR* dir = opendir(input->config_para.route.upload_path.c_str());
            int count = 0;
            struct dirent* entry;
            while ((entry = readdir(dir)) != NULL) 
            {
                if (strncmp(entry->d_name, filename.c_str(), filename.length()) == 0)
                    count++; // Found a file with the same name
            }
            closedir(dir);
            std::ostringstream ss;
            ss << count;
            if (count > 0)
                filename = filename + "(" + ss.str() + ")";
            
            // create file and store data in file
            std::ofstream file((input->config_para.route.upload_path + "/" + filename).c_str(), std::ios::binary);
            if (!file.is_open())
            {
                std::cerr << "Failed to open file" << std::endl;
                this->build_500_respond();
                return;
            }
            else
            {
                long unsigned int i = 0;
                while (i < iter->second.size())
                {
                    file << iter->second[i];
                    i++;
                }
                file.close();
            }
        }
        std::string body = "<html><head><title>42 Webserv Upload</title></head><body><h1>Upload Successful</h1><ul>";
        this->status = 200;
        this->status_line = "HTTP/1.1 200 OK";
        this->content_type = "text/html";
        this->content_length = body.length();
        this->respond_body = body;
    }
    else if (input->get_method() == "POST")
    {
        this->status_line = "HTTP/1.1 200 OK";
        this->content_type = "text/html";
    }
}




void respond_builder::build_directory_respond()
{
    std::string body;

    body = "<html><head><title>42 Webserv Directory Listing</title></head><body><h1>42 Webserv Directory Listing</h1><ul>";
   
    DIR* dir = opendir(this->request_info->get_directory_listing().c_str());
    if (dir != NULL) 
    { 
        struct dirent* entry;
        entry = readdir(dir);
        std::string dir_path = this->request_info->get_target();
        if (this->request_info->get_target()[this->request_info->get_target().length() - 1] == '/')
        {
            dir_path = this->request_info->get_target().substr(0, this->request_info->get_target().length() - 1);
        }
        size_t pos = dir_path.find_last_of('/');
        std::ostringstream ss;
        ss << this->request_info->get_port();
        std::string host_port = this->request_info->get_host() + ":" + ss.str() + "/"; 

        if (this->request_info->get_target() == "/")
            body += "<li><a href=\"http://" + host_port.substr(0, host_port.length() - 1) + "/\">../</a></li>";
        else
            body += "<li><a href=\"http://" + host_port.substr(0, host_port.length() - 1) + this->request_info->get_target().substr(0, pos) + "/\">../</a></li>";
        while (entry != NULL)
        {
            std::string filename = entry->d_name;
            if (filename != "." && filename != "..") 
            {
                if (this->request_info->is_directory(this->request_info->get_directory_listing() + filename) != 0)
                    body += "<li><a href=\"http://" + host_port + this->request_info->get_target().substr(1) + filename + "/\">" + filename + "/</a></li>";
                else
                    body += "<li><a href=\"http://" + host_port + this->request_info->get_target().substr(1) + filename + "\">" + filename + "</a></li>";
            }
            entry = readdir(dir);
        }
        closedir(dir);
    }
    else
        body += "<li>Error: Unable to open directory</li>";
    body += "</ul></body></html>";

    this->status = 200;
    this->status_line = "HTTP/1.1 200 OK";
    this->content_type = "text/html";
    this->content_length = body.length();
    this->respond_body = body;
}

void respond_builder::build_400_respond()
{
    std::ifstream file;
    std::ostringstream ss;

    this->status = 400;
    this->status_line = "HTTP/1.1 400 Bad Request";
    this->content_type = "text/html";
    file.open(this->request_info->config_para.default_error_pages[400].c_str());
	ss << file.rdbuf();
    this->respond_body = ss.str();
    this->content_length = this->respond_body.length();
}

void respond_builder::build_404_respond()
{
    std::ifstream file;
    std::ostringstream ss;

    this->status = 404;
    this->status_line = "HTTP/1.1 404 Not Found";
    this->content_type = "text/html";
    file.open(this->request_info->config_para.default_error_pages[404].c_str());
	ss << file.rdbuf();
    this->respond_body = ss.str();
    this->content_length = this->respond_body.length();
}

void respond_builder::build_405_respond()
{
    std::ifstream file;
    std::ostringstream ss;

    this->status = 404;
    this->status_line = "HTTP/1.1 405 Method Not Allowed";
    this->content_type = "text/html";
    file.open(this->request_info->config_para.default_error_pages[405].c_str());
	ss << file.rdbuf();
    this->respond_body = ss.str();
    this->content_length = this->respond_body.length();
}


void respond_builder::build_413_respond()
{
    std::ifstream file;
    std::ostringstream ss;

    this->status = 413;
    this->status_line = "HTTP/1.1 413 Content Too Large";
    this->content_type = "text/html";
    file.open(this->request_info->config_para.default_error_pages[413].c_str());
	ss << file.rdbuf();
    this->respond_body = ss.str();
    this->content_length = this->respond_body.length();
}

void respond_builder::build_414_respond()
{
    std::ifstream file;
    std::ostringstream ss;

    this->status = 414;
    this->status_line = "HTTP/1.1 414 URI Too Long";
    this->content_type = "text/html";
    file.open(this->request_info->config_para.default_error_pages[414].c_str());
	ss << file.rdbuf();
    this->respond_body = ss.str();
    this->content_length = this->respond_body.length();
}

void respond_builder::build_500_respond()
{
    std::ifstream file;
    std::ostringstream ss;

    this->status = 500;
    this->status_line = "HTTP/1.1 500 Internal Server Error";
    this->content_type = "text/html";
    file.open(this->request_info->config_para.default_error_pages[500].c_str());
	ss << file.rdbuf();
    this->respond_body = ss.str();
    this->content_length = this->respond_body.length();
}

std::string respond_builder::build_respond_data()
{
    std::string respond_txt;
    // get current time
    std::time_t currentTime = std::time(NULL);
    std::tm* localTime = std::gmtime(&currentTime); // Convert to GMT time
    // Format the date string
    char dateString[128];
    std::strftime(dateString, sizeof(dateString), "%a, %d %b %Y %H:%M:%S GMT", localTime);

    std::stringstream ss;
    ss << this->content_length;
    respond_txt = this->status_line + "\r\n"
                    + "Server: " + this->request_info->config_para.s_name + "\r\n"
                    + "Date: " + dateString + "\r\n"
                    + "Content-Type: " + this->content_type + "\r\n"
                    + "Content-Length: " + ss.str() + "\r\n"
                    + "Connection: " + this->connection + "\r\n\r\n"
                    + this->respond_body + "\r\n";
    this->respond_data = respond_txt;
    return(this->respond_data);
}
