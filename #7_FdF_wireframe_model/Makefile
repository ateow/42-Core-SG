# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ateow <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/16 18:37:40 by ateow             #+#    #+#              #
#    Updated: 2023/10/16 18:37:41 by ateow            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#SETUP
NAME = fdf

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

#FILES AND PATH
PROJECT_DIR = ./srcs/fdf/
PROJECT_SRCS = fdf.c fdf_utils.c controls.c free.c plot_line.c rotate.c rotate_math.c translate.c projection.c render.c
PROJECT = $(addprefix $(PROJECT_DIR), $(PROJECT_SRCS))

GNL_DIR = ./srcs/get_next_line/
GNL_SRCS = get_next_line_utils.c get_next_line.c
GNL = $(addprefix $(GNL_DIR), $(GNL_SRCS))

LIBFT_DIR = ./srcs/libft/
LIBFT = $(addprefix $(LIBFT_DIR), libft.a)

MINILIBX_DIR = ./srcs/minilibx-linux/
MINILIBX = $(addprefix $(MINILIBX_DIR), libmlx.a)

# MiniLibX Flags
MINILIBX_FLAGS = -L$(MINILIBX_DIR) -lmlx -lXext -lX11 -lm -lbsd

#COMMANDS
all: $(NAME)

$(NAME): libft minilibx
	@$(CC) $(CFLAGS) $(PROJECT) $(GNL) $(LIBFT) $(MINILIBX_FLAGS) -o $(NAME)

bonus:
	@$(CC) $(CFLAGS) $(PROJECT) $(GNL) $(LIBFT) $(MINILIBX_FLAGS) -o $(NAME)

#libft

libft:
	@$(MAKE) -C ./srcs/libft 

clean_libft:
	@$(MAKE) -C ./srcs/libft fclean   
	 
re_libft:
	@$(MAKE) -C ./srcs/libft re

#minilibx

minilibx:
	@$(MAKE) -C ./srcs/minilibx-linux
    
clean_minilibx:
	@$(MAKE) -C ./srcs/minilibx-linux clean

re_minilibx:
	@$(MAKE) -C ./srcs/minilibx-linux re
	
#Project Clean and RE

clean:
	@rm -rf $(NAME) 

fclean:	clean clean_libft clean_minilibx 
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
