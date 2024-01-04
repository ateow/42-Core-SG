/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ateow <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 19:26:30 by ateow             #+#    #+#             */
/*   Updated: 2023/12/29 19:26:33 by ateow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_not_pipe_or_and(char **input, int i)
{
	if (input[i][0] != '|' && ft_strncmp(input[i], "||", 2) != 0
		&& ft_strncmp(input[i], "&&", 2) != 0)
		return (1);
	else
		return (0);
}

int	pipe_in_prev(char **input, int i)
{
	if (i != 0 && ft_strlen(input[i - 1]) == 1
		&& ft_strncmp(input[i - 1], "|", 1) == 0)
		return (1);
	else
		return (0);
}

int	pipe_in_next(char **input, int i)
{
	if (input[i + 1] != NULL && ft_strlen(input[i + 1]) == 1
		&& ft_strncmp(input[i + 1], "|", 1) == 0)
		return (1);
	else
		return (0);
}

void	set_pipe_conditions(char **input, int i, int *pipe_fd, t_inout *fds)
{
	if (pipe_in_next(input, i) == 1)
	{
		dup2(pipe_fd[1], 1);
		close(pipe_fd[1]);
	}
	if (pipe_in_prev(input, i) == 1)
	{
		close(pipe_fd[0]);
		dup2(fds->infd, 0);
	}
}

void	pipe_logic(char **input, int i, t_var *vars)
{
	int			child_pid;
	int			pipe_fd[2];

	pipe(pipe_fd);
	child_pid = fork();
	if (child_pid == 0)
	{
		set_pipe_conditions(input, i, pipe_fd, &(vars->fds));
		if (check_meta(input[i], '<') == 1
			|| check_meta(input[i], '>') == 1)
			redirection(input[i], vars);
		else if (input[i][0] == '(')
			brackets_logic(input[i], vars);
		else
			expansion_execute(input[i], vars);
		free_arr_lst_arr(input, vars->history_list, vars->env);
		exit(vars->exit_status);
	}
	else
	{
		close(pipe_fd[1]);
		vars->fds.infd = pipe_fd[0];
		waitpid(child_pid, &(vars->exit_status), 0);
		vars->exit_status = WEXITSTATUS(vars->exit_status);
	}
}
