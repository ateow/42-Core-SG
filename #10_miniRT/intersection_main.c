/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection_main.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 10:32:05 by kali              #+#    #+#             */
/*   Updated: 2024/01/17 08:31:44 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_xyz	intersect_pos(t_xyz ro, t_xyz rd, float t)
{
	t_xyz	res;

	res.x = ro.x + t * rd.x;
	res.y = ro.y + t * rd.y;
	res.z = ro.z + t * rd.z;
	return (res);
}

int	solve_quadratic(t_quadratic *q)
{
	q->delta = q->b * q->b - 4 * q->a * q->c;
	if (q->delta < 0)
		return (0);
	q->t1 = (-q->b - sqrt(q->delta)) / (q->a * 2.0);
	q->t2 = (-q->b + sqrt(q->delta)) / (q->a * 2.0);
	return (1);
}

float	get_intersection(t_xyz origin, t_xyz ray, t_hittable *obj)
{
	float		t;

	if (ft_strncmp(obj->type, "sp", 2) == 0)
		t = intersect_sphere(origin, ray, obj);
	else if (ft_strncmp(obj->type, "pl", 2) == 0)
		t = intersect_plane(origin, ray, obj);
	else if (ft_strncmp(obj->type, "cy", 2) == 0)
		t = intersect_cylinder(origin, ray, obj);
	else if (ft_strncmp(obj->type, "co", 2) == 0)
		t = intersect_cone(origin, ray, obj);
	return (t);
}
