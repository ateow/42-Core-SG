/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ateow <ateow@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 08:49:39 by ateow             #+#    #+#             */
/*   Updated: 2023/09/14 08:49:41 by ateow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_definetype(char c, va_list args, int *i)
{
	if (c == 'i' || c == 'd')
		return (ft_itoa(va_arg(args, int)));
	else if (c == 'u')
		return (ft_uitoa(va_arg(args, unsigned int)));
	else if (c == 'c')
		return (ft_pchar(va_arg(args, int)));
	else if (c == 's')
		return (ft_pstring(va_arg(args, char *)));
	else if (c == 'x' || c == 'X')
		return (ft_phexanbr(va_arg(args, unsigned int), c));
	else if (c == 'p')
		return (ft_ppointer(va_arg(args, unsigned long)));
	else if (c == '%')
		return (ft_pchar('%'));
	else
		(*i)--;
	return (0);
}

int	ft_printf(const char *input, ...)
{
	int		i;
	int		count;
	va_list	args;

	va_start(args, input);
	i = 0;
	count = 0;
	while (input[i] != '\0')
	{
		if (input[i] == '%')
		{
			i++;
			count += ft_definetype(input[i], args, &i);
			i++;
		}
		else
		{
			count += ft_pchar(input[i]);
			i++;
		}
	}
	va_end(args);
	return (count);
}
/*
#include <stdio.h>
int	main(void)
{
	int x = ft_printf("%a");
	printf("\n");
	int y = printf("%");
	printf("\nx: %i", x);
	printf("\ny: %i", y);
	printf("\n");
}*/
