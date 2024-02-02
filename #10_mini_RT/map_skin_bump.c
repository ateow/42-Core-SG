/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_skin_bump.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 08:20:54 by kali              #+#    #+#             */
/*   Updated: 2024/01/27 04:14:59 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	map_skin_texture(t_params *p, t_xyz inter, t_xyz cam_orient, t_sphere *sp)
{
	t_xyz	i;
	int		x;
	int		y;

	i = sphere_mapping(inter, cam_orient, sp);
	sp->cb.uv[0] = atan2(i.x, i.z) / (2 * M_PI) + 0.5;
	sp->cb.uv[1] = i.y * 0.5 + 0.5;
	if (sp->skin_type == 1)
	{
		x = (int)(sp->cb.uv[0] * p->moon.width) % p->moon.width;
		y = (int)(sp->cb.uv[1] * p->moon.height) % p->moon.height;
		return (p->moon.data[y * p->moon.width + x]);
	}
	if (sp->skin_type == 2)
	{
		x = (int)(sp->cb.uv[0] * p->earth.width) % p->earth.width;
		y = (int)(sp->cb.uv[1] * p->earth.height) % p->earth.height;
		return (p->earth.data[y * p->earth.width + x]);
	}
	else
	{
		x = (int)(sp->cb.uv[0] * p->sun.width) % p->sun.width;
		y = (int)(sp->cb.uv[1] * p->sun.height) % p->sun.height;
		return (p->sun.data[y * p->sun.width + x]);
	}
}

t_xyz	get_new_surface_normal(int colour, t_inter in)
{
	t_xyz	surface_normal;

	surface_normal.x = get_r(colour);
	surface_normal.y = get_g(colour);
	surface_normal.z = get_b(colour);
	surface_normal = normalize(surface_normal);
	surface_normal.x = surface_normal.x * 2 - 1;
	surface_normal.y = surface_normal.y * 2 - 1;
	surface_normal.z = surface_normal.z * 2 - 1;
	surface_normal = add_xyz(surface_normal, in.surfnorm);
	return (normalize(surface_normal));
}

int	get_colour(t_params *p, t_sphere *sp)
{
	int	x;
	int	y;
	int	colour;

	if (sp->skin_type == 1)
	{
		x = (int)(sp->cb.uv[0] * p->moon_bump.width) % p->moon_bump.width;
		y = (int)(sp->cb.uv[1] * p->moon_bump.height) % p->moon_bump.height;
		colour = p->moon_bump.data[y * p->moon_bump.width + x];
	}
	if (sp->skin_type == 2)
	{
		x = (int)(sp->cb.uv[0] * p->earth_bump.width) % p->earth_bump.width;
		y = (int)(sp->cb.uv[1] * p->earth_bump.height) % p->earth_bump.height;
		colour = p->earth_bump.data[y * p->earth_bump.width + x];
	}
	if (sp->skin_type == 3)
	{
		x = (int)(sp->cb.uv[0] * p->sun_bump.width) % p->sun_bump.width;
		y = (int)(sp->cb.uv[1] * p->sun_bump.height) % p->sun_bump.height;
		colour = p->sun_bump.data[y * p->sun_bump.width + x];
	}
	return (colour);
}

t_xyz	map_skin_bump(t_params *p, t_inter in, t_xyz cam_orient, t_sphere *sp)
{
	t_xyz	i;
	int		colour;

	i = sphere_mapping(in.inter, cam_orient, sp);
	sp->cb.uv[0] = atan2(i.x, i.z) / (2 * M_PI) + 0.5;
	sp->cb.uv[1] = i.y * 0.5 + 0.5;
	colour = get_colour(p, sp);
	return (get_new_surface_normal(colour, in));
}
