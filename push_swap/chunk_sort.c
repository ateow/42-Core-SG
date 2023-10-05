/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ateow <ateow@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 14:16:34 by ateow             #+#    #+#             */
/*   Updated: 2023/10/04 14:16:37 by ateow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_small_to_b(MyStruct *stacks, int cs)
{
	int	i;
	int	k;
	int	*smallest_arr;

	smallest_arr = find_smallest_numbers(stacks->stack_a, stacks->count_a, cs);
	k = 0;
	while (k < cs)
	{
		i = 0;
		while (i < cs && k < cs)
		{
			if (stacks->stack_a[0] == smallest_arr[i])
			{
				push_a(stacks->stack_a, &(stacks->count_a),
					stacks->stack_b, &(stacks->count_b));
				k++;
				if (i < (cs / 2))
					rot_up_b(stacks->stack_b, stacks->count_b);
				i = -1;
			}
			i++;
		}
		rot_up_a(stacks->stack_a, stacks->count_a);
	}
	free(smallest_arr);
}

void	move_stack(MyStruct *stacks, int *largest_arr, int k)
{
	int	i;

	i = 0;
	while (i < stacks->count_b)
	{
		if (stacks->stack_b[i] == largest_arr[k])
			break ;
		i++;
	}
	if (stacks->stack_b[0] != largest_arr[k])
	{
		if (i <= (stacks->count_b - i))
			rot_up_b(stacks->stack_b, stacks->count_b);
		else if (i > (stacks->count_b - i))
			rot_down_b(stacks->stack_b, stacks->count_b);
	}
}

void	move_sec_third_largest(MyStruct *stacks,
	int *largest_arr, int *k, int *z)
{
	if (*z == 0 && stacks->stack_b[0] == largest_arr[*k + 1])
	{
		push_b(stacks->stack_b, &(stacks->count_b),
			stacks->stack_a, &(stacks->count_a));
		*z = 1;
	}
	if (*z == 1 && stacks->stack_b[0] == largest_arr[*k + 2])
	{
		push_b(stacks->stack_b, &(stacks->count_b),
			stacks->stack_a, &(stacks->count_a));
		*z = 2;
	}
}

void	move_largest(MyStruct *stacks, int *largest_arr, int *k, int *z)
{
	if (stacks->stack_b[0] == largest_arr[*k])
	{
		push_b(stacks->stack_b, &(stacks->count_b),
			stacks->stack_a, &(stacks->count_a));
		*k = *k + 1;
		if (*z == 1)
		{
			swap_a(stacks->stack_a, stacks->count_a);
			*k = *k + 1;
		}
		if (*z == 2)
		{
			swap_a(stacks->stack_a, stacks->count_a);
			rot_up_a(stacks->stack_a, stacks->count_a);
			swap_a(stacks->stack_a, stacks->count_a);
			rot_down_a(stacks->stack_a, stacks->count_a);
			*k = *k + 2;
		}
		*z = 0;
	}
}

void	move_large_to_a(MyStruct *stacks, int cs)
{
	int	k;
	int	z;
	int	*largest_arr;

	largest_arr = find_largest_numbers(stacks->stack_b, stacks->count_b, cs);
	k = 0;
	z = 0;
	while (k < cs && stacks->count_b >= 0)
	{
		move_stack(stacks, largest_arr, k);
		if (((k + 1 < cs) && z == 0) || ((k + 2 < cs) && z == 1))
			move_sec_third_largest(stacks, largest_arr, &k, &z);
		move_largest(stacks, largest_arr, &k, &z);
	}
	free(largest_arr);
}
