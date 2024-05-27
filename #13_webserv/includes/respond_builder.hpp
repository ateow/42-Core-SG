#pragma once
# include "libs.hpp"
#include "request_parser.hpp"
#include "EpollServer.hpp"

class respond_builder
{
    private:
        class request_data *request_info;
        std::string respond_data;
        std::string status_line;
        std::string respond_body;
        int status;
        std::string date;
        std::string content_type;
        int content_length;
        std::string connection;

    public:
        respond_builder(request_data *input);
        void build_400_respond();
        void build_404_respond();
        void build_405_respond();
        void build_413_respond();
        void build_414_respond();
        void build_500_respond();
        void build_directory_respond();
        std::string build_respond_data();
};
