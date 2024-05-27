NAME = webserv
COMPILER = c++
CFLAGS = -Wall -Wextra -Werror -g -std=c++98
INCLUDES = -Iincludes

SRCS_DIR = srcs/
BUILD_DIR = build/
SRCS := $(SRCS_DIR)EpollServer.cpp\
$(SRCS_DIR)exec_cgi.cpp\
$(SRCS_DIR)load_config.cpp\
$(SRCS_DIR)main.cpp\
$(SRCS_DIR)request_parser.cpp\
$(SRCS_DIR)respond_builder.cpp\
$(SRCS_DIR)verify_cgi.cpp

OBJS := $(SRCS:$(SRCS_DIR)%.cpp=$(BUILD_DIR)%.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(COMPILER) $(CFLAGS) $(INCLUDES) -o $(NAME) $(OBJS)

$(BUILD_DIR)%.o: $(SRCS_DIR)%.cpp
	 mkdir -p $(BUILD_DIR)
	$(COMPILER) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS) $(NAME)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
