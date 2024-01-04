/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ateow <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 17:06:28 by ateow             #+#    #+#             */
/*   Updated: 2023/12/28 17:06:29 by ateow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_builtin(char **input)
{
	if (ft_strncmp(input[0], "cd", 3) == 0
		|| ft_strncmp(input[0], "pwd", 3) == 0
		|| ft_strncmp(input[0], "history", 8) == 0
		|| ft_strncmp(input[0], "env", 4) == 0
		|| ft_strncmp(input[0], "export", 7) == 0
		|| ft_strncmp(input[0], "unset", 6) == 0
		|| ft_strncmp(input[0], "echo", 5) == 0
		|| ft_strncmp(input[0], "exit", 5) == 0)
		return (1);
	return (0);
}

void	execute_builtin(char **input, t_var *vars)
{
	if (ft_strncmp(input[0], "cd", ft_strlen(input[0])) == 0)
		vars->exit_status = change_directory(input, vars->env);
	else if (ft_strncmp(input[0], "pwd", ft_strlen(input[0])) == 0)
		vars->exit_status = print_working_directory();
	else if (ft_strncmp(input[0], "history", ft_strlen(input[0])) == 0)
		vars->exit_status = print_history(vars->history_list);
	else if (ft_strncmp(input[0], "env", ft_strlen(input[0])) == 0)
		vars->exit_status = print_env(vars->env);
	else if (ft_strncmp(input[0], "export", ft_strlen(input[0])) == 0)
		vars->exit_status = export_env(input[1], &(vars->env));
	else if (ft_strncmp(input[0], "unset", ft_strlen(input[0])) == 0)
		vars->exit_status = unset_env(input[1], &(vars->env));
	else if (ft_strncmp(input[0], "echo", ft_strlen(input[0])) == 0)
		vars->exit_status = echo(input);
	else if (ft_strncmp(input[0], "exit", ft_strlen(input[0])) == 0)
		vars->exit_status = ft_exit(input, vars->history_list, &(vars->env));
}

void	in_child(char **ret, t_var *vars)
{
	char	**bin_paths;
	int		bin_path_index;

	use_default_signal_handlers();
	bin_paths = get_bin_path(ret[0], vars->env);
	bin_path_index = get_path_index(bin_paths, ret[0]);
	if (execve(bin_paths[bin_path_index], ret, vars->env) == -1)
		perror(ret[0]);
	free_array(bin_paths);
	exit (EXIT_FAILURE);
}

void	execute_cmd(char **ret, t_var *vars)
{
	int		child_pid;

	if (is_builtin(ret) == 1)
		execute_builtin(ret, vars);
	else
	{
		child_pid = fork();
		if (child_pid == 0)
		{
			in_child(ret, vars);
		}
		else
		{
			block_custom_signal_handlers();
			waitpid(child_pid, &(vars->exit_status), 0);
			vars->exit_status = WEXITSTATUS(vars->exit_status);
		}
	}
}
