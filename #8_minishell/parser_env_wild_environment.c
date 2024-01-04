/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_env_wild_environment.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cooi <cooi@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 19:40:07 by cooi              #+#    #+#             */
/*   Updated: 2023/12/31 15:14:42 by cooi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_env_value(char *key, char **env, int *exit_status)
{
	char	*value;
	char	*tmp;
	int		i;
	int		len;

	i = 0;
	value = NULL;
	while (env[i] != NULL)
	{
		len = 0;
		while (env[i][len] != '=')
			len++;
		if (ft_strncmp(env[i], key, len) == 0)
			return (ft_strdup(env[i] + (len + 1)));
		i++;
	}
	if (key[0] == '$' && ft_strlen(key) == 1)
		value = ft_strdup("$");
	else if (key[0] == '?')
	{
		tmp = ft_itoa(*exit_status);
		value = ft_strjoin(tmp, key + 1);
		free(tmp);
	}
	return (value);
}

char	*env_expansion(char *s, int *i, char **env, int *exit_status)
{
	char	*tmp;
	char	*sub;
	char	*ret;
	int		jdx;

	sub = ft_substr(s, 0, *i);
	(*i)++;
	jdx = *i;
	while (s[*i] && (ft_isalnum(s[*i]) || s[*i] == '_' || s[*i] == '?'))
		(*i)++;
	ret = sub;
	if (jdx == *i)
		sub = ft_strdup("$");
	else
		sub = ft_substr(s, jdx, *i - jdx);
	tmp = get_env_value(sub, env, exit_status);
	free (sub);
	sub = ft_strjoin(ret, tmp);
	free (ret);
	free (tmp);
	ret = sub;
	sub = ft_substr(s, *i, ft_strlen(s) - *i);
	free (s);
	s = ft_strjoin(ret, sub);
	return (free(ret), free(sub), s);
}
