/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_phexanbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ateow <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 16:31:27 by ateow             #+#    #+#             */
/*   Updated: 2023/09/15 16:31:27 by ateow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_phexanbr(unsigned int nbrx, char c)
{
	char	*hex;
	int		count;

	count = 0;
	if (c == 'x')
		hex = "0123456789abcdef";
	else if (c == 'X')
		hex = "0123456789ABCDEF";
	if (nbrx < 16)
	{
		ft_pchar(hex[nbrx]);
		count++;
	}
	else
	{
		count += ft_phexanbr(nbrx / 16, c);
		count += ft_phexanbr(nbrx % 16, c);
	}
	return (count);
}
