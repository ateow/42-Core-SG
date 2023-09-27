/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   revrot_ops.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ateow <ateow@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 10:43:44 by ateow             #+#    #+#             */
/*   Updated: 2023/09/27 10:43:45 by ateow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	revrot_a(int *arr, int count)
{
	int	tmp;
	int	i;

	if (count < 2)
	{
		write(1, "fail rra\n", 9);
		return ;
	}
	i = 0;
	tmp = arr[0];
	while (i < count)
	{
		arr[i] = arr[i + 1];
		i++;
	}
	arr[count - 1] = tmp;
	write(1, "rra\n", 4);
}

void	revrot_b(int *arr, int count)
{
	int	tmp;
	int	i;

	if (count < 2)
	{
		write(1, "fail rrb\n", 9);
		return ;
	}
	i = 0;
	tmp = arr[0];
	while (i < count)
	{
		arr[i] = arr[i + 1];
		i++;
	}
	arr[count - 1] = tmp;
	write(1, "rrb\n", 4);
}

void	revrot_ab(int *arr_a, int count_a, int *arr_b, int count_b)
{
	int	tmp;
	int	i;

	if (count_a < 2 || count_b < 2)
	{
		write(1, "fail rrr\n", 9);
		return ;
	}
	i = 0;
	tmp = arr_a[0];
	while (i < count_a)
	{
		arr_a[i] = arr_a[i + 1];
		i++;
	}
	arr_a[count_a - 1] = tmp;
	i = 0;
	tmp = arr_b[0];
	while (i < count_b)
	{
		arr_b[i] = arr_b[i + 1];
		i++;
	}
	arr_b[count_b - 1] = tmp;
	write(1, "rrr\n", 4);
}
