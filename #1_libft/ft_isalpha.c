/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c             	                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ateow <ateow@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 06:50:09 by ateow             #+#    #+#             */
/*   Updated: 2023/09/06 06:50:18 by ateow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1);
	return (0);
}
/*
int	main(void)
{
	char	c;

	c = 'a';
	printf("\nOG_isalpha: %d", isalpha(c));
	printf("\nft_isalpha: %d", ft_isalpha(c));

	c = 'H';
	printf("\nOG_isalpha: %d", isalpha(c));
	printf("\nft_isalpha: %d", ft_isalpha(c));

	c = 'Z';
	printf("\nOG_isalpha: %d", isalpha(c));
	printf("\nft_isalpha: %d", ft_isalpha(c));

	c = ' ';
	printf("\nOG_isalpha: %d", isalpha(c));
	printf("\nft_isalpha: %d", ft_isalpha(c));

	c = '!';
	printf("\nOG_isalpha: %d", isalpha(c));
	printf("\nft_isalpha: %d", ft_isalpha(c));
}*/
