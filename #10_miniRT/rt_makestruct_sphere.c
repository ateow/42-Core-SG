/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_makestruct_sphere.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 10:19:50 by cooi              #+#    #+#             */
/*   Updated: 2024/01/27 04:16:41 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	init_checkerboard(t_sphere *sp, t_cb *cb, char **split)
{
	t_xyz		cb_rgb1;
	t_xyz		cb_rgb2;

	if (get_xyz(&cb_rgb1, split[5], 1) == -1
		|| get_xyz(&cb_rgb2, split[6], 1) == -1
		|| check_float(split[7], 0) == 0
		|| check_float(split[8], 0) == 0
		|| check_float(split[9], 0) == 0)
		return (-1);
	cb->width = ft_atoi(split[7]);
	cb->height = ft_atoi(split[8]);
	cb->tilesize = ft_atoi(split[9]);
	cb->rgb1 = create_argb(1, cb_rgb1.x, cb_rgb1.y, cb_rgb1.z);
	cb->rgb2 = create_argb(1, cb_rgb2.x, cb_rgb2.y, cb_rgb2.z);
	sp->is_checkered = 1;
	return (0);
}

int	init_texture(t_rt **f, t_sphere *sp, char **split)
{
	if (ft_strncmp(split[4], "moon", ft_strlen(split[4])) == 0
		&& ft_strlen(split[4]) == 4)
	{
		(*f)->has_moon = 1;
		sp->skin_type = 1;
	}
	else if (ft_strncmp(split[4], "earth", ft_strlen(split[4])) == 0
		&& ft_strlen(split[4]) == 5)
	{
		(*f)->has_earth = 1;
		sp->skin_type = 2;
	}
	else if (ft_strncmp(split[4], "sun", ft_strlen(split[4])) == 0
		&& ft_strlen(split[4]) == 3)
	{
		(*f)->has_sun = 1;
		sp->skin_type = 3;
	}
	else
		return (-1);
	sp->has_skin = 1;
	return (0);
}

int	get_sphere(t_rt **f, char **split)
{
	t_sphere	*sp;
	t_xyz		rgb;

	sp = ft_calloc(1, sizeof(t_sphere));
	if (!sp)
		return (free_array(split), -1);
	sp->d = ft_atof(split[2]);
	if (get_xyz(&rgb, split[3], 1) == -1 || check_float(split[2], 0) == 0
		|| check_rgb(rgb) == 0 || get_xyz(&sp->pos, split[1], 1) == -1)
		return (free(sp), free_array(split), -1);
	sp->rgb = create_argb(1, rgb.x, rgb.y, rgb.z);
	sp->is_checkered = 0;
	sp->has_skin = 0;
	if (arrlen(split) == 5)
		if (init_texture(f, sp, split) == -1)
			return (free(sp), free_array(split), -1);
	if (arrlen(split) == 10)
	{
		if ((ft_strncmp(split[4], "cb", ft_strlen(split[4]))
				|| ft_strlen(split[4]) != 2)
			|| init_checkerboard(sp, &sp->cb, split) == -1)
			return (free(sp), free_array(split), -1);
	}
	add_hittable(f, sp, "sp");
	return (free_array(split), 0);
}
