NAME = minishell
BONUS = minishell_bonus

LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/libft.a

SRCS = main.c builtin.c builtin_env.c builtin_env_utils.c execute_cmd.c signal.c history.c workflow.c pipe_utils.c parser_env_wild.c parser_utils.c parser_utils_split.c get_cmd_path.c redirect.c redirect_utils.c free.c parser_env_wild_wildcard.c parser_env_wild_environment.c

OBJS = $(SRCS:.c=.o)

CC = gcc
FLAGS = -Wall -Wextra -Werror
LFLAGS = -lreadline -lncurses
RM = rm -rf

all: $(NAME) $(BONUS)

$(NAME): $(OBJS) $(LIBFT)
	@$(CC) $(FLAGS) -I. -o $(NAME) $(OBJS) $(LIBFT) $(LFLAGS)

$(BONUS): $(OBJS) $(LIBFT)
	@$(CC) $(FLAGS) -I. -o $(BONUS) $(OBJS) $(LIBFT) $(LFLAGS)

$(OBJS): $(SRCS)
	@$(CC) $(FLAGS) -I. -c $(SRCS) $(LFLAGS)

$(LIBFT):
	@make -C $(LIBFT_PATH) all

clean:
	@make -C $(LIBFT_PATH) clean
	@$(RM) $(OBJS)

fclean: clean
	@make -C $(LIBFT_PATH) fclean
	@$(RM) $(NAME) $(BONUS)

re: fclean all

.PHONY: all clean fclean re
