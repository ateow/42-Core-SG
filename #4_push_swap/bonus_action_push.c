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

void	b_push_a(int *arr_a, int *count_a, int *arr_b, int *count_b)
{
	int	tmp;
	int	i;

	if (*count_a < 1)
		return ;
	tmp = arr_a[0];
	*count_a = *count_a - 1;
	i = 0;
	while (i < *count_a)
	{
		arr_a[i] = arr_a[i + 1];
		i++;
	}
	i = 1;
	*count_b = *count_b + 1;
	while (i < *count_b)
	{
		arr_b[*count_b - i] = arr_b[*count_b - 1 - i];
		i++;
	}
	arr_b[0] = tmp;
}

void	b_push_b(int *arr_a, int *count_a, int *arr_b, int *count_b)
{
	int	tmp;
	int	i;

	if (*count_a < 1)
		return ;
	tmp = arr_a[0];
	*count_a = *count_a - 1;
	i = 0;
	while (i < *count_a)
	{
		arr_a[i] = arr_a[i + 1];
		i++;
	}
	i = 1;
	*count_b = *count_b + 1;
	while (i < *count_b)
	{
		arr_b[*count_b - i] = arr_b[*count_b - 1 - i];
		i++;
	}
	arr_b[0] = tmp;
}
