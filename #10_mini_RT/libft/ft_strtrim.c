/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cooi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 21:19:16 by cooi              #+#    #+#             */
/*   Updated: 2023/09/06 22:23:41 by cooi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	in_set(char const c, char const *set)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ret;
	int		i;
	int		j;
	int		k;

	i = -1;
	j = 0;
	k = 0;
	if (s1 == NULL || set == NULL)
		return (NULL);
	while (s1[++i])
	{
		if (in_set(s1[i], set) && i == j)
			j++;
	}
	while (in_set(s1[i - 1], set) && i != j)
		i--;
	ret = (char *)malloc((i - j + 1) * sizeof(char));
	if (!ret)
		return (NULL);
	ret[0] = '\0';
	while (j + k < i && ++k)
		ret[k - 1] = s1[j + k - 1];
	ret[k] = '\0';
	return (ret);
}
