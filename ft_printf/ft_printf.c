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

int	ft_definetype(char c, va_list args)
{
	if (c == 'i' || c == 'd')
		return (ft_pstring(ft_itoa(va_arg(args, int))));
	if (c == 'u')
		return (ft_pstring(ft_uitoa(va_arg(args, unsigned int))));
	if (c == 'c')
		return (ft_pchar(va_arg(args, int)));
	if (c == 's')
		return (ft_pstring(va_arg(args, char *)));
	if (c == 'x' || c == 'X')
		return (ft_phexanbr(va_arg(args, unsigned int), c));
	if (c == 'p')
		return (ft_ppointer(va_arg(args, unsigned long)));
	if (c == '%')
		return (ft_pchar('%'));
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
		if (input[i] != '%')
		{
			count = count + ft_pchar(input[i]);
			i++;
		}
		else if (input[i] == '%')
		{
			count = count + ft_definetype(input[i + 1], args);
			i = i + 2;
		}
	}
	va_end(args);
	return (count);
}
