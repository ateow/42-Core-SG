/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: CHRISTOPHER OOI <cooi@student.42singa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 13:14:23 by CHRISTOPH         #+#    #+#             */
/*   Updated: 2023/08/04 13:56:21 by CHRISTOPH        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*dest;
	int		i;
	int		j;

	i = 0;
	while (src[i] != '\0')
		i++;
	j = 0;
	dest = (char *)malloc((i + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	while (j < i)
	{
		dest[j] = src[j];
		j++;
	}
	dest[j] = '\0';
	return (dest);
}
