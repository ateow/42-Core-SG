/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_makestruct_0.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 14:19:08 by cooi              #+#    #+#             */
/*   Updated: 2024/01/28 04:22:31 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	check_float(char *str, int c)
{
	int	j;
	int	k;

	j = 0;
	k = 1 - c;
	if (str[j] == '-' || str[j] == '+')
		j++;
	if (!str[j])
		return (0);
	while (str[j])
	{
		if (str[j] == '.')
			k--;
		else if (!ft_isdigit(str[j]))
			return (0);
		j++;
	}
	if (k < 0)
		return (0);
	return (1);
}

char	**validate_xyz(char *str, int c)
{
	char	**split;
	int		i;
	int		j;

	split = ft_split(str, ',');
	i = -1;
	j = 0;
	while (str[++i])
		j += (str[i] == ',');
	i = 0;
	while (split[i])
	{
		if (j != 2 || i > 3 || check_float(split[i], c) == 0)
			return (free_array(split), NULL);
		i++;
	}
	return (split);
}

int	get_xyz(t_xyz *xyz, char *str, int c)
{
	char	**split;

	split = validate_xyz(str, c);
	if (!split)
		return (-1);
	xyz->x = ft_atof(split[0]);
	xyz->y = ft_atof(split[1]);
	xyz->z = ft_atof(split[2]);
	free_array(split);
	return (0);
}

int	check_rgb(t_xyz rgb)
{
	if (rgb.x > 255 || rgb.x < 0)
		return (0);
	if (rgb.y > 255 || rgb.y < 0)
		return (0);
	if (rgb.z > 255 || rgb.z < 0)
		return (0);
	return (1);
}

int	check_vector(t_xyz xyz)
{
	if (xyz.x > 1 || xyz.x < -1)
		return (0);
	if (xyz.y > 1 || xyz.y < -1)
		return (0);
	if (xyz.z > 1 || xyz.z < -1)
		return (0);
	return (1);
}
