/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ateow <ateow@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 08:37:32 by ateow             #+#    #+#             */
/*   Updated: 2023/09/07 08:37:34 by ateow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		c = c + 32;
	return (c);
}
/*
int	main()
{
	printf("Function: tolower");
	char c = 'a';
	printf("\n\ninput: a");
	printf("\nft_tolower: %c", ft_tolower(c));	
	printf("\nOG_tolower: %c", tolower(c));
	
	char d = 'A';
	printf("\n\ninput: A");
	printf("\nft_tolower: %c", ft_tolower(d));	
	printf("\nOG_toupper: %c", tolower(d));

	char e = '!';
	printf("\n\ninput: !");
	printf("\nft_tolower: %c", ft_tolower(e));	
	printf("\nOG_tolower: %c", tolower(e));
}*/
