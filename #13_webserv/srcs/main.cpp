#include "libs.hpp"
#include "EpollServer.hpp"

// Global pointer, compatible with C++98
EpollServer* server = NULL;  // Use NULL instead of nullptr

// Signal handler - This is mostly C++98 compliant
void signalHandler(int signum) {
    std::cout << std::endl << "Signal " << signum << " received, shutting down the server..." << std::endl;
    if (server != NULL) {
        delete server;
        server = NULL;
    }
}

int main(int argc, char **argv)
{
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <config-file>" << std::endl;
        return 1;
    }

    try
    {
        WebServerConfig config;
        config.parseConfig(argv[1]);  // Parse the config file specified by the command line
        if (!checkConfig(config)) {
            std::cerr << "Configuration is incomplete\n";
            return 2;
        }

        std::cout << "Starting " << config.servers.size() << " servers" << std::endl << std::endl;
        
        std::signal(SIGINT, signalHandler);  // Register signal handler for SIGINT
        std::signal(SIGTERM, signalHandler);  // Register signal handler for SIGTERM

        server = new EpollServer(config);
        server->runServer();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
        if (server != NULL) {
            delete server;
            server = NULL;
        }
        return 3;
    }
    if (server != NULL) {
        delete server;
        server = NULL;
    }
	return 0;
}
