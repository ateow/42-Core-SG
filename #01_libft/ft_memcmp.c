/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ateow <ateow@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 11:03:21 by ateow             #+#    #+#             */
/*   Updated: 2023/09/07 11:03:22 by ateow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	int	i;

	i = 0;
	while (i < (int)n)
	{
		if (((unsigned char *)s1)[i] != ((unsigned char *)s2)[i])
			return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
		i++;
	}
	return (0);
}
/*
int main()
{
	printf("### Function: memcmp ###");

	printf("\n\nstring1: Geeks\nstring2: Geeks\nn: 10");	
	printf("\nOG: %d", memcmp("Geeks", "Geeks", 10));
	printf("\nft: %d", ft_memcmp("Geeks", "Geeks", 10));
	
	printf("\n\nstring1: Geeks\nstring2: Geeks\nn: -1");	
	printf("\nOG: %d", memcmp("Geeks", "Geeks", -1));
	printf("\nft: %d", ft_memcmp("Geeks", "Geeks", -1));
	
	printf("\n\nstring1: Geekaaa\nstring2: Geekzzz\nn: 4");	
	printf("\nOG: %d", memcmp("Geekaaa", "Geekzzz", 4));
	printf("\nft: %d", ft_memcmp("Geekaaa", "Geekzzz", 4));
	
	printf("\n\nstring1: Geekaaa\nstring2: Geekzzz\nn: 5");	
	printf("\nOG: %d", memcmp("Geekqaa", "Geekzzz", 5));
	printf("\nft: %d", ft_memcmp("Geekqaa", "Geekzzz", 5));
	
	printf("\n\nstring1: Geekzzz\nstring2: Geekaaa\nn: 5");	
	printf("\nOG: %d", memcmp("Geekzzz", "Geekaaa", 5));
	printf("\nft: %d", ft_memcmp("Geekzzz", "Geekaaa", 5));

	printf("\n\nstring1: Geeka""\nstring2: Geekb\nn: 5");	
	printf("\nOG: %d", memcmp("Geeka", "Geekb", 5));
	printf("\nft: %d", ft_memcmp("Geeka", "Geekb", 5));
}*/
