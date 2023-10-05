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

void	chuck_sort(MyStruct *stacks, int chunk_size)
{
	while (stacks->count_a != 0)
	{
		if (stacks->count_a < chunk_size)
			move_small_to_b(stacks, stacks->count_a);
		else
			move_small_to_b(stacks, chunk_size);
	}
	while (stacks->count_b != 0)
	{
		if (stacks->count_b < chunk_size)
			move_large_to_a(stacks, stacks->count_b);
		else
			move_large_to_a(stacks, chunk_size);
	}
}

void	sorting_hat(MyStruct *stacks)
{
	if (stacks->count_a == 2)
	{
		if (stacks->stack_a[0] > stacks->stack_a[1])
			swap_a(stacks->stack_a, 2);
	}
	else if (stacks->count_a == 3)
		sort_three(stacks->stack_a);
	else if (stacks->count_a == 4)
		sort_four(stacks->stack_a, stacks->count_a,
			stacks->stack_b, stacks->count_b);
	else if (stacks->count_a == 5)
		sort_five(stacks->stack_a, stacks->count_a,
			stacks->stack_b, stacks->count_b);
	else if (stacks->count_a < 20)
		chuck_sort(stacks, 4);
	else if (stacks->count_a < 200)
		chuck_sort(stacks, 20);
	else if (stacks->count_a < 600)
		chuck_sort(stacks, 65);
	else
		chuck_sort(stacks, stacks->count_a / 10);
}

int	main(int argc, char **argv)
{
	MyStruct	*stacks;
	int			i;

	stacks = (MyStruct *)malloc(sizeof(MyStruct));
	stacks->count_a = argc - 1;
	stacks->count_b = 0;
	if ((argc - 1) < 2 || is_error((argv + 1), stacks->count_a) == 1)
		return (0);
	stacks->stack_a = malloc(sizeof(int) * (argc - 1));
	stacks->stack_b = malloc(sizeof(int) * (argc - 1));
	i = 0;
	while (i < stacks->count_a)
	{
		stacks->stack_a[i] = ft_atoi(argv[i + 1]);
		i++;
	}
	if (is_sorted(stacks->stack_a, stacks->count_a) == 0)
		sorting_hat(stacks);
	free(stacks->stack_a);
	free(stacks->stack_b);
	free(stacks);
}
