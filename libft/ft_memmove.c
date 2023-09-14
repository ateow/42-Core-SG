/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ateow <ateow@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 03:20:33 by ateow             #+#    #+#             */
/*   Updated: 2023/09/07 03:20:35 by ateow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	len;

	len = 0;
	if (dest > src)
	{
		len = n;
		while (len > 0)
		{
			len--;
			((unsigned char *)dest)[len] = ((unsigned char *)src)[len];
		}
	}
	else
	{
		len = 0;
		while (len < n)
		{
			((unsigned char *)dest)[len] = ((unsigned char *)src)[len];
			len++;
		}
	}
	return (dest);
}
/*
int	main()
{
	char x[] = "abcde";
	ft_memmove(x + 1, x, 3);
	printf("\nstring: %s", x);
	//dest > src
	//copy from dest[n - 1] backwards to dest[0]
	
	char y[] = "abcde";
	ft_memmove(y, y + 1, 3);
	printf("\nstring: %s", y);
	//dest < src
	//copy from dest[0] forward to dest[n - 1]
}*/
