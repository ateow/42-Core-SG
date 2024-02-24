# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ateow <ateow@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/10 02:48:10 by kali              #+#    #+#              #
#    Updated: 2024/02/24 11:09:57 by ateow            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ex03

SOURCES = main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp DiamondTrap.cpp
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