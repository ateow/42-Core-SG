/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils_split.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ateow <ateow@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 01:46:47 by ateow             #+#    #+#             */
/*   Updated: 2023/12/30 01:46:50 by ateow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_split	init_split(void)
{
	t_split	ret;

	ret.b = 0;
	ret.i = 0;
	ret.j = 0;
	ret.sq = 0;
	ret.dq = 0;
	return (ret);
}

char	**split_redirection(char *in)
{
	t_split	sp;
	int		c;
	char	*t;
	char	**r;

	sp = init_split();
	c = 1;
	r = ft_calloc((c + 1), sizeof(char *));
	while (in[sp.i])
	{
		sp = check_quotes_and_brackets(sp, in[sp.i]);
		if (ft_strchr("<>", in[sp.i]) && sp.b == 0 && sp.sq == 0 && sp.dq == 0)
			sp = extract_operator(sp, &r, &c, in);
		else
			sp.i++;
	}
	if (sp.i != sp.j)
		t = ft_substr(in, sp.j, sp.i - sp.j);
	else
		t = ft_strdup(" ");
	r[c - 1] = ft_strtrim(t, " ");
	free (t);
	r[c] = NULL;
	return (r);
}

char	**split_and_or_pipe(char *in)
{
	t_split	sp;
	int		c;
	char	*t;
	char	**r;

	sp = init_split();
	c = 1;
	r = ft_calloc((c + 1), sizeof(char *));
	while (in[sp.i])
	{
		sp = check_quotes_and_brackets(sp, in[sp.i]);
		if (ft_strchr("&|", in[sp.i]) && sp.b == 0 && sp.sq == 0 && sp.dq == 0)
			sp = extract_operator(sp, &r, &c, in);
		sp.i++;
	}
	if (sp.i - sp.j != 0)
	{
		t = ft_substr(in, sp.j, sp.i - sp.j);
		r[c - 1] = ft_strtrim(t, " ");
		free (t);
		r[c] = NULL;
	}
	return (r);
}

char	*split_quotes(char *input, int *idx)
{
	int		length;
	char	target;
	char	*tmp;

	target = ' ';
	if (input[*idx] == '\'' || input[*idx] == '"')
		target = input[*idx];
	tmp = ft_strchr(input + *idx + 1, target);
	if (tmp)
		length = tmp - (input + *idx) + 1;
	else
		length = ft_strlen(input) - *idx;
	tmp = ft_substr(input, *idx, length);
	*idx += length;
	if (input[*idx] == ' ')
		(*idx)++;
	return (tmp);
}

char	*split_brackets(char *input, int *idx)
{
	char	*tmp;
	int		length;
	int		brackets;

	if (input[*idx] == '(')
	{
		brackets = 1;
		tmp = input + *idx;
		while (*(++tmp) && brackets != 0)
		{
			if (*tmp == '(')
				brackets++;
			else if (*tmp == ')')
				brackets--;
		}
	}
	else
		return (split_quotes(input, idx));
	if (tmp && *tmp)
		length = tmp - (input + *idx);
	else
		length = ft_strlen(input) - *idx;
	tmp = ft_substr(input, *idx, length);
	*idx += length;
	return (tmp);
}
