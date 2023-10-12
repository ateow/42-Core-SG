/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ateow <ateow@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 03:20:42 by ateow             #+#    #+#             */
/*   Updated: 2023/09/27 03:20:44 by ateow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int	*stack_a;
	int	*stack_b;
	int	count_a;
	int	count_b;
}	t_list;

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

size_t		ft_strlen(const char *s);
int			get_index(const char *s, int c);
char		*ft_strjoin(char *s1, char *s2);
char		*ft_substr(char *s, unsigned int start, size_t len);
char		*get_next_line(int fd);

int			ft_pchar(char c);
int			ft_pstring(char *s);
int			ft_uitoa(int n);
int			ft_phexanbr(unsigned int nbr, char c);
int			ft_ppointer(unsigned long nbr);
int			ft_itoa(int n);
int			ft_printf(const char *input, ...);
int			ft_atoi(const char *str);

void		sort_two(int *stack_a);
void		sort_three(int *stack_a);
void		sort_four(int *stack_a, int count_a, int *stack_b, int count_b);
void		sort_five(int *stack_a, int count_a, int *stack_b, int count_b);

void		chuck_sort(t_list *stacks, int chunk_size);
void		move_stack(t_list *stacks, int *largest_arr, int k);
void		move_sec_third_largest(t_list *stacks,
				int *largest_arr, int *k, int *z);
void		move_largest(t_list *stacks, int *largest_arr, int *k, int *z);
void		move_large_to_a(t_list *stacks, int cs);
void		move_small_to_b(t_list *stacks, int cs);

void		swap_a(int *arr, int count);
void		swap_b(int *arr, int count);
void		swap_ab(int *arr_a, int count_a, int *arr_b, int count_b);
void		push_a(int *arr_a, int *count_a, int *arr_b, int *count_b);
void		push_b(int *arr_a, int *count_a, int *arr_b, int *count_b);
void		rot_up_a(int *arr, int count);
void		rot_up_b(int *arr, int count);
void		rot_up_ab(int *arr_a, int count_a, int *arr_b, int count_b);
void		rot_down_a(int *arr, int count);
void		rot_down_b(int *arr, int count);
void		rot_down_ab(int *arr_a, int count_a, int *arr_b, int count_b);

void		b_swap_a(int *arr, int count);
void		b_swap_b(int *arr, int count);
void		b_swap_ab(int *arr_a, int count_a, int *arr_b, int count_b);
void		b_push_a(int *arr_a, int *count_a, int *arr_b, int *count_b);
void		b_push_b(int *arr_a, int *count_a, int *arr_b, int *count_b);
void		b_rot_up_a(int *arr, int count);
void		b_rot_up_b(int *arr, int count);
void		b_rot_up_ab(int *arr_a, int count_a, int *arr_b, int count_b);
void		b_rot_down_a(int *arr, int count);
void		b_rot_down_b(int *arr, int count);
void		b_rot_down_ab(int *arr_a, int count_a, int *arr_b, int count_b);

int			str_cmp(char *s1, char *s2);
int			is_error(char **arr, int count);
int			is_sorted(int *arr, int count);
int			is_smallest(int *arr, int nbr, int count);
int			is_largest(int *arr, int nbr, int count);
int			*find_smallest_numbers(int *arr, int count, int x);
int			*find_largest_numbers(int *arr, int count, int x);

#endif
