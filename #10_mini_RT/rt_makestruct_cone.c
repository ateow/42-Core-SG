/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_makestruct_cone.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 08:06:47 by kali              #+#    #+#             */
/*   Updated: 2024/01/24 09:59:13 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	init_cone(t_cone *co, char **split)
{
	co->nor = normalize(co->i_nor);
	co->d = ft_atof(split[3]);
	co->rad_top = 0;
	co->rad_btt = co->d / 2.0;
	co->h = ft_atof(split[4]);
	co->pt_top = multiply_xyz(co->nor, co->h);
	co->pt_top = add_xyz(co->pt_top, co->pos);
	co->pt_btt = multiply_xyz(co->nor, -co->h);
	co->pt_btt = add_xyz(co->pt_btt, co->pos);
	co->half_angle = atan((co->d / 2.0) / co->h);
	co->cos2 = cos(atan((co->d / 2.0) / co->h));
	co->cos2 *= co->cos2;
}

int	get_cone(t_rt **f, char **split)
{
	t_cone	*co;
	t_xyz	rgb;

	co = ft_calloc(1, sizeof(t_cone));
	if (!co)
		return (free_array(split), -1);
	if (get_xyz(&co->pos, split[1], 1) == -1)
		return (free(co), free_array(split), -1);
	if (get_xyz(&co->i_nor, split[2], 0) == -1
		|| check_vector(co->i_nor) == 0)
		return (free(co), free_array(split), -1);
	init_cone(co, split);
	if (get_xyz(&rgb, split[5], 1) == -1 || check_float(split[3], 0) == 0
		|| check_float(split[4], 0) == 0 || check_rgb(rgb) == 0
		|| co->d < 0 || co->h < 0)
		return (free(co), free_array(split), -1);
	co->rgb = create_argb(1, rgb.x, rgb.y, rgb.z);
	add_hittable(f, co, "co");
	return (free_array(split), 0);
}
