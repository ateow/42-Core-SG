/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_env_wild_wildcard.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cooi <cooi@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 19:40:07 by cooi              #+#    #+#             */
/*   Updated: 2023/12/31 15:32:46 by cooi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_break_condition(char *f, char *tmp, char **p, int i)
{
	if (i == 0 && ft_strncmp(f, p[i], ft_strlen(p[i])) != 0)
		return (NULL);
	if (p[i + 1] == NULL && ft_strlen(p[i]) > 0)
	{
		if (ft_strchr(f, '.') && (ft_strnstr(ft_strchr(f, '.'), p[i],
					ft_strlen(f)) == NULL))
			return (NULL);
		else if (ft_strnstr(tmp, p[i], ft_strlen(tmp)) == NULL)
			return (NULL);
		else if (ft_strncmp(f + (ft_strlen(f)
					- ft_strlen(p[i])), p[i], ft_strlen(p[i])) != 0)
			return (NULL);
	}
	return ("ok");
}

char	*get_directory_item(DIR *d)
{
	struct dirent	*dir;

	dir = readdir(d);
	if (!dir)
		return (NULL);
	else
		return (dir->d_name);
}

char	*read_directory(DIR *d, char ***r, int *c, char **p)
{
	char	*tmp;
	char	*f;
	int		i;

	f = get_directory_item(d);
	if (!f)
		return (NULL);
	i = 0;
	tmp = f;
	while (p[i] && tmp && (ft_strncmp(f, ".", 1) != 0))
	{
		if (get_break_condition(f, tmp, p, i) == NULL)
			break ;
		if (p[i + 1] == NULL)
		{
			(*r) = ft_realloc((*r), (*c + 1) * sizeof(char *),
					*c * sizeof(char *));
			(*r)[*c - 1] = ft_strdup(f);
			(*c)++;
		}
		else
			tmp = ft_strnstr(tmp, p[i], ft_strlen(tmp));
		i++;
	}
	return ("ok");
}

char	**getwildcard(char **pattern, char **env, int *exit_status)
{
	DIR				*directory;
	char			**r;
	int				c;

	if (!pattern)
		return (NULL);
	directory = opendir(get_env_value("PWD", env, exit_status));
	if (!directory)
	{
		perror(get_env_value("PWD", env, exit_status));
		return (NULL);
	}
	c = 1;
	r = NULL;
	while (1)
	{
		if (read_directory(directory, &r, &c, pattern) == NULL)
			break ;
	}
	if (r)
		r[c - 1] = NULL;
	closedir(directory);
	return (r);
}

char	**getpattern(char *input, int *wild)
{
	int		i;
	int		j;
	int		c;
	char	**r;

	i = 0;
	j = 0;
	c = 1;
	r = NULL;
	while (i < (int)ft_strlen(input) + 1)
	{
		if (input[i] == '*' || input[i] == '\0')
		{
			if (*wild != 0)
			{
				r = ft_realloc(r, (c + 1) * sizeof(char *), c * sizeof(char *));
				r[c - 1] = ft_substr(input, j, i - j);
				r[c++] = NULL;
				j = i + 1;
			}
			wild++;
		}
		i++;
	}
	return (r);
}
