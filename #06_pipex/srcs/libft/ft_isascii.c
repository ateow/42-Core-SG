/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ateow <ateow@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 08:21:16 by ateow             #+#    #+#             */
/*   Updated: 2023/09/06 08:21:19 by ateow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}
/*
int	main(void)
{
	char	c;

	c = 128;
	printf("\nOG: %d", isascii(c));
	printf("\nft: %d", ft_isascii(c));

	c = '5';
	printf("\nOG: %d", isascii(c));
	printf("\nft: %d", ft_isascii(c));

	c = 'a';
	printf("\nOG: %d", isascii(c));
	printf("\nft: %d", ft_isascii(c));
	
	c = ')';
	printf("\nOG: %d", isascii(c));
	printf("\nft: %d", ft_isascii(c));
}*/
