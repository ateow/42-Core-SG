/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cooi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 19:40:10 by cooi              #+#    #+#             */
/*   Updated: 2023/09/06 21:03:27 by cooi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *hstk, const char *ndl, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (*ndl == '\0' || !ndl)
		return ((char *)hstk);
	while (hstk[i] != '\0')
	{
		j = 0;
		while (hstk[i + j] != '\0' && ndl[j] != '\0' && i + j < len)
		{
			if (hstk[i + j] != ndl[j])
				break ;
			j++;
		}
		if (ndl[j] == '\0')
			return ((char *)(hstk + i));
		i++;
	}
	return (NULL);
}
