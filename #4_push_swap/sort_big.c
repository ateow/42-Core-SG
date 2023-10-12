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

void	move_small_to_b(t_list *stacks, int cs) // main function to shed A to B
{
	int	i;
	int	k;
	int	*smallest_arr;

	k = 0;
	smallest_arr = find_smallest_numbers(stacks->stack_a, stacks->count_a, cs); // arrange numbers from smallest to biggest
	while (k < cs) // only exit when chunk size is reached
	{
		i = 0;
		while (i < cs && k < cs) // check if current stack_a[0] belongs to any number in smallest arr
		{
			if (stacks->stack_a[0] == smallest_arr[i]) // if found in any of the number in the smallest arr, push to stack B  
			{
				push_a(stacks->stack_a, &(stacks->count_a),
					stacks->stack_b, &(stacks->count_b));
				k++;
				if (i < (cs / 2)) // this is to further optimise. can split pushed smallest_arr into a smaller half and a bigger half
					rot_up_b(stacks->stack_b, stacks->count_b); //in stack_b, if the pushed value belong to the smaller half in the smallest_arr, rot up B
				i = -1;
			}
			i++;
		}
		rot_up_a(stacks->stack_a, stacks->count_a); // rot stack_a up if current stack_a[0] not in smallest list
	}
	free(smallest_arr);
}

void	move_stack(t_list *stacks, int *largest_arr, int k) //rot up or down depends on where the largest index is
{
	int	i;

	i = 0;
	while (i < stacks->count_b) // identify the index whereby the largest value is in stack_b
	{
		if (stacks->stack_b[i] == largest_arr[k])
			break ;
		i++;
	}
	if (stacks->stack_b[0] != largest_arr[k])
	{
		if (i <= (stacks->count_b - i)) //rot up if index is closer to top
			rot_up_b(stacks->stack_b, stacks->count_b);
		else if (i > (stacks->count_b - i))
			rot_down_b(stacks->stack_b, stacks->count_b); //rot down if index is closer to bottom
	}
}

void	move_sec_third_largest(t_list *stacks,
	int *largest_arr, int *k, int *z) // do not tagged k here because we dont want to change the goal of finding largest. 
{
	if (*z == 1 && stacks->stack_b[0] == largest_arr[*k + 2]) // push in third largest only if second largest have been found previously and pushed
	{
		push_b(stacks->stack_b, &(stacks->count_b),
			stacks->stack_a, &(stacks->count_a));
		*z = 2; // assign 2 to incidate that we have pushed both second and third largest
	}
	if (*z == 0 && stacks->stack_b[0] == largest_arr[*k + 1]) // push in second largest, regardless if it has found third
	{
		push_b(stacks->stack_b, &(stacks->count_b),
			stacks->stack_a, &(stacks->count_a));
		*z = 1; // z 1 is to incidate we only found 2nd largest
	}
}

void	move_largest(t_list *stacks, int *largest_arr, int *k, int *z)
{
	if (stacks->stack_b[0] == largest_arr[*k]) //k is always the index of the largest number
	{
		push_b(stacks->stack_b, &(stacks->count_b),
			stacks->stack_a, &(stacks->count_a)); // push to A if current stack_b[0] is largest
		*k = *k + 1;
		if (*z == 1) // if we previously found and pushed in a second largest number in stack A, swap with largest
		{
			swap_a(stacks->stack_a, stacks->count_a);
			*k = *k + 1; // k is tagged here at the end and not tagged to push because we dont want change the algo goal to find the largest
		}
		if (*z == 2) // if we previously found pushed in both second and third largest, need to sort these 3 numbers at stackA
		{
			swap_a(stacks->stack_a, stacks->count_a);
			rot_up_a(stacks->stack_a, stacks->count_a);
			swap_a(stacks->stack_a, stacks->count_a);
			rot_down_a(stacks->stack_a, stacks->count_a);
			*k = *k + 2; // k is tagged here at the end and not tagged to push because we dont want change the algo goal to find the largest
		}
		*z = 0;
	}
}

void	move_large_to_a(t_list *stacks, int cs) // main function to move B to A
{
	int	k;
	int	z;
	int	*largest_arr;

	k = 0;
	z = 0;
	largest_arr = find_largest_numbers(stacks->stack_b, stacks->count_b, cs); //create arr with numbers from large to small. arr size is chunksize 
	while (k < cs && stacks->count_b >= 0) //only exit when you pushed all number largest_arr.
	{
		move_largest(stacks, largest_arr, &k, &z); // if current stack_b[0] is largest, push to stack_a
		if (((k + 1 < cs) && z == 0) || ((k + 2 < cs) && z == 1)) //if k is last or 2nd last, dont allow 2nd or 3rd largest push to execute. and also to check if there are still leftover arr for 2nd and 3rd push. or else, we will read into memory that we cant access. for example, if left one number in arr, and we do k+2
			move_sec_third_largest(stacks, largest_arr, &k, &z); // if current stack_b[0] is 2nd or 3rd largest, push to stack
		move_stack(stacks, largest_arr, k); //if current stack_b[0] not largest, rot up or rot down depending on position
	}
	free(largest_arr);
}
