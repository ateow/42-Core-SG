/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cooi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 14:48:02 by cooi              #+#    #+#             */
/*   Updated: 2023/09/07 17:25:56 by cooi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c)
{
	int	count;
	int	n;
	int	word;

	count = 0;
	n = 0;
	word = 0;
	while (s[n])
	{
		if (word == 0 && s[n] != c)
		{
			count++;
			word = 1;
		}
		else if (word == 1 && s[n] == c)
			word = 0;
		n++;
	}
	return (count);
}

static char	*make_string(char const *s, int j)
{
	char	*ret;

	ret = (char *)malloc((j + 1) * sizeof(char));
	if (!ret)
		return (NULL);
	ret[j] = '\0';
	while (--j > -1)
		ret[j] = s[j];
	return (ret);
}

static char	**make_ret(char const *s, char c, int count, char **ret)
{
	int	i;
	int	j;

	i = -1;
	while (++i < count && *s)
	{
		j = 0;
		while (*s && *s == c)
			s++;
		while (s[j] && s[j] != c)
			j++;
		ret[i] = make_string(s, j);
		if (!ret[i])
		{
			while (i > -1)
				free(ret[i--]);
			free(ret);
			return (NULL);
		}
		while (*s && *s != c)
			s++;
	}
	ret[i] = NULL;
	return (ret);
}

char	**ft_split(char *s, char c)
{
	char	**ret;
	int		count;

	count = count_words(s, c);
	ret = (char **)malloc((count + 1) * sizeof(char *));
	if (!ret)
		return (NULL);
	return (make_ret(s, c, count, ret));
}
