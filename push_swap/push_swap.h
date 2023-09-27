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

int		ft_atoi(const char *str);
int		is_error(char **arr, int count);
void	swap_a(int *arr, int count);
void	swap_b(int *arr, int count);
void	swap_ab(int *arr_a, int count_a, int *arr_b, int count_b);
void	push_a(int *arr_a, int *count_a, int *arr_b, int *count_b);
void	push_b(int *arr_a, int *count_a, int *arr_b, int *count_b);
void	rot_a(int *arr, int count);
void	rot_b(int *arr, int count);
void	rot_ab(int *arr_a, int count_a, int *arr_b, int count_b);
void	revrot_a(int *arr, int count);
void	revrot_b(int *arr, int count);
void	revrot_ab(int *arr_a, int count_a, int *arr_b, int count_b);

#endif
