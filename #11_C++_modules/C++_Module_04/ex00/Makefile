# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kali <kali@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/10 02:48:10 by kali              #+#    #+#              #
#    Updated: 2024/02/18 23:43:37 by kali             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ex00

SOURCES = main.cpp Animal.cpp Dog.cpp Cat.cpp WrongAnimal.cpp WrongCat.cpp
OBJECTS = $(SOURCES:.cpp=.o)

CC = g++
CFLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME):$(OBJECTS)
	$(CC) $(CFLAGS) $(SOURCES) -o $(NAME)

clean:
	rm -rf $(NAME)

fclean:	clean
	rm -rf $(NAME) $(OBJECTS)

re: fclean all

.PHONY: all clean fclean re