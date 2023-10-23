/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ateow <ateow@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 10:52:35 by ateow             #+#    #+#             */
/*   Updated: 2023/09/06 10:52:37 by ateow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	while (n > 0)
	{
		((unsigned char *)str)[n - 1] = (unsigned char)c;
		n--;
	}
	return (str);
}
/*
int	main()
{
	char s[] = "123456";
	char t[] = "123456";
	memset(s, 'a', 3);
	ft_memset(t, 'a', 3);
	printf("OG string: %s", s);
	printf("\nft string: %s", t);
}*/
