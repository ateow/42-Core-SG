/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ateow <ateow@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 09:47:50 by ateow             #+#    #+#             */
/*   Updated: 2023/10/06 09:47:53 by ateow            ###   ########.fr       */
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

int	str_cmp(char *s1, char *s2)
{
	unsigned int	i;

	i = 0;
	while (s1[i] != '\0' || s2[i] != '\0')
	{
		if (s1[i] != s2[i])
		{
			return (s1[i] - s2[i]);
		}
		i++;
	}
	return (0);
}

void	perform_action(t_list *s, char *line, int *x)
{
	if (str_cmp(line, "sa\n") == 0)
		b_swap_a(s->stack_a, s->count_a);
	else if (str_cmp(line, "sb\n") == 0)
		b_swap_b(s->stack_b, s->count_b);
	else if (str_cmp(line, "ss\n") == 0)
		b_swap_ab(s->stack_a, s->count_a, s->stack_b, s->count_b);
	else if (str_cmp(line, "ra\n") == 0)
		b_rot_up_a(s->stack_a, s->count_a);
	else if (str_cmp(line, "rb\n") == 0)
		b_rot_up_b(s->stack_b, s->count_b);
	else if (str_cmp(line, "rr\n") == 0)
		b_rot_up_ab(s->stack_a, s->count_a, s->stack_b, s->count_b);
	else if (str_cmp(line, "rra\n") == 0)
		b_rot_down_a(s->stack_a, s->count_a);
	else if (str_cmp(line, "rrb\n") == 0)
		b_rot_down_b(s->stack_b, s->count_b);
	else if (str_cmp(line, "rrr\n") == 0)
		b_rot_down_ab(s->stack_a, s->count_a, s->stack_b, s->count_b);
	else if (str_cmp(line, "pa\n") == 0)
		b_push_b(s->stack_b, &(s->count_b), s->stack_a, &(s->count_a));
	else if (str_cmp(line, "pb\n") == 0)
		b_push_a(s->stack_a, &(s->count_a), s->stack_b, &(s->count_b));
	else
		*x = 1;
}

void	check_input(t_list *s, int c)
{
	int		i;
	int		x;
	char	*line;

	x = 0;
	i = 0;
	while (i == 0 && x == 0)
	{
		line = get_next_line(0);
		if (line == NULL)
		{
			free(line);
			break ;
		}
		else
			perform_action(s, line, &x);
		free(line);
	}
	if (x != 0)
		ft_printf("%s", "Error\n");
	else if (is_sorted(s->stack_a, s->count_a) == 1 && s->count_a == c)
		ft_printf("%s", "OK\n");
	else
		ft_printf("%s", "KO\n");
}

int	main(int argc, char **argv)
{
	t_list	*stacks;
	int		i;

	if (is_error((argv + 1), (argc - 1)) == 1)
		return (0);
	stacks = (t_list *)malloc(sizeof(t_list));
	stacks->count_a = argc - 1;
	stacks->count_b = 0;
	stacks->stack_a = malloc(sizeof(int) * (argc - 1));
	stacks->stack_b = malloc(sizeof(int) * (argc - 1));
	i = 0;
	while (i < stacks->count_a)
	{
		stacks->stack_a[i] = ft_atoi(argv[i + 1]);
		i++;
	}
	check_input(stacks, (argc - 1));
	free(stacks->stack_a);
	free(stacks->stack_b);
	free(stacks);
}
