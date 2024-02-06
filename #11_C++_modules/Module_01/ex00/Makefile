# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ateow <ateow@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/06 19:11:39 by ateow             #+#    #+#              #
#    Updated: 2024/02/06 21:54:26 by ateow            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = BraiiiiiiinnnzzzZ

SOURCES = main.cpp Zombie.cpp newZombie.cpp randomChump.cpp

CC = g++
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