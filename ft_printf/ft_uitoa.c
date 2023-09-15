/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ateow <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 16:01:15 by ateow             #+#    #+#             */
/*   Updated: 2023/09/15 16:01:17 by ateow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static unsigned int	ft_len(unsigned int n)
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

char	*ft_uitoa(int n)
{
	char			*arr;
	unsigned int	nb;
	unsigned int	len;

	nb = (unsigned int)n;
	len = ft_len(nb);
	arr = malloc((len + 1) * sizeof(char));
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
