/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ateow <ateow@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 10:18:03 by ateow             #+#    #+#             */
/*   Updated: 2023/09/07 10:18:04 by ateow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned int	i;

	i = 0;
	while (i < n)
	{
		if (((unsigned char *)s)[i] == (unsigned char)c)
			return ((void *)(s + i));
		i++;
	}
	return (NULL);
}
/*
int	main()
{
	printf("### Function: memchr ###");
	char s[] = "hello world";
	printf("\n\ninput: hello world\nchar: l\nn: 1");	
	printf("\nOG: %s", (char *)memchr(s, 'l', 1));
	printf("\nft: %s", (char *)ft_memchr(s, 'l', 1));
	printf("\nOG: %p", memchr(s, 'l', 1));
	printf("\nft: %p", ft_memchr(s, 'l', 1));

	printf("\n\ninput: hello world\nchar: l\nn: 5");	
	printf("\nOG: %s", (char *)memchr(s, 'l', 5));
	printf("\nft: %s", (char *)ft_memchr(s, 'l', 5));
	printf("\nOG: %p", memchr(s, 'l', 5));
	printf("\nft: %p", ft_memchr(s, 'l', 5));

	printf("\n\ninput: hello world\nchar: null\nn: 5");	
	printf("\nOG: %s", (char *)memchr(s, '\0', 5));
	printf("\nft: %s", (char *)ft_memchr(s, '\0', 5));
	printf("\nOG: %p", memchr(s, '\0', 5));
	printf("\nft: %p", ft_memchr(s, '\0', 5));		
}*/
