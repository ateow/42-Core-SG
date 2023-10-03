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

void	sort_two(int *stack_a)
{
	if (stack_a[0] > stack_a[1])
		swap_a(stack_a, 2);
}

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

void	sort_four(int *stack_a, int count_a, int *stack_b, int count_b)
{
	if (is_smallest(stack_a, stack_a[0], 4) == 1 // if first number is smallest 
		|| is_largest(stack_a, stack_a[0], 4) == 1) // if first number is largest
	{
		push_a(stack_a, &count_a, stack_b, &count_b);
		sort_three(stack_a);
		push_b(stack_b, &count_b, stack_a, &count_a);
		if (is_largest(stack_a, stack_a[0], 4) == 1) // if first number is largest
			rot_up_a(stack_a, 4);
	}
	else if (is_largest(stack_a, stack_a[3], 4) == 1 // if last numner is largest
		|| is_smallest(stack_a, stack_a[3], 4) == 1) // if last number is smallest
	{
		rot_down_a(stack_a, 4);
		if (is_sorted(stack_a, count_a) == 1)
			return ;
		push_a(stack_a, &count_a, stack_b, &count_b);
		sort_three(stack_a);
		push_b(stack_b, &count_b, stack_a, &count_a);
		if (is_largest(stack_a, stack_a[0], 4) == 1) // if first number is largest
			rot_up_a(stack_a, 4);
	}
	else // if 1 and 4 are in the middle
	{
		rot_up_a(stack_a, 4);
		push_a(stack_a, &count_a, stack_b, &count_b);
		sort_three(stack_a);
		push_b(stack_b, &count_b, stack_a, &count_a);
		if (is_largest(stack_a, stack_a[0], 4) == 1)
			rot_up_a(stack_a, 4);
	}
}

void	sort_five(int *stack_a, int count_a, int *stack_b, int count_b)
{
	if (is_smallest(stack_a, stack_a[0], 5) == 1 // if first number is smallest 
		|| is_largest(stack_a, stack_a[0], 5) == 1) // if first number is largest
	{
		push_a(stack_a, &count_a, stack_b, &count_b);
		sort_four(stack_a, count_a, stack_b, count_b);
		push_b(stack_b, &count_b, stack_a, &count_a);
		if (is_largest(stack_a, stack_a[0], 5) == 1) // if first number is largest
			rot_up_a(stack_a, 5);
	}
	else if (is_largest(stack_a, stack_a[4], 5) == 1 // if last numner is largest
		|| is_smallest(stack_a, stack_a[4], 5) == 1) // if last number is smallest
	{
		rot_down_a(stack_a, 5);
		if (is_sorted(stack_a, count_a) == 1)
			return ;
		push_a(stack_a, &count_a, stack_b, &count_b);
		sort_four(stack_a, count_a, stack_b, count_b);
		push_b(stack_b, &count_b, stack_a, &count_a);
		if (is_largest(stack_a, stack_a[0], 5) == 1) // if first number is largest
			rot_up_a(stack_a, 5);
	}
	else // if 1 and 5 are in the middle
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
		push_a(stack_a, &count_a, stack_b, &count_b); 
		sort_four(stack_a, count_a, stack_b, count_b);
		push_b(stack_b, &count_b, stack_a, &count_a);
		if (is_largest(stack_a, stack_a[0], 5) == 1)
			rot_up_a(stack_a, 5);
	}
}

void	move_small_to_b(int *stack_a, int *count_a, int *stack_b, int *count_b, int chunk_size)
{
	int	i;
	int	j;
	int	k;
	int	*smallest_arr;

	smallest_arr = find_smallest_numbers(stack_a, *count_a, chunk_size);
	i = 0;
	k = 0;
	while (k != chunk_size)
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
					write(1, "YYYYYY smallest loop\n", 21);
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
	int	j;
	int	k;
	int	z;
	int	*largest_arr;

	largest_arr = find_largest_numbers(stack_b, *count_b, chunk_size);
	//write(1, "ZZZZZZ LARGEST\n", 16);
	//printf("\n>>>>> MOVE LARGE TO A START <<<<<<<\n");
	//printf("j:%d    stack_b[j]: %d    largest_arr[%d]: %d\n",j, stack_b[j], k,  largest_arr[k]);
	k = 0;
	z = 0;
	while (k != chunk_size)
	{
		i = 0;
		j = 0;
		while (j < *count_b && k < chunk_size)
		{		
			if (stack_b[j] == largest_arr[k])
			{
				i = j;
				break ;
			}
			j++;
		}
		//printf("j:%d    stack_b[j]: %d    largest_arr[%d]: %d\n",j, stack_b[j], k,  largest_arr[k]);
		while (stack_b[0] != largest_arr[k])
		{
			if (i <= (*count_b - i))
			{
				rot_up_b(stack_b, *count_b);
				write(1, "HERE>>\n", 7);
			}
			else if (i > (*count_b - i))
				rot_down_b(stack_b, *count_b);
			j--;
			if (stack_b[0] == largest_arr[k + 1] && z == 0)
			{
				push_b(stack_b, count_b, stack_a, count_a);
				z = 1;
				//printf("####### find 2\n");
			}
			if (stack_b[0] == largest_arr[k + 2] && z == 1)
			{
				push_b(stack_b, count_b, stack_a, count_a);
				z = 2;
				//printf("####### find 3\n");
			}
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

}

void	chuck_sort(int *stack_a, int count_a, int *stack_b, int count_b, int chunk_size)
{
	while (count_a != 0)
	{
		if (count_a < chunk_size)
			chunk_size = count_a;
		move_small_to_b(stack_a, &count_a, stack_b, &count_b, chunk_size);
	}
	while (count_b != 0)
	{
		if (count_b < chunk_size)
			chunk_size = count_b;
		move_large_to_a(stack_a, &count_a, stack_b, &count_b, chunk_size);
	}
	//return_to_a(stack_a, &count_a, stack_b, &count_b);
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
//CHECK ERROR
	if (argc == 1)
		return (0);
	if (is_error((argv + 1), count_a) == 1)
		return (0);
	if ((argc - 1) < 2)
		return (ft_atoi(argv[1]));
//INIT & SORT
	stack_a = malloc(sizeof(int) * (argc - 1));
	stack_b = malloc(sizeof(int) * (argc - 1));
	i = 0;
	while (i < count_a)
	{
		stack_a[i] = ft_atoi(argv[i + 1]);
		i++;
	}
// ALGO
	if (is_sorted(stack_a, count_a) == 0)
	{
		if (count_a == 2)
			sort_two(stack_a);
		else if (count_a == 3)
			sort_three(stack_a);
		else if (count_a == 4)
			sort_four(stack_a, count_a, stack_b, count_b);
		else if (count_a == 5)
			sort_five(stack_a, count_a, stack_b, count_b);
		else if (count_a == 500)
			chuck_sort(stack_a, count_a, stack_b, count_b, 70);
		else if (count_a == 100)
			chuck_sort(stack_a, count_a, stack_b, count_b, 20);
		else
			chuck_sort(stack_a, count_a, stack_b, count_b, count_a / 5);
	}
	free(stack_a);
	free(stack_b);
}
/*
	swap_a(stack_a, count_a);
	swap_b(stack_b, count_b);
	push_a(stack_a, &count_a, stack_b, &count_b);
	push_b(stack_b, &count_b, stack_a, &count_a);
	rot_up_a(stack_a, count_a);
	rot_up_b(stack_b, count_b);
	rot_up_ab(stack_a, count_a, stack_b, count_b);
	rot_down_a(stack_a, count_a);
	rot_down_b(stack_b, count_b);
	rot_down_ab(stack_a, count_a, stack_b, count_b);
	printf("%d\n", smallest_arr[0]);
	printf("%d\n", smallest_arr[1]);
	printf("%d\n", smallest_arr[2]);
	printf("%d\n", smallest_arr[3]);
	printf("%d\n", smallest_arr[4]);
	
	
void	return_to_a(int *stack_a, int *count_a, int *stack_b, int *count_b)
{
	int	i;
	int	l;

	i = *count_b;
	while (i > 0)
	{
		l = find_largest_index(stack_b, *count_b);
		//print_stack(stack_a, *count_a, stack_b, *count_b);
		if (l == 0)
		{
			push_b(stack_b, count_b, stack_a, count_a);
			i--;
		}
		else if (l <= (*count_b - l))
			rot_up_b(stack_b, *count_b);
		else if (l > (*count_b - l))
			rot_down_b(stack_b, *count_b);
	}
	//print_stack(stack_a, *count_a, stack_b, *count_b);
}

void	chuck_sort(int *stack_a, int count_a, int *stack_b, int count_b, int chunk_size)
{
	int	loop;

	loop = count_a / chunk_size;
	if ((count_a % chunk_size) != 0)
		loop++;
	while (count_a > 0)
		move_small_to_b(stack_a, &count_a, stack_b, &count_b, chunk_size);
	//print_stack(stack_a, count_a, stack_b, count_b);
	return_to_a(stack_a, &count_a, stack_b, &count_b);
}
*/
