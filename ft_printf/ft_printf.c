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

int	ft_printf(const char *format, ...)
{
	int	i;

	va_list(args);
	va_start(args, format);
	i = 0;
	while (format[i] != '\0')
	{
		if (format[i] != '%')
		{
			ft_putchar_fd(format[i], 1);
			i++;
		}
		if (format[i] == '%' && (format[i + 1] == 'i' || format[i + 1] == 'd'))
		{
			ft_putstr_fd(ft_itoa(va_arg(args, int)), 1);
			i = i + 2;
		}
		else if (format[i] == '%' && format[i + 1] == 'c')
		{
			ft_putchar_fd(va_arg(args, int), 1);
			i = i + 2;
		}
		else if (format[i] == '%' && format[i + 1] == 's')
		{
			ft_putstr_fd(va_arg(args, char *), 1);
			i = i + 2;
		}
	}
	va_end(args);
	return (0);
}

int	main(void)
{
	ft_printf("int: %i\nchar: %c\nstring: %s", 1, 'z', "hello world");
	ft_printf("\n");
	printf("int: %i\nchar: %c\nstring: %s", 1, 'z', "hello world");
}
