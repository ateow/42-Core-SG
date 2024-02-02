/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_makestruct_cylinder.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ateow <ateow@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 10:20:39 by cooi              #+#    #+#             */
/*   Updated: 2024/01/21 14:35:46 by ateow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	init_cylinder(t_cylinder *cy, char **split)
{
	cy->nor = normalize(cy->i_nor);
	cy->d = ft_atof(split[3]);
	cy->h = ft_atof(split[4]);
	cy->p1 = multiply_xyz(cy->nor, -0.5 * cy->h);
	cy->p1 = add_xyz(cy->p1, cy->pos);
	cy->p2 = multiply_xyz(cy->nor, 0.5 * cy->h);
	cy->p2 = add_xyz(cy->p2, cy->pos);
	cy->sqt_radius = cy->d * cy->d * 0.25;
}

int	get_cylinder(t_rt **f, char **split)
{
	t_cylinder	*cy;
	t_xyz		rgb;

	cy = ft_calloc(1, sizeof(t_cylinder));
	if (!cy)
		return (free_array(split), -1);
	if (get_xyz(&cy->pos, split[1], 1) == -1)
		return (free(cy), free_array(split), -1);
	if (get_xyz(&cy->i_nor, split[2], 0) == -1
		|| check_vector(cy->i_nor) == 0)
		return (free(cy), free_array(split), -1);
	init_cylinder(cy, split);
	if (get_xyz(&rgb, split[5], 1) == -1 || check_float(split[3], 0) == 0
		|| check_float(split[4], 0) == 0 || check_rgb(rgb) == 0
		|| cy->d < 0 || cy->h < 0)
		return (free(cy), free_array(split), -1);
	cy->rgb = create_argb(1, rgb.x, rgb.y, rgb.z);
	add_hittable(f, cy, "cy");
	return (free_array(split), 0);
}
