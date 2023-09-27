/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ateow <ateow@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 11:41:04 by ateow             #+#    #+#             */
/*   Updated: 2023/09/27 11:41:06 by ateow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long	ft_atol(const char *str)
{
	long	res;
	int		i;
	int		n;

	i = 0;
	res = 0;
	n = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			n = -1;
		i++;
	}
	while ((str[i] >= '0' && str[i] <= '9') && str[i] != '\0')
	{
		res = (res * 10) + (str[i] - '0');
		i++;
	}
	return (res * n);
}

static int	is_outof_int(char **arr, int count)
{
	int		i;
	long	n;

	i = 0;
	while (i < count)
	{
		n = ft_atol(arr[i]);
		if (n > 2147483647 || n < -2147483648)
			return (1);
		i++;
	}
	return (0);
}

static int	is_dup(char **arr, int count)
{
	int	i;
	int	j;

	i = 0;
	while (i < count)
	{
		j = i + 1;
		while (j < count)
		{
			if (ft_atoi(arr[i]) == ft_atoi(arr[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static int	is_not_int(char **arr, int count)
{
	int	i;
	int	j;

	i = 0;
	while (i < count)
	{
		j = 0;
		if (arr[i][0] == '-')
			j++;
		while (arr[i][j] != '\0')
		{
			if (arr[i][j] < '0' || arr[i][j] > '9')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	is_error(char **arr, int count)
{
	if (is_not_int(arr, count) == 1
		|| is_outof_int(arr, count) == 1
		|| is_dup(arr, count) == 1)
	{
		write(1, "error\n", 6);
		return (1);
	}
	return (0);
}
