/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_below_five.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ateow <ateow@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 14:18:36 by ateow             #+#    #+#             */
/*   Updated: 2023/10/04 14:18:39 by ateow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(int *stack_a)
{
	if (is_largest(stack_a, stack_a[2], 3) == 1) // if last number is the biggest
	{
		if (stack_a[0] > stack_a[1])
			swap_a(stack_a, 3);
	}
	else if (is_smallest(stack_a, stack_a[2], 3) == 1) // if last number is the smallest
	{
		if (stack_a[0] > stack_a[1])
			swap_a(stack_a, 3);
		rot_down_a(stack_a, 3);
	}
	else
	{
		if (stack_a[0] < stack_a[1])
			swap_a(stack_a, 3);
		rot_up_a(stack_a, 3);
	}
}

void	push_sort_push(int *stack_a, int *count_a, int *stack_b, int *count_b)
{
	push_a(stack_a, count_a, stack_b, count_b);
	if (*count_a == 3)
		sort_three(stack_a);
	else if (*count_a == 4)
		sort_four(stack_a, *count_a, stack_b, *count_b);
	push_b(stack_b, count_b, stack_a, count_a);
}

void	sort_four(int *stack_a, int count_a, int *stack_b, int count_b)
{
	if (is_smallest(stack_a, stack_a[0], 4) == 1 // if first number is smallest 
		|| is_largest(stack_a, stack_a[0], 4) == 1) // if first number is largest
	{
		push_sort_push(stack_a, &count_a, stack_b, &count_b);
		if (is_largest(stack_a, stack_a[0], 4) == 1) // if first number is largest
			rot_up_a(stack_a, 4);
	}
	else if (is_largest(stack_a, stack_a[3], 4) == 1 // if last numner is largest
		|| is_smallest(stack_a, stack_a[3], 4) == 1) // if last number is smallest
	{
		rot_down_a(stack_a, 4);
		if (is_sorted(stack_a, count_a) == 1)
			return ;
		push_sort_push(stack_a, &count_a, stack_b, &count_b);
		if (is_largest(stack_a, stack_a[0], 4) == 1) // if first number is largest
			rot_up_a(stack_a, 4);
	}
	else // if 1 and 4 are in the middle
	{
		rot_up_a(stack_a, 4);
		push_sort_push(stack_a, &count_a, stack_b, &count_b);
		if (is_largest(stack_a, stack_a[0], 4) == 1)
			rot_up_a(stack_a, 4);
	}
}

void	one_five_in_middle(int *stack_a, int count_a, int *stack_b, int count_b)
{
	if (is_smallest(stack_a, stack_a[1], 5) == 1
		|| is_largest(stack_a, stack_a[1], 5) == 1) // if second number is not smallest, can skip rot_downx2
		rot_up_a(stack_a, 5);
	else if (is_smallest(stack_a, stack_a[3], 5) == 1 // if forth number is smallest 
		|| is_largest(stack_a, stack_a[3], 5) == 1) // or if forth number is largest
	{
		rot_down_a(stack_a, 5); 
		rot_down_a(stack_a, 5);
	}
	if (is_sorted(stack_a, count_a) == 1)
		return ;
	push_sort_push(stack_a, &count_a, stack_b, &count_b);
	if (is_largest(stack_a, stack_a[0], 5) == 1)
		rot_up_a(stack_a, 5);
}

void	sort_five(int *stack_a, int count_a, int *stack_b, int count_b)
{
	if (is_smallest(stack_a, stack_a[0], 5) == 1 // if first number is smallest 
		|| is_largest(stack_a, stack_a[0], 5) == 1) // if first number is largest
	{
		push_sort_push(stack_a, &count_a, stack_b, &count_b);
		if (is_largest(stack_a, stack_a[0], 5) == 1) // if first number is largest
			rot_up_a(stack_a, 5);
	}
	else if (is_largest(stack_a, stack_a[4], 5) == 1 // if last numner is largest
		|| is_smallest(stack_a, stack_a[4], 5) == 1) // if last number is smallest
	{
		rot_down_a(stack_a, 5);
		if (is_sorted(stack_a, count_a) == 1)
			return ;
		push_sort_push(stack_a, &count_a, stack_b, &count_b);
		if (is_largest(stack_a, stack_a[0], 5) == 1) // if first number is largest
			rot_up_a(stack_a, 5);
	}
	else // if 1 and 5 are in the middle
		one_five_in_middle(stack_a, count_a, stack_b, count_b);
}
