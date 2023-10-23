/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ateow <ateow@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 14:22:13 by ateow             #+#    #+#             */
/*   Updated: 2023/09/08 14:22:15 by ateow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;

	if (!s)
		return (0);
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	if (start >= ft_strlen(s))
	{
		len = 0;
		start = ft_strlen(s);
	}
	str = (char *) malloc((len + 1) * sizeof(char));
	if (!str)
		return (0);
	ft_strlcpy(str, &s[start], len + 1);
	return (str);
}
/*
int	main()
{
	printf("### Function: ft_substr ###");
	char *s = "hello world";
	
	printf("\nft: %s", ft_substr(s, 0, 0));
	printf("\nft: %s", ft_substr(s, 3, 7));
	printf("\nft: %s", ft_substr(s, 3, -5));
	printf("\nft: %s\n", ft_substr(s, -5, 1));
}*/
