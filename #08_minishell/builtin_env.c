/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ateow <ateow@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 23:28:07 by ateow             #+#    #+#             */
/*   Updated: 2023/12/27 23:28:08 by ateow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	unset_env(char *input, char ***env)
{
	char	**tmp;
	int		i;
	int		j;

	j = 0;
	i = 0;
	if (input == NULL)
		return (0);
	tmp = ft_calloc(1, sizeof(char *));
	while ((*env)[i] != NULL)
	{
		tmp = ft_realloc(tmp, (i + 2) * sizeof(char *),
				(i + 1) * sizeof(char *));
		if (ft_strncmp((*env)[i], input, ft_strlen(input)) != 0)
		{
			tmp[j] = ft_strdup((*env)[i]);
			j++;
		}
		i++;
	}
	tmp[j] = NULL;
	free_array(*env);
	*env = tmp;
	return (0);
}

int	print_env(char **env)
{
	int	i;

	i = 0;
	while (env[i] != NULL)
	{
		write(STDOUT_FILENO, env[i], ft_strlen(env[i]));
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
	return (0);
}

int	export_env(char *input, char ***env)
{
	char	*var;
	char	*string;

	var = ft_calloc(1, sizeof(char));
	string = ft_calloc(1, sizeof(char));
	get_var_string(&var, &string, input);
	if ((ft_isalpha(var[0]) != 1 && var[0] != '_')
		|| (ft_strchr(var, '-') != NULL
			|| ft_strchr(var, '!') != NULL))
	{
		write(2, "Minishell: export: not a valid identifier\n", 42);
		free(var);
		free(string);
		return (1);
	}
	if (ft_strchr(input, '=') != NULL)
		if (update_env(var, string, *env) == 0)
			append_env(input, env);
	free(var);
	free(string);
	return (0);
}

void	append_env(char *input, char ***env)
{
	int		i;
	char	**tmp;

	i = 0;
	while ((*env)[i] != NULL)
		i++;
	tmp = malloc(sizeof(char *) * (i + 2));
	if (tmp == NULL)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	i = 0;
	while ((*env)[i] != NULL)
	{
		tmp[i] = ft_strdup((*env)[i]);
		i++;
	}
	tmp[i] = ft_strdup(input);
	tmp[i + 1] = NULL;
	free_array(*env);
	*env = tmp;
}

int	update_env(char	*var, char *new_string, char **env)
{
	int		i;
	int		len;
	char	*tmp;

	len = 0;
	i = 0;
	while (env[i] != NULL)
	{
		len = 0;
		while (env[i][len] != '=')
			len++;
		if (ft_strncmp(env[i], var, len) == 0)
		{
			free(env[i]);
			tmp = ft_strjoin(var, "=");
			env[i] = ft_strjoin(tmp, new_string);
			free(tmp);
			return (1);
		}
		i++;
	}
	return (0);
}
