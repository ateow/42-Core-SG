/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   workflow.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cooi <cooi@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 19:40:07 by cooi              #+#    #+#             */
/*   Updated: 2023/12/26 22:17:41 by cooi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	skip_to_next_andor(char **input, int *exit_status, int *i)
{
	if ((ft_strncmp(input[*i], "||", 2) == 0 && *exit_status == 0)
		|| (ft_strncmp(input[*i], "&&", 2) == 0 && *exit_status != 0))
	{
		while (input[*i + 1] != NULL && ft_strncmp(input[*i + 1], "||", 2)
			&& ft_strncmp(input[*i + 1], "&&", 2))
			*i = *i + 1;
		return (1);
	}
	return (0);
}

void	brackets_logic(char *input, t_var *vars)
{
	int	child_pid;

	child_pid = fork();
	if (child_pid == 0)
	{
		input[ft_strlen(input) - 1] = '\0';
		parsed_and_execute(input + 1, vars);
		free_str_lst_arr(input, vars->history_list, vars->env);
		exit(vars->exit_status);
	}
	else
	{
		waitpid(child_pid, &(vars->exit_status), 0);
		vars->exit_status = WEXITSTATUS(vars->exit_status);
	}
}

void	parsed_and_execute(char *input, t_var *vars)
{
	int		i;
	char	**r;

	i = -1;
	r = remove_empty_string(split_and_or_pipe(input));
	while (r[++i])
	{
		if (ft_strchr("<>&|;", r[i][0]))
		{
			if (r[i + 1] == NULL || r[i + 1][0] == '&' || r[i + 1][0] == '|')
			{
				write(2, "syntax error near unexpected token '", 36);
				ft_putchar_fd(r[i][0], 2);
				write(2, "'\n", 2);
			}
			if ((r[i + 1] == NULL)
				|| (r[i + 1][0] == '&' || r[i + 1][0] == '|'))
			{
				vars->exit_status = 2;
				free_array(r);
				return ;
			}
		}
	}
	execution_loop(r, vars);
}

void	execution_loop(char **input, t_var *vars)
{
	int			i;

	i = 0;
	while (input[i] != NULL)
	{
		if (skip_to_next_andor(input, &(vars->exit_status), &i) == 1)
			;
		else if (is_not_pipe_or_and(input, i) == 1)
		{
			if (pipe_in_prev(input, i) == 1 || pipe_in_next(input, i) == 1)
				pipe_logic(input, i, vars);
			else if (check_meta(input[i], '<') == 1
				|| check_meta(input[i], '>') == 1)
				redirection(input[i], vars);
			else if (input[i][0] == '(')
				brackets_logic(input[i], vars);
			else
				expansion_execute(input[i], vars);
		}
		i++;
	}
	free_array(input);
}

void	expansion_execute(char *input, t_var *vars)
{
	char	**cmd_args_arr;

	cmd_args_arr = var_expand_wild_arr(input, vars);
	execute_cmd(cmd_args_arr, vars);
	free_array(cmd_args_arr);
}
