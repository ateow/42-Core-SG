/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ateow <ateow@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 06:50:09 by ateow             #+#    #+#             */
/*   Updated: 2023/09/06 06:50:18 by ateow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
/*
int	main(void)
{
	char	c;

	c = '0';
	printf("\nOG_isdigit: %d", isdigit(c));
	printf("\nft_isdigit: %d", ft_isdigit(c));

	c = '5';
	printf("\nOG_isdigit: %d", isdigit(c));
	printf("\nft_isdigit: %d", ft_isdigit(c));

	c = 'a';
	printf("\nOG_isdigit: %d", isdigit(c));
	printf("\nft_isdigit: %d", ft_isdigit(c));
	
	c = ')';
	printf("\nOG_isdigit: %d", isdigit(c));
	printf("\nft_isdigit: %d", ft_isdigit(c));
}*/
