# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ateow <ateow@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/02 16:29:33 by ateow             #+#    #+#              #
#    Updated: 2024/01/03 21:39:31 by ateow            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo_bonus

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

#FILES AND PATH
SOURCES = philo_bonus.c philo_utils_bonus.c init_bonus.c

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

