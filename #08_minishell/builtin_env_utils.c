/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ateow <ateow@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 00:34:46 by ateow             #+#    #+#             */
/*   Updated: 2023/12/28 00:34:47 by ateow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**init_env(char *envp[])
{
	int		i;
	char	**e;

	i = 0;
	e = ft_calloc(1, sizeof(char *));
	while (envp[i] != NULL)
	{
		e = ft_realloc(e, (i + 2) * sizeof(char *), (i + 1) * sizeof(char *));
		e[i] = ft_strdup(envp[i]);
		i++;
	}
	e[i] = NULL;
	return (e);
}

void	get_var_string(char **var, char **string, char *input)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (input[i] != '=' && input[i] != '\0')
	{
		*var = ft_realloc(*var, (i + 2) * sizeof(char *),
				(i + 1) * sizeof(char *));
		(*var)[i] = input[i];
		i++;
	}
	(*var)[i] = '\0';
	while (input[i] != '\0')
	{
		*string = ft_realloc(*string, (j + 2) * sizeof(char *),
				(j + 1) * sizeof(char *));
		(*string)[j] = input[i + 1];
		i++;
		j++;
	}
	(*string)[j] = '\0';
}

int	is_not_number(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (i == 0 && (s[i] == '+' || s[i] == '-'))
			;
		else if (s[i] < '0' || s[i] > '9')
			return (1);
		i++;
	}
	return (0);
}

int	change_directory_status(char **input, char **env)
{
	int	status;

	if (input[1] == NULL || input[1][0] == '\0' || input [1][0] == '~')
		status = chdir(get_env_value("HOME", env, 0));
	else
		status = chdir(input[1]);
	return (status);
}
