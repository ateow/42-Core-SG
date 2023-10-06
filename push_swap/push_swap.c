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

void	chuck_sort(t_list *stacks, int chunk_size)
{
	while (stacks->count_a != 0) //shed stack_a to stack_b
	{
		if (stacks->count_a < chunk_size) // if left over stack_a is less then chunksize, change chunksize to count a
			move_small_to_b(stacks, stacks->count_a);
		else
			move_small_to_b(stacks, chunk_size);
	}
	//print_stack(stacks->stack_a, stacks->count_a, stacks->stack_b, stacks->count_b);
	while (stacks->count_b != 0) // move stack_b back to stack_a 
	{
		if (stacks->count_b < chunk_size) // if left over stack_b is less then chunksize, change chunksize to count b
			move_large_to_a(stacks, stacks->count_b);
		else
			move_large_to_a(stacks, chunk_size);
	}
	//print_stack(stacks->stack_a, stacks->count_a, stacks->stack_b, stacks->count_b);
}

void	sorting_hat(t_list *stacks)
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
		chuck_sort(stacks, 65); // chunksize 65 gives best results
	else
		chuck_sort(stacks, stacks->count_a / 10); // estimate a chunk size if not determined
}

int	main(int argc, char **argv)
{
	t_list	*stacks;
	int		i;

	if (is_error((argv + 1), (argc - 1)) == 1 || (argc - 1) < 2)
		return (0);
	stacks = (t_list *)malloc(sizeof(t_list));
	stacks->count_a = argc - 1;
	stacks->count_b = 0;
	stacks->stack_a = malloc(sizeof(int) * (argc - 1));
	stacks->stack_b = malloc(sizeof(int) * (argc - 1));
	i = 0;
	while (i < stacks->count_a)
	{
		stacks->stack_a[i] = ft_atoi(argv[i + 1]); //convert string arr into int arr and store in struct stacka
		i++;
	}
	if (is_sorted(stacks->stack_a, stacks->count_a) == 0) //if not sorted, sort
		sorting_hat(stacks);
	free(stacks->stack_a);
	free(stacks->stack_b);
	free(stacks);
}
