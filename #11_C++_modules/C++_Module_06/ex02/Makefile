# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ateow <ateow@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/10 02:48:10 by kali              #+#    #+#              #
#    Updated: 2024/06/08 15:07:56 by ateow            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ex02

SOURCES = main.cpp
OBJECTS = $(SOURCES:.cpp=.o)

CC = c++
CFLAGS = -Wall -Wextra -Werror -Wshadow -std=c++98 -g

all: $(NAME)

$(NAME):$(OBJECTS)
	$(CC) $(CFLAGS) $(SOURCES) -o $(NAME)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@
	
clean:
	rm -rf $(OBJECTS)

fclean:	clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re