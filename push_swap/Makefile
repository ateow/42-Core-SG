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
BONUS = checker

SOURCES = push_swap.c push_swap_utils.c check_error.c \
	action_push.c action_revrot.c action_rot.c action_swap.c \
	sort_big.c sort_small.c

B_SOURCES = bonus_checker.c bonus_action_push.c bonus_action_revrot.c bonus_action_rot.c bonus_action_swap.c \
	check_error.c get_next_line.c get_next_line_utils.c

LIB = libft.a libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME) $(BONUS)

$(NAME):
	$(CC) $(CFLAGS) $(SOURCES) $(LIB) -o $(NAME)

$(BONUS):
	$(CC) $(CFLAGS) $(B_SOURCES) $(LIB) -o $(BONUS)

clean:
	rm -rf $(NAME) $(BONUS)

fclean:	clean
	rm -rf $(NAME) $(BONUS)

re: fclean all

.PHONY: all clean fclean re
