/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ateow <ateow@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 05:39:29 by ateow             #+#    #+#             */
/*   Updated: 2023/09/07 05:39:30 by ateow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size > 0)
	{
		while (src[i] != '\0' && i < (size - 1))
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	while (src[i] != '\0')
		i++;
	return (i);
}
/*
int	main()
{
	printf("### Function: strlcpy ###");
	//function suppose to return len of src
	//function will null terminate. means size - 1. last byte for null
	//assume that size that user end is less or equal to dest size
	
	char src[] = "helloworld";
	char src2[] = "helloworld";
	char dest[15] = "nonono";
	char dest2[15] = "nonono";

	printf("\n\nft len:%ld", ft_strlcpy(dest2, src2, 0));
	printf("\nft string:%s\n", dest2);
		
	printf("\n\nOG len:%ld", strlcpy(dest, src, 0));
	printf("\nOG string:%s\n", dest);
}*/
