/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_mapping.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 09:44:49 by kali              #+#    #+#             */
/*   Updated: 2024/01/26 23:42:14 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

unsigned int	*generate_cb_arr(t_cb cb)
{
	int				y;
	int				x;
	int				i;
	int				j;
	unsigned int	*texture;

	texture = malloc(cb.width * cb.height * sizeof(unsigned int));
	y = 0;
	while (y < cb.height)
	{
		x = 0;
		while (x < cb.width)
		{
			i = x / cb.tilesize;
			j = y / cb.tilesize;
			if ((i + j) % 2 == 0)
				texture[y * cb.width + x] = cb.rgb1;
			else
				texture[y * cb.width + x] = cb.rgb2;
			x++;
		}
		y++;
	}
	return (texture);
}

t_xyz	sphere_mapping(t_xyz inter, t_xyz cam_orient, t_sphere *sp)
{
	t_xyz	ex;
	t_xyz	ey;
	t_xyz	ez;
	t_xyz	res;
	t_xyz	v;

	ey.x = 1;
	ey.y = 0;
	ey.z = 0;
	ey = normalize(ey);
	ex = normalize(cross_prod(ey, cam_orient));
	ez = normalize(cross_prod(ex, ey));
	v = normalize(subtract_xyz(inter, sp->pos));
	res.x = dot(ex, v);
	res.y = dot(ey, v);
	res.z = dot(ez, v);
	return (res);
}

int	map_cb_texture(t_xyz inter, t_xyz cam_orient, t_sphere *sp)
{
	unsigned int	*cb_arr;
	t_xyz			i;
	int				res;

	i = sphere_mapping(inter, cam_orient, sp);
	sp->cb.uv[0] = atan2(i.x, i.z) / (2 * M_PI) + 0.5;
	sp->cb.uv[1] = i.y * 0.5 + 0.5;
	cb_arr = generate_cb_arr(sp->cb);
	res = cb_arr[((int)(sp->cb.uv[1] * sp->cb.height) % sp->cb.height)
		* sp->cb.width
		+ ((int)(sp->cb.uv[0] * sp->cb.width) % sp->cb.width)];
	free (cb_arr);
	return (res);
}
