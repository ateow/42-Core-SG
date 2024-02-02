/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection_cylinder.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 10:31:59 by kali              #+#    #+#             */
/*   Updated: 2024/01/28 04:40:52 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

float	infinite_cylinder_intersection(t_xyz ro, t_xyz rd, t_cylinder *cy)
{
	t_quadratic	q;
	t_xyz		u;
	t_xyz		v;

	u = cross_prod(rd, cy->nor);
	v = subtract_xyz(cy->pos, ro);
	v = cross_prod(v, cy->nor);
	q.a = dot(u, u);
	q.b = 2 * dot(u, v);
	q.c = dot(v, v) - cy->sqt_radius;
	if (solve_quadratic(&q) == 0 || (q.t2 <= 0.0001 && q.t1 <= 0.0001))
		return (-1);
	if (q.t1 <= 0.0001 || (q.t2 > 0.0001 && (q.t2 < q.t1)))
		q.t1 = q.t2;
	return (q.t1);
}

float	cylinder_intersection(t_xyz ro, t_xyz rd, t_cylinder *cy)
{
	float	t;
	float	tmp;

	tmp = INFINITY;
	t = plane_intersection(ro, rd, cy->p1, normalize(cy->i_nor));
	if ((t != -1)
		&& (distance(intersect_pos(ro, rd, t), cy->p1) <= cy->d * 0.5)
		&& (tmp > t))
		tmp = t;
	t = plane_intersection(ro, rd, cy->p2, normalize(cy->i_nor));
	if ((t != -1)
		&& (distance(intersect_pos(ro, rd, t), cy->p2) <= cy->d * 0.5)
		&& (tmp > t))
		tmp = t;
	t = infinite_cylinder_intersection(ro, rd, cy);
	if ((t != -1)
		&& pow(distance(cy->pos, (intersect_pos(ro, rd, t))), 2)
		<= (pow(cy->h * 0.5, 2) + cy->sqt_radius)
		&& (tmp > t))
		tmp = t;
	if (tmp < INFINITY && tmp > 0.0001)
		return (tmp);
	return (-1);
}

float	intersect_cylinder(t_xyz origin, t_xyz ray, t_hittable *obj)
{
	float		t;
	t_cylinder	*cy;

	cy = obj->obj;
	t = cylinder_intersection(origin, ray, cy);
	return (t);
}
