# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kali <kali@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/02 21:21:08 by kali              #+#    #+#              #
#    Updated: 2024/02/03 11:17:46 by kali             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = phonebook

SOURCES = main.cpp

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++11

all: $(NAME)	

$(NAME):
	$(CC) $(CFLAGS) $(SOURCES) -o $(NAME)

clean:
	rm -rf $(NAME)

fclean:	clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re