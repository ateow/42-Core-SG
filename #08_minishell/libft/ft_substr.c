/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cooi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 19:20:26 by cooi              #+#    #+#             */
/*   Updated: 2023/09/06 19:35:54 by cooi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	math(unsigned int start, size_t len, size_t i)
{
	if (i == 0)
		return (0);
	if (start + len > i)
		return (i - start);
	else
		return (len);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ret;
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	if (start > i)
		i = 0;
	len = math(start, len, i);
	ret = (char *)malloc((len + 1) * sizeof(char));
	if (!ret || !s)
		return (NULL);
	ret[0] = '\0';
	s += start;
	i = 0;
	while (i < len && s[i] != '\0')
	{
		ret[i] = s[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}
