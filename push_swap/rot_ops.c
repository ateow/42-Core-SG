/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_ops.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ateow <ateow@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 06:56:04 by ateow             #+#    #+#             */
/*   Updated: 2023/09/27 06:56:06 by ateow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rot_a(int *arr, int count)
{
	int	tmp;
	int	i;

	if (count < 2)
	{
		write(1, "fail ra\n", 8);
		return ;
	}
	i = 0;
	tmp = arr[count - 1];
	while (i < count)
	{
		arr[count - 1 - i] = arr[count - 1 - i - 1];
		i++;
	}
	arr[0] = tmp;
	write(1, "ra\n", 3);
}

void	rot_b(int *arr, int count)
{
	int	tmp;
	int	i;

	if (count < 2)
	{
		write(1, "fail rb\n", 8);
		return ;
	}
	i = 0;
	tmp = arr[count - 1];
	while (i < count)
	{
		arr[count - 1 - i] = arr[count - 1 - i - 1];
		i++;
	}
	arr[0] = tmp;
	write(1, "rb\n", 3);
}

void	rot_ab(int *arr_a, int count_a, int *arr_b, int count_b)
{
	int	tmp;
	int	i;

	if (count_a < 2 || count_b < 2)
	{
		write(1, "fail rr\n", 8);
		return ;
	}
	i = 0;
	tmp = arr_a[count_a - 1];
	while (i < count_a)
	{
		arr_a[count_a - 1 - i] = arr_a[count_a - 1 - i - 1];
		i++;
	}
	arr_a[0] = tmp;
	i = 0;
	tmp = arr_b[count_b - 1];
	while (i < count_b)
	{
		arr_b[count_b - 1 - i] = arr_b[count_b - 1 - i - 1];
		i++;
	}
	arr_b[0] = tmp;
	write(1, "rr\n", 3);
}
