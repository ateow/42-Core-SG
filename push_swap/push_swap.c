/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ateow <ateow@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 03:19:09 by ateow             #+#    #+#             */
/*   Updated: 2023/09/27 03:19:11 by ateow            ###   ########.fr       */
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

void	sorting_hat(int *stack_a, int count_a, int *stack_b, int count_b)
{
	if (count_a == 2)
		sort_two(stack_a);
	else if (count_a == 3)
		sort_three(stack_a);
	else if (count_a == 4)
		sort_four(stack_a, count_a, stack_b, count_b);
	else if (count_a == 5)
		sort_five(stack_a, count_a, stack_b, count_b);
	else if (count_a < 20)
		chuck_sort(stack_a, count_a, stack_b, count_b, 4);
	else if (count_a < 200)
		chuck_sort(stack_a, count_a, stack_b, count_b, 20);
	else if (count_a < 600)
		chuck_sort(stack_a, count_a, stack_b, count_b, 65);
	else
		chuck_sort(stack_a, count_a, stack_b, count_b, count_a / 10);
}

int	main(int argc, char **argv)
{
	int	*stack_a;
	int	*stack_b;
	int	count_a;
	int	count_b;
	int	i;

	count_a = argc - 1;
	count_b = 0;
	if ((argc - 1) < 2 || is_error((argv + 1), count_a) == 1)
		return (0);
	stack_a = malloc(sizeof(int) * (argc - 1));
	stack_b = malloc(sizeof(int) * (argc - 1));
	i = 0;
	while (i < count_a)
	{
		stack_a[i] = ft_atoi(argv[i + 1]);
		i++;
	}
	if (is_sorted(stack_a, count_a) == 0)
		sorting_hat(stack_a, count_a, stack_b, count_b);
	free(stack_a);
	free(stack_b);
}
/*
void	move_large_to_a(int *stack_a, int *count_a, 
int *stack_b, int *count_b, int chunk_size)
{
	int	i;
	int	j;
	int	k;
	int	z;
	int	*largest_arr;

	largest_arr = find_largest_numbers(stack_b, *count_b, chunk_size);
	k = 0;
	z = 0;
	while (k < chunk_size && *count_b != 0)
	{
		i = 0;
		j = 0;
		while (j < *count_b)
		{		
			if (stack_b[j] == largest_arr[k])
			{
				i = j;
				break ;
			}
			j++;
		}
		while (stack_b[0] != largest_arr[k])
		{
			if (stack_b[0] == largest_arr[k + 1] && z == 0 && (chunk_size - k) > 1)
			{
				push_b(stack_b, count_b, stack_a, count_a);
				z = 1;
				i--;
			}
			if (stack_b[0] == largest_arr[k + 2] && z == 1 && (chunk_size - k) > 2)
			{
				push_b(stack_b, count_b, stack_a, count_a);
				z = 2;
				i--;
			}
			if (stack_b[0] == largest_arr[k])
				break;
			//printf("countb:%d    i:%d\n", *count_b, i);			
			if (i <= (*count_b - i))
			{
				rot_up_b(stack_b, *count_b);
			}
			else if (i > (*count_b - i))
				rot_down_b(stack_b, *count_b);
		}
		if (stack_b[0] == largest_arr[k])			
		{
			push_b(stack_b, count_b, stack_a, count_a);
			k++;
			if (z == 1)
			{
				swap_a(stack_a, *count_a);
				k++;
				z = 0;
			}
			if (z == 2)
			{
				swap_a(stack_a, *count_a);
				rot_up_a(stack_a, *count_a);
				swap_a(stack_a, *count_a);
				rot_down_a(stack_a, *count_a);
				k = k + 2;
				z = 0;
			}
		}
	}
	free(largest_arr);
}*/
