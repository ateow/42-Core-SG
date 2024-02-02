/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cooi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 17:26:35 by cooi              #+#    #+#             */
/*   Updated: 2023/09/07 18:06:49 by cooi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long	count_digits(int n)
{
	long	i;
	long	tmp;

	tmp = n;
	if (n < 0)
		tmp *= -1;
	else
		tmp = n;
	i = 1;
	while (tmp > 9)
	{
		tmp /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*ret;
	long	tmp;
	long	digits;

	tmp = n;
	digits = count_digits(n);
	if (tmp < 0)
	{
		digits++;
		tmp *= -1;
	}
	ret = (char *)malloc((digits + 1) * sizeof(char));
	if (!ret)
		return (NULL);
	ret[digits] = '\0';
	while (digits-- > 0)
	{
		ret[digits] = tmp % 10 + '0';
		tmp /= 10;
	}
	if (n < 0)
		ret[0] = '-';
	return (ret);
}
