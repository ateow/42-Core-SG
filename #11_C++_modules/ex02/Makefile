# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kali <kali@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/04 11:27:16 by kali              #+#    #+#              #
#    Updated: 2024/02/04 11:29:24 by kali             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = account

SOURCES = tests.cpp Account.cpp

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)	

$(NAME):
	$(CC) $(CFLAGS) $(SOURCES) -o $(NAME)

clean:
	rm -rf $(NAME)

fclean:	clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re