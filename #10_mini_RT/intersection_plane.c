/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection_plane.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 10:31:55 by kali              #+#    #+#             */
/*   Updated: 2024/01/28 04:47:20 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

float	plane_intersection(t_xyz ro, t_xyz rd, t_xyz pp, t_xyz pn)
{
	float	d;
	float	t;
	t_xyz	ray;

	pn = normalize(pn);
	d = dot(rd, pn);
	if (fabs(d) > 1e-6)
	{
		ray = subtract_xyz(ro, pp);
		t = dot(ray, pn) / d;
		if (t > 0.0)
			return (t);
	}
	return (-1);
}

float	intersect_plane(t_xyz origin, t_xyz ray, t_hittable *obj)
{
	float		t;
	t_plane		*pl;

	pl = obj->obj;
	t = plane_intersection(origin, ray, pl->pos, pl->nor);
	return (t);
}
