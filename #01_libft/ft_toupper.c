/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ateow <ateow@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 08:37:23 by ateow             #+#    #+#             */
/*   Updated: 2023/09/07 08:37:25 by ateow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		c = c - 32;
	return (c);
}
/*
int	main()
{
	printf("Function: toupper");

	char c = 'a';
	printf("\n\ninput: a");
	printf("\nft_toupper: %c", ft_toupper(c));	
	printf("\nOG_toupper: %c", toupper(c));
	
	char d = 'A';
	printf("\n\ninput: A");
	printf("\nft_toupper: %c", ft_toupper(d));	
	printf("\nOG_toupper: %c", toupper(d));

	char e = '!';
	printf("\n\ninput: !");
	printf("\nft_toupper: %c", ft_toupper(e));	
	printf("\nOG_toupper: %c", toupper(e));
}*/
