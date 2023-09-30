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

int	is_sorted(int *arr, int count)
{
	int	i;

	i = 0;
	while (i < (count - 1))
	{
		if (arr[i] > arr[i + 1])
			return (0);
		i++;
	}
	return (1);
}

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
			printf("  ");
		if (i < count_b)
			ft_printf("%d\n", stack_b[i]);
		else
			ft_printf("\n");
		i++;
	}
}
