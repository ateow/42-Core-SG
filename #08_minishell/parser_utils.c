/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cooi <cooi@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 11:01:45 by cooi              #+#    #+#             */
/*   Updated: 2023/12/29 11:01:46 by cooi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_split	check_quotes_and_brackets(t_split sp, char c)
{
	if (c == '\'')
		sp.sq = !sp.sq;
	if (c == '"')
		sp.dq = !sp.dq;
	sp.b = sp.b + (c == '(') - (c == ')');
	return (sp);
}

t_split	extract_operator(t_split sp, char ***r, int *c, char *in)
{
	char	*t;

	t = ft_substr(in, sp.j, sp.i - sp.j);
	(*r)[*c - 1] = ft_strtrim(t, " ");
	free (t);
	sp.j = sp.i;
	(*c)++;
	(*r) = ft_realloc((*r), (*c + 1) * sizeof(char *), *c * sizeof(char *));
	sp.i = sp.i + 1 + (in[sp.i] == in[sp.i + 1]);
	t = ft_substr(in, sp.j, sp.i - sp.j);
	(*r)[*c - 1] = ft_strtrim(t, " ");
	free (t);
	(*c)++;
	sp.j = sp.i;
	(*r) = ft_realloc((*r), (*c + 1) * sizeof(char *), *c * sizeof(char *));
	return (sp);
}

t_split	add_space_after(t_split sp, char *in, char **ret)
{
	char	*sub;
	char	*tmp;

	sp.i = sp.i + 1 + (in[sp.i] == in[sp.i + 1]);
	sub = ft_substr(in, sp.j, sp.i - sp.j);
	tmp = ft_strjoin((*ret), sub);
	free ((*ret));
	free (sub);
	(*ret) = tmp;
	if (in[sp.i] && in[sp.i] != ' ')
	{
		tmp = ft_strjoin((*ret), " ");
		free ((*ret));
		(*ret) = tmp;
	}
	sp.j = sp.i;
	return (sp);
}

t_split	add_space_before(t_split sp, char *in, char **ret)
{
	char	*sub;
	char	*tmp;

	sub = ft_substr(in, sp.j, sp.i - sp.j);
	tmp = ft_strjoin((*ret), sub);
	free ((*ret));
	free (sub);
	(*ret) = tmp;
	if (sp.i > 0 && (*ret)[ft_strlen((*ret)) - 1] != ' ')
	{
		tmp = ft_strjoin((*ret), " ");
		free ((*ret));
		(*ret) = tmp;
	}
	sp.j = sp.i;
	return (sp);
}

char	*inject_space(char *in)
{
	t_split	sp;
	char	*ret;
	char	*sub;
	char	*tmp;

	sp = init_split();
	ret = ft_strdup("");
	while (in[sp.i])
	{
		sp = check_quotes_and_brackets(sp, in[sp.i]);
		if (ft_strchr("<>&|", in[sp.i])
			&& sp.b == 0 && sp.sq == 0 && sp.dq == 0)
		{
			sp = add_space_before(sp, in, &ret);
			sp = add_space_after(sp, in, &ret);
		}
		else
			sp.i++;
	}
	sub = ft_substr(in, sp.j, sp.i - sp.j);
	tmp = ft_strjoin(ret, sub);
	free (ret);
	free (sub);
	ret = tmp;
	return (ret);
}
