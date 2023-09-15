/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ateow <ateow@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 05:51:19 by ateow             #+#    #+#             */
/*   Updated: 2023/09/09 05:51:23 by ateow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_len(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n != 0)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*arr;
	long	nb;
	int		len;

	nb = n;
	len = ft_len(n);
	arr = malloc((len + 1) * sizeof(char));
	if (n < 0)
	{
		arr[0] = '-';
		nb = -nb;
	}
	if (nb == 0)
		arr[0] = '0';
	arr[len] = '\0';
	while (nb != 0)
	{
		arr[--len] = (nb % 10) + '0';
		nb = nb / 10;
	}
	return (arr);
}
/*
int	main()
{
	printf("%s",ft_itoa(-2147483648));
}*/
