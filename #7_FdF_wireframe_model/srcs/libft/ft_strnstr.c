/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ateow <ateow@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 11:58:32 by ateow             #+#    #+#             */
/*   Updated: 2023/09/07 11:58:34 by ateow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <bsd/string.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t		i;
	size_t		j;

	i = 0;
	if (!*needle)
		return ((char *) haystack);
	while (haystack[i] && i < len)
	{
		j = 0;
		while (needle[j] == haystack[i + j] && i + j < len)
			if (!needle[++j])
				return ((char *) haystack + i);
		i++;
	}
	return (0);
}
/*
int main ()
{
	char haystack[99] ="123456";
	char needle[99] = "2";

	printf("ft: %s\n", ft_strnstr(haystack, needle, 6));	
	printf("og: %s\n", strnstr(haystack, needle, 6));
	
	printf("\nnew: %s",ft_strnstr("lorem ipsum dolor sit amet", "ipsumm", 30));
}*/
