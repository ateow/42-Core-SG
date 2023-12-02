# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ateow <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/02 16:29:33 by ateow             #+#    #+#              #
#    Updated: 2023/12/02 16:29:34 by ateow            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

#FILES AND PATH
SOURCES = philo.c philo_utils.c init.c

#COMMANDS
all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) $(SOURCES) -o $(NAME)

clean:
	rm -rf $(NAME) 

fclean:	clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re

