/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ateow <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 16:05:41 by ateow             #+#    #+#             */
/*   Updated: 2023/09/30 16:05:43 by ateow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_smallest(int *arr, int nbr, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		if (nbr > arr[i])
			return (0);
		i++;
	}
	return (1);
}

int	is_largest(int *arr, int nbr, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		if (nbr < arr[i])
			return (0);
		i++;
	}
	return (1);
}

int	*nbr_dup(int *arr, int count)
{
	int	i;
	int	*arrdup;

	arrdup = malloc(sizeof(int) * count);
	i = 0;
	while (i < count)
	{
		arrdup[i] = arr[i];
		i++;
	}
	return (arrdup);
}

int	*find_smallest_numbers(int *arr, int count, int x)
{
	int	i;
	int	j;
	int	y;
	int	*arrdup;
	int	*res;

	arrdup = nbr_dup(arr, count);
	res = malloc(sizeof(int) * x);
	y = 0;
	while (y < x)
	{
		i = 0;
		j = 0;
		while (i < count)
		{
			if (arrdup[j] > arrdup[i])
				j = i;
			i++;
		}
		res[y] = arrdup[j];
		arrdup[j] = 2147483647;
		y++;
	}
	free (arrdup);
	return (res);
}

int	*find_largest_numbers(int *arr, int count, int x)
{
	int	i;
	int	j;
	int	y;
	int	*arrdup;
	int	*res;

	arrdup = nbr_dup(arr, count);
	res = malloc(sizeof(int) * x);
	y = 0;
	while (y < x)
	{
		i = 0;
		j = 0;
		while (i < count)
		{
			if (arrdup[j] < arrdup[i])
				j = i;
			i++;
		}
		res[y] = arrdup[j];
		arrdup[j] = -2147483648;
		y++;
	}
	free (arrdup);
	return (res);
}
/*
void	print_stack(int *stack_a, int count_a, int *stack_b, int count_b)
{
	int	i;

	i = 0;
	ft_printf("\na b\n- -\n");
	while (i < count_a || i < count_b)
	{
		if (i < count_a)
			ft_printf("%d ", stack_a[i]);
		else
			ft_printf("  ");
		if (i < count_b)
			ft_printf("%d\n", stack_b[i]);
		else
			ft_printf("\n");
		i++;
	}
}*/
