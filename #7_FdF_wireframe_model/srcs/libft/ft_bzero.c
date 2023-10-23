/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ateow <ateow@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 12:30:03 by ateow             #+#    #+#             */
/*   Updated: 2023/09/06 12:30:07 by ateow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}
/*
int	main()
{
	char s[] = "123456";
	char t[] = "123456";
	bzero(s, 3);
	ft_bzero(t, 3);
	printf("OG string: %s", s);
	printf("\nft string: %s", t);
}*/
