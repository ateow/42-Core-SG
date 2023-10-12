/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ateow <ateow@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 07:59:10 by ateow             #+#    #+#             */
/*   Updated: 2023/09/06 07:59:13 by ateow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')
		|| (c >= '0' && c <= '9'))
		return (1);
	return (0);
}
/*
int	main(void)
{
	char	c;

	c = 'Z';
	printf("\nOG_isdigit: %d", isalnum(c));
	printf("\nft_isdigit: %d", ft_isalnum(c));

	c = '5';
	printf("\nOG_isdigit: %d", isalnum(c));
	printf("\nft_isdigit: %d", ft_isalnum(c));

	c = 'a';
	printf("\nOG_isdigit: %d", isalnum(c));
	printf("\nft_isdigit: %d", ft_isalnum(c));
	
	c = ')';
	printf("\nOG_isdigit: %d", isalnum(c));
	printf("\nft_isdigit: %d", ft_isalnum(c));
	
	c = ' ';
	printf("\nOG_isdigit: %d", isalnum(c));
	printf("\nft_isdigit: %d", ft_isalnum(c));
}*/
