# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ateow <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/16 18:37:40 by ateow             #+#    #+#              #
#    Updated: 2023/10/16 18:37:41 by ateow            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#SETUP
NAME = pipex

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

#FILES AND PATH
SRCS_DIR = srcs/
SRCS_SRCS = pipex.c pipex_utils.c free.c get_next_line_utils.c get_next_line.c
SOURCES = $(addprefix $(SRCS_DIR), $(SRCS_SRCS))
LIB = srcs/libft.a

#COMMANDS
all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) $(SOURCES) $(LIB) -o $(NAME)

clean:
	rm -rf $(NAME) 

fclean:	clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
