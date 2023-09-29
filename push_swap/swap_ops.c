/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_ops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ateow <ateow@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 04:42:40 by ateow             #+#    #+#             */
/*   Updated: 2023/09/27 04:42:42 by ateow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(int *arr, int count)
{
	int	tmp;

	if (count < 2)
	{
		write(1, "fail sa\n", 8);
		return ;
	}
	tmp = arr[0];
	arr[0] = arr[1];
	arr[1] = tmp;
	write(1, "sa\n", 3);
}

void	swap_b(int *arr, int count)
{
	int	tmp;

	if (count < 2)
	{
		write(1, "fail sa\n", 8);
		return ;
	}
	tmp = arr[0];
	arr[0] = arr[1];
	arr[1] = tmp;
	write(1, "sb\n", 3);
}

void	swap_ab(int *arr_a, int count_a, int *arr_b, int count_b)
{
	int	tmp;

	if (count_a < 2 || count_b < 2)
	{
		write(1, "fail ss\n", 8);
		return ;
	}
	tmp = arr_a[0];
	arr_a[0] = arr_a[1];
	arr_a[1] = tmp;
	tmp = arr_b[0];
	arr_b[0] = arr_b[1];
	arr_b[1] = tmp;
	write(1, "ss\n", 3);
}
