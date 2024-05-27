/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ateow <ateow@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 08:26:08 by ateow             #+#    #+#             */
/*   Updated: 2023/09/06 08:26:10 by ateow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}
/*
int	main(void)
{
	char	c;

	c = ' ';
	printf("\nOG: %d", isprint(c));
	printf("\nft: %d", ft_isprint(c));

	c = '	';
	printf("\nOG: %d", isprint(c));
	printf("\nft: %d", ft_isprint(c));

	c = 'a';
	printf("\nOG: %d", isprint(c));
	printf("\nft: %d", ft_isprint(c));
	
	c = ')';
	printf("\nOG: %d", isprint(c));
	printf("\nft: %d", ft_isprint(c));
}*/
