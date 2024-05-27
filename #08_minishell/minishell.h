/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cooi <cooi@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 19:42:44 by cooi              #+#    #+#             */
/*   Updated: 2023/12/31 15:16:09 by cooi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft/libft.h"
# include <errno.h>
# include <fcntl.h>
# include <limits.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <signal.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/wait.h>
# include <unistd.h>
# include <dirent.h>

typedef struct s_node
{
	char			*str;
	struct s_node	*next;
}	t_node;

typedef struct s_inout {
	int		infd;
	int		heredoc;
	int		outfd;
	int		append;
}	t_inout;

typedef struct s_cmd {
	char	*cmdstr;
	int		infd;
	char	*infile;
	int		outfd;
	char	*outfile;
}	t_cmd;

typedef struct s_split {
	int	i;
	int	j;
	int	b;
	int	sq;
	int	dq;
}	t_split;

typedef struct s_wild {
	char	**ret;
	int		c;
}	t_wild;

typedef struct s_var
{
	char	*user_input;
	char	*clean_input;
	char	**env;
	int		exit_status;
	t_list	*history_list;
	t_inout	fds;
}	t_var;

// workflow
void	parsed_and_execute(char *input, t_var *vars);
void	execution_loop(char **input, t_var *vars);
void	expansion_execute(char *input, t_var *vars);
void	brackets_logic(char *input, t_var *vars);

// pipe
int		is_not_pipe_or_and(char **input, int i);
int		pipe_in_prev(char **input, int i);
int		pipe_in_next(char **input, int i);
void	set_pipe_conditions(char **input, int i, int *pipe_fd, t_inout *fds);
void	pipe_logic(char **input, int i, t_var *vars);

// redirection
void	redirection(char *input, t_var *vars);
void	execute_redirect(t_cmd	*cmds, t_var *vars);
int		check_meta(char *string, char x);
void	set_outfile(t_cmd **next, char **redir, int jdx, char *file);
void	set_infile(t_cmd **next, char **redir, int jdx, char *file);
int		set_in_and_out(t_cmd **next, char **redir, int jdx);
void	write_heredoc(t_cmd **next, char *file);

// parser_env_wild
char	**var_expand_wild_arr(char *string, t_var *vars);
char	**remove_empty_string(char **arr);
char	*get_env_value(char *key, char **env, int *exit_status);
char	*env_expansion(char *s, int *i, char **env, int *exit_status);
char	**getwildcard(char **pattern, char **env, int *exit_status);
char	**getpattern(char *input, int *wild);

// parser_utils
char	*inject_space(char *input);
t_split	check_quotes_and_brackets(t_split sp, char c);
t_split	extract_operator(t_split sp, char ***r, int *c, char *in);
t_split	add_space_after(t_split sp, char *in, char **ret);
t_split	add_space_before(t_split sp, char *in, char **ret);

// parser utils split
char	**split_and_or_pipe(char *input);
char	*split_quotes(char *input, int *idx);
char	*split_brackets(char *input, int *idx);
char	**split_redirection(char *input);
t_split	init_split(void);

// get_cmd_path
int		get_path_index(char **bin_paths, char *cmd);
char	**get_bin_path(char *binarycmd, char **envp);

// execute commands
void	execute_cmd(char **ret, t_var *vars);
void	execute_builtin(char **parsed_input, t_var *vars);
int		is_builtin(char **parsed_input);

// builtin functions
int		ft_exit(char **input, t_list *history_list, char ***env);
int		print_working_directory(void);
int		change_directory(char **input, char **env);
int		echo(char **input);
char	*var_expansion(char *input, char **env, int *exit_status);

// builtin env and utils functions
int		update_env(char	*var, char *new_string, char **env);
void	append_env(char *input, char ***env);
int		export_env(char *input, char ***env);
int		unset_env(char *input, char ***env);
int		print_env(char **env);
char	**init_env(char *envp[]);
void	get_var_string(char **var, char **string, char *input);
int		is_not_number(char *s);
int		change_directory_status(char **input, char **env);

// signals
void	signal_handler_ctrl_c(int signo);
void	setup_custom_signal_handlers(void);
void	block_custom_signal_handlers(void);
void	use_fork_signal_handlers(void);
void	use_default_signal_handlers(void);

// history
void	store_history(char *user_input, t_list **history_list);
int		print_history(t_list *lst);

// free
void	free_arr_lst_arr(char **arr1, t_list *lst, char **arr2);
void	free_str_lst_arr(char *str, t_list *lst, char **arr);
void	free_list(t_list *head);
void	free_t_cmd_list(t_cmd *head);

#endif
