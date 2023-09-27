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
#include <stdio.h>

void	print_stack(int *stack_a, int count_a, int *stack_b, int count_b)
{
	int	i;

	i = 0;
	printf("\na b\n- -\n");
	while (i < count_a || i < count_b)
	{
		if (i < count_a)
			printf("%d ", stack_a[count_a - 1 - i]);
		else
			printf("  ");
		if (i < count_b)
			printf("%d\n", stack_b[count_b - 1 - i]);
		else
			printf("\n");
		i++;
	}
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
	if (is_error((argv + 1), count_a) == 1)
		return (0);
	if ((argc -1) < 2)
		return (ft_atoi(argv[1]));
//INIT & SORT
	stack_a = malloc(sizeof(int) * (argc - 1));
	stack_b = malloc(sizeof(int) * (argc - 1));
	i = 0;
	while (i < count_a)
	{
		stack_a[i] = ft_atoi(argv[count_a - i]);
		i++;
	}
//PRINTING STACK
	print_stack(stack_a, count_a, stack_b, count_b);
//FREE
	free(stack_a);
	free(stack_b);
}
/*
push_b(stack_b, &count_b, stack_a, &count_a);
push_a(stack_a, &count_a, stack_b, &count_b);
push_a(stack_a, &count_a, stack_b, &count_b);
rot_b(stack_b, count_b);
push_a(stack_a, &count_a, stack_b, &count_b);
rot_b(stack_b, count_b);
push_a(stack_a, &count_a, stack_b, &count_b);
push_a(stack_a, &count_a, stack_b, &count_b);
rot_b(stack_b, count_b);
rot_ab(stack_a, count_a, stack_b, count_b);
swap_a(stack_a, count_a);
swap_b(stack_b, count_b);
swap_ab(stack_a, count_a, stack_b, count_b);
revrot_ab(stack_a, count_a, stack_b, count_b);*/
