/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_ops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ateow <ateow@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 06:16:25 by ateow             #+#    #+#             */
/*   Updated: 2023/09/27 06:16:26 by ateow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a(int *arr_a, int *count_a, int *arr_b, int *count_b)
{
	if (*count_a < 1)
	{
		write(1, "fail pa\n", 8);
		return ;
	}
	arr_b[*count_b] = arr_a[*count_a - 1];
	arr_a[*count_a - 1] = 99;
	*count_a = *count_a - 1;
	*count_b = *count_b + 1;
	write(1, "pa\n", 3);
}

void	push_b(int *arr_a, int *count_a, int *arr_b, int *count_b)
{
	if (*count_a < 1)
	{
		write(1, "fail pb\n", 8);
		return ;
	}
	arr_b[*count_b] = arr_a[*count_a - 1];
	arr_a[*count_a - 1] = 99;
	*count_a = *count_a - 1;
	*count_b = *count_b + 1;
	write(1, "pb\n", 3);
}
