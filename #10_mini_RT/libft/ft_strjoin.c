/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cooi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 19:40:10 by cooi              #+#    #+#             */
/*   Updated: 2023/09/06 21:03:27 by cooi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ret;
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	while (s1 && s1[i] != '\0')
		i++;
	while (s2 && s2[j] != '\0')
		j++;
	ret = (char *)malloc((i + j + 1) * sizeof(char));
	if (!ret || !s1 || !s2)
		return (NULL);
	while (k < i && ++k)
		ret[k - 1] = s1[k - 1];
	i = 0;
	while (k + i < k + j && ++i)
		ret[k + i - 1] = s2[i - 1];
	ret[k + i] = '\0';
	return (ret);
}
