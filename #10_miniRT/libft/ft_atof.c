/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ateow <ateow@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 15:50:22 by cooi              #+#    #+#             */
/*   Updated: 2024/01/31 16:23:29 by ateow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_digits(int n)
{
	int		i;
	long	tmp;

	tmp = n;
	if (n < 0)
		tmp *= -1;
	else
		tmp = n;
	i = 1;
	while (tmp > 9)
	{
		tmp /= 10;
		i++;
	}
	return (i);
}

float	ft_atof(char *str)
{
	char	**nums;
	int		i;
	int		j;
	int		k;
	float	r;

	nums = ft_split(str, '.');
	i = ft_atoi(nums[0]);
	r = 0.0;
	if (nums[1] != NULL)
	{
		j = ft_atoi(nums[1]);
		if (j != 0)
		{
			k = count_digits(j);
			r = j;
			while (k--)
				r /= 10;
		}
	}
	r += i;
	free_array(nums);
	return (r);
}
