# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ateow <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/30 17:05:46 by ateow             #+#    #+#              #
#    Updated: 2023/09/30 17:05:47 by ateow            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SOURCES = push_swap.c push_swap_utils.c check_error.c push_ops.c revrot_ops.c rot_ops.c swap_ops.c

LIB = libft.a libftprintf.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) $(SOURCES) -L ./ $(LIB) -o $(NAME)

clean:
	rm -rf $(NAME)

fclean:	clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
