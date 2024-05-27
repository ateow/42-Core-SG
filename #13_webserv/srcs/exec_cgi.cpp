#include "libs.hpp"

int execute_cgi(const std::string& script_path, const std::string& post_data, std::string* output, int timeout_sec = 10) {
    int input_fds[2];
    int output_fds[2];
    pipe(input_fds);  // Create a pipe for input communication
    pipe(output_fds); // Create a pipe for output redirection

    pid_t pid = fork();

    if (pid == 0) { // Child process
        std::vector<std::string> envp_str;
        std::stringstream ss;

        ss << "CONTENT_LENGTH=" << post_data.length();
        envp_str.push_back(ss.str());
        envp_str.push_back("CONTENT_TYPE=application/x-www-form-urlencoded");

        std::vector<char*> envp;
        for (size_t i = 0; i < envp_str.size(); ++i) {
            envp.push_back(const_cast<char*>(envp_str[i].c_str()));
        }
        envp.push_back(NULL);

        std::vector<char*> argv;
        argv.push_back(const_cast<char*>(script_path.c_str()));
        argv.push_back(NULL);

        dup2(input_fds[0], STDIN_FILENO);
        close(input_fds[1]);
        dup2(output_fds[1], STDOUT_FILENO);
        close(output_fds[0]);
        dup2(output_fds[1], STDERR_FILENO); // Redirect STDERR to the output pipe

        execve(script_path.c_str(), &argv[0], &envp[0]);

        std::cerr << "Failed to execute CGI script\n";
        exit(1);
    } else if (pid > 0) { // Parent process
        close(input_fds[0]);
        close(output_fds[1]);

        write(input_fds[1], post_data.c_str(), post_data.size());
        close(input_fds[1]); // Close to send EOF

        fd_set readfds;
        struct timeval timeout;

        FD_ZERO(&readfds);
        FD_SET(output_fds[0], &readfds);

        timeout.tv_sec = timeout_sec;
        timeout.tv_usec = 0;

        int retval = select(output_fds[0] + 1, &readfds, NULL, NULL, &timeout);
        if (retval == -1) {
            std::cerr << "select() failed\n";
            return 500;
        } else if (retval == 0) {
            std::cerr << "CGI script timed out\n";
            kill(pid, SIGKILL);
            waitpid(pid, NULL, 0); // clean up child process
            return 500;
        } else {
            const int buffer_size = 4096;
            char buffer[buffer_size];
            ssize_t nbytes = read(output_fds[0], buffer, buffer_size);
            close(output_fds[0]);

            if (output != NULL && nbytes > 0) {
                output->assign(buffer, nbytes);
            }

            int status;
            waitpid(pid, &status, 0);

            if (WIFEXITED(status) && WEXITSTATUS(status) == 0) {
                std::cout << "CGI script executed successfully.\n";
                return 1;
            } else {
                std::cout << "CGI script failed to execute.\n";
                return 404;
            }
        }
    }
    return 500; // In case of fork failure
}
