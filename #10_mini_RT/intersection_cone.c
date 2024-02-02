/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection_cone.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 10:01:45 by kali              #+#    #+#             */
/*   Updated: 2024/01/28 04:48:03 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

float	conic_inter(t_xyz ro, t_xyz rd, t_cone *co)
{
	t_quadratic	q;
	float		prod_dv;
	float		prod_cov;
	t_xyz		v_co;
	t_xyz		inter;

	v_co = subtract_xyz(co->pos, ro);
	prod_dv = dot(rd, co->nor);
	prod_cov = dot(v_co, co->nor);
	q.a = prod_dv * prod_dv - co->cos2;
	q.b = 2 * (prod_dv * prod_cov - dot(rd, v_co) * co->cos2);
	q.c = prod_cov * prod_cov - dot(v_co, v_co) * co->cos2;
	if (solve_quadratic(&q) == 0 || (q.t2 <= 0.0001 && q.t1 <= 0.0001))
		return (-1);
	if (q.t1 <= 0.0001 || (q.t2 > 0.0001 && (q.t2 < q.t1)))
		q.t1 = q.t2;
	inter = intersect_pos(ro, rd, q.t1);
	v_co = subtract_xyz(co->pos, inter);
	if (dot(co->nor, v_co) > 0 || dot(co->nor, v_co) < -co->h)
		return (-1);
	return (q.t1);
}

float	cone_intersection(t_xyz ro, t_xyz rd, t_cone *co)
{
	float	t;
	float	tmp;

	tmp = INFINITY;
	t = plane_intersection(ro, rd, co->pt_top, co->nor);
	if ((t != -1)
		&& (distance(intersect_pos(ro, rd, t), co->pt_top) <= co->rad_top)
		&& (tmp > t))
		tmp = t;
	t = plane_intersection(ro, rd, co->pt_btt, co->nor);
	if ((t != -1)
		&& (distance(intersect_pos(ro, rd, t), co->pt_btt) <= co->rad_btt)
		&& (tmp > t))
		tmp = t;
	t = conic_inter(ro, rd, co);
	if (t != -1 && (tmp > t))
		tmp = t;
	if (tmp < INFINITY && tmp > 0.0001)
		return (tmp);
	return (-1);
}

float	intersect_cone(t_xyz origin, t_xyz ray, t_hittable *obj)
{
	float	t;
	t_cone	*co;

	co = obj->obj;
	t = cone_intersection(origin, ray, co);
	return (t);
}
