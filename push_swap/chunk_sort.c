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

void	move_small_to_b(int *stack_a, int *count_a, int *stack_b, int *count_b, int chunk_size)
{
	int	i;
	int	j;
	int	k;
	int	*smallest_arr;

	smallest_arr = find_smallest_numbers(stack_a, *count_a, chunk_size);
	i = 0;
	k = 0;
	while (k < chunk_size)
	{
		//printf("i:%d\n",i);
		j = 0;
		while (j < chunk_size && k < chunk_size)
		{
			//printf("j:%d\n",j);
		//	printf("stack_a[0]: %d    smallest_arr[j]: %d\n",stack_a[0],  smallest_arr[j]);
			if (stack_a[0] == smallest_arr[j])
			{
			//	printf("found same\n");
				push_a(stack_a, count_a, stack_b, count_b);
				k++;
				if (j < (chunk_size / 2))
				{
					rot_up_b(stack_b, *count_b);
					//write(1, "YYYYYY smallest loop\n", 21);
				}
				j = -1;
			}
			j++;
		}
		rot_up_a(stack_a, *count_a);
		//printf(">>>>>>>>>>>>>> i : %d\n",i);
		i++;
	}
	free(smallest_arr);
	//print_stack(stack_a, *count_a, stack_b, *count_b);
}

void	move_large_to_a(int *stack_a, int *count_a, int *stack_b, int *count_b, int chunk_size)
{
	int	i;
	int	k;
	int	z;
	int	*largest_arr;

	largest_arr = find_largest_numbers(stack_b, *count_b, chunk_size);
	k = 0;
	z = 0;
	while (k < chunk_size && *count_b >= 0)
	{
		i = 0;
		while (i < *count_b)
		{		
			if (stack_b[i] == largest_arr[k])
				break ;
			i++;
		}

		if (stack_b[0] != largest_arr[k])
		{
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
			}
			if (z == 2)
			{
				swap_a(stack_a, *count_a);
				rot_up_a(stack_a, *count_a);
				swap_a(stack_a, *count_a);
				rot_down_a(stack_a, *count_a);
				k = k + 2;
			}
			z = 0;
		}
		
		if ((k + 1 < chunk_size) && z == 0 && stack_b[0] == largest_arr[k + 1])
		{
			push_b(stack_b, count_b, stack_a, count_a);
			z = 1;
		}

		if ((k + 2 < chunk_size) && z == 1 && stack_b[0] == largest_arr[k + 2])
		{
			push_b(stack_b, count_b, stack_a, count_a);
			z = 2;
		}


	}
	free(largest_arr);
}

void	chuck_sort(int *stack_a, int count_a, int *stack_b, int count_b, int chunk_size)
{
	while (count_a != 0)
	{
		if (count_a < chunk_size)
			move_small_to_b(stack_a, &count_a, stack_b, &count_b, count_a);
		else
			move_small_to_b(stack_a, &count_a, stack_b, &count_b, chunk_size);
	}
	while (count_b != 0)
	{
		if (count_b < chunk_size)
			move_large_to_a(stack_a, &count_a, stack_b, &count_b, count_b);
		else
			move_large_to_a(stack_a, &count_a, stack_b, &count_b, chunk_size);
	}
}
