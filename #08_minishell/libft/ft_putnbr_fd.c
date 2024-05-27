/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cooi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 18:34:06 by cooi              #+#    #+#             */
/*   Updated: 2023/09/07 18:37:39 by cooi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	tmp;

	tmp = n;
	if (fd < 0)
		return ;
	if (tmp < 0)
	{
		write(fd, "-", 1);
		tmp *= -1;
	}
	if (tmp >= 10)
	{
		ft_putnbr_fd(tmp / 10, fd);
		ft_putnbr_fd(tmp % 10, fd);
	}
	else
	{
		tmp += '0';
		write(fd, &tmp, 1);
	}
}
