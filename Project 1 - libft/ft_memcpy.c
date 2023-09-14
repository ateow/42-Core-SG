/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ateow <ateow@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 03:06:43 by ateow             #+#    #+#             */
/*   Updated: 2023/09/07 03:06:45 by ateow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	len;

	len = 0;
	while (len < n)
	{
		((unsigned char *)dest)[len] = ((unsigned char *)src)[len];
		len++;
	}
	return (dest);
}
/*
int	main()
{
	char s[] = "hello world";
	ft_memcpy(s + 6, s, 5);
	printf("\nft string: %s", s);
	
	char t[] = "hello world";
	memcpy(t + 6, t, 5);
	printf("\nOG string: %s", t);
	
	char x[] = "123456789";
	ft_memcpy(x + 1, x, 5);
	printf("\nft string: %s", x);
	//this will cause memory to overlap because 
		//src and des are pointers to the same strings.
	//this means after copying 1 into des, the next copy from will take 
		//from this new des which is 1. resulting in 111111789
	
	char y[] = "123456789";
	ft_memcpy(y, y + 1, 5);
	printf("\nOG string: %s", y);
}*/
