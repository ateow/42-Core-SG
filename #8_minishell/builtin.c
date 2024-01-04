/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ateow <ateow@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 23:03:58 by ateow             #+#    #+#             */
/*   Updated: 2023/12/27 23:04:00 by ateow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_exit(char **input, t_list *history_list, char ***env)
{
	write(1, "exit\n", 5);
	if (input[1] == NULL)
	{
		free_list(history_list);
		free_array(*env);
		exit(0);
	}
	else if (atoi(input[1]) == 0 || is_not_number(input[1]) == 1)
	{
		write(2, "exit: numeric argument required\n", 32);
		free_list(history_list);
		free_array(*env);
		exit(2);
	}
	else if (input[1] != NULL && input[2] != NULL)
	{
		write(2, "exit: too many arguments\n", 25);
		return (1);
	}
	else
	{
		free_list(history_list);
		free_array(*env);
		exit (ft_atoi(input[1]));
	}
}

char	*get_working_directory(void)
{
	char		*cwd;
	size_t		size;

	size = 256;
	while (1)
	{
		cwd = (char *)malloc(size);
		if (cwd != NULL)
		{
			if (getcwd(cwd, size) != NULL)
				return (cwd);
			else
			{
				free(cwd);
				size *= 2;
			}
		}
		else
			perror("malloc");
	}
}

int	print_working_directory(void)
{
	char	*cwd;

	cwd = get_working_directory();
	if (cwd != NULL)
	{
		write(STDOUT_FILENO, cwd, ft_strlen(cwd));
		write(STDOUT_FILENO, "\n", 1);
		free(cwd);
	}
	return (0);
}

int	change_directory(char **input, char **env)
{
	char	*cwd;
	int		status;
	char	*tmp;

	if (input[1] != NULL && input[2] != NULL)
	{
		write(2, "cd: too many arguments\n", 23);
		return (1);
	}
	cwd = get_working_directory();
	update_env("OLDPWD", cwd, env);
	free(cwd);
	status = change_directory_status(input, env);
	if (status != 0)
	{
		tmp = ft_strjoin("Minishell: cd: ", input[1]);
		perror(tmp);
		status = 1;
		free(tmp);
	}
	cwd = get_working_directory();
	update_env("PWD", cwd, env);
	free(cwd);
	return (status);
}

int	echo(char **input)
{
	int	i;

	i = 0;
	if (input[1] == NULL)
	{
		write(STDOUT_FILENO, "\n", 1);
		return (0);
	}
	if ((ft_strncmp(input[1], "-n", ft_strlen(input[1]) + 1) == 0))
		i = 1;
	while (input[i + 1] != NULL)
	{
		write(STDOUT_FILENO, input[i + 1], ft_strlen(input[i + 1]));
		i++;
		if (input[i + 1] != NULL)
			write(STDOUT_FILENO, " ", 1);
	}
	if (!(ft_strncmp(input[1], "-n", 3) == 0))
		write(STDOUT_FILENO, "\n", 1);
	return (0);
}
