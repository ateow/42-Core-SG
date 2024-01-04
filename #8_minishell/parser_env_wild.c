/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_env_wild.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cooi <cooi@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 19:40:07 by cooi              #+#    #+#             */
/*   Updated: 2023/12/31 15:14:16 by cooi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	wild_expansion(t_wild *w, char *string, t_var *vars, int *wild)
{
	char	**pattern;
	char	**wildcards;
	int		z;

	pattern = getpattern(string, wild);
	wildcards = getwildcard(pattern, vars->env, &(vars->exit_status));
	if (wildcards)
	{
		z = 0;
		while (wildcards[z])
		{
			w->ret = ft_realloc(w->ret, (w->c + 1 + z) * sizeof(char *),
					(w->c + z) * sizeof(char *));
			w->ret[w->c - 1 + z] = ft_strdup(wildcards[z]);
			free (wildcards[z]);
			z++;
		}
		w->c = w->c + z - 1;
		free (wildcards);
	}
	free_array(pattern);
}

char	*expand_args(char *string, char **env, int *exit_status)
{
	int		idx;
	int		quote;

	idx = 0;
	quote = 0;
	while (idx < (int)ft_strlen(string))
	{
		if (string[idx] == '\'' && quote == 0)
		{
			ft_memmove(string + idx, string + idx + 1, ft_strlen(string) - idx);
			while (string[idx] && string[idx] != '\'')
				idx++;
		}
		else if (string[idx] == '"')
		{
			quote = !quote;
			ft_memmove(string + idx, string + idx + 1, ft_strlen(string) - idx);
		}
		else if (string[idx] == '$')
			string = env_expansion(string, &idx, env, exit_status);
		else
			idx++;
	}
	return (string);
}

int	*check_wildcards(char *string)
{
	int		i;
	int		c;
	int		*ret;
	t_split	sp;

	sp = init_split();
	i = -1;
	c = 1;
	ret = NULL;
	while (string[++i])
	{
		sp = check_quotes_and_brackets(sp, string[i]);
		if (string[i] == '*' && string[i + 1] != '*'
			&& sp.sq == 0 && sp.dq == 0)
		{
			ret = ft_realloc(ret, (c + 1) * sizeof(int), c * sizeof(int));
			if (sp.sq == 0 && sp.dq == 0)
				ret[c - 1] = 1;
			else
				ret[c - 1] = 0;
			ret[c++] = -1;
		}
	}
	return (ret);
}

int	extract_args(t_wild *w, char *string, int idx, t_var *vars)
{
	t_split	sp;
	int		*wild;
	int		jdx;
	char	*tmp;

	sp = init_split();
	jdx = idx;
	while (string[idx])
	{
		sp = check_quotes_and_brackets(sp, string[idx]);
		if (sp.sq == 0 && sp.dq == 0 && string[idx] == ' ')
			break ;
		idx++;
	}
	tmp = ft_substr(string, jdx, idx - jdx);
	wild = check_wildcards(tmp);
	(w->ret)[w->c - 1] = expand_args(tmp, vars->env, &(vars->exit_status));
	if (wild != NULL)
		wild_expansion(w, (w->ret)[w->c - 1], vars, wild);
	return (idx);
}

char	**var_expand_wild_arr(char *string, t_var *vars)
{
	int		index;
	t_wild	wild;

	index = 0;
	wild.c = 0;
	wild.ret = ft_calloc(1, sizeof(char *));
	while (++wild.c)
	{
		wild.ret = ft_realloc(wild.ret, (wild.c + 1)
				* sizeof(char *), (wild.c) * sizeof(char *));
		index = extract_args(&wild, string, index, vars);
		while (string[index] && string[index] == ' ')
			index++;
		if (string[index] == '\0')
			break ;
	}
	wild.ret[wild.c] = NULL;
	wild.ret = remove_empty_string(wild.ret);
	return (wild.ret);
}
