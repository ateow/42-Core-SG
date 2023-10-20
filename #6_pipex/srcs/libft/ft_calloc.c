/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ateow <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 12:19:43 by ateow             #+#    #+#             */
/*   Updated: 2023/09/08 12:19:47 by ateow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*p;

	p = malloc(count * size);
	if (p)
		ft_bzero(p, count * size);
	return (p);
}
/*
int	main()
{
	printf("### Function: calloc ###");
	char *s = "hello";
	printf("\nft: %s\n",s);
	
	s = ft_calloc(2 * sizeof(char));
	printf("\nft: %c\n",s[0]);
}*/
