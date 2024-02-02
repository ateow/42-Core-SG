/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection_sphere.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 10:31:51 by kali              #+#    #+#             */
/*   Updated: 2024/01/24 09:59:54 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

float	sphere_intersection(t_xyz ro, t_xyz rd, t_xyz spos, float sr)
{
	t_xyz	oc;
	float	a;
	float	b;
	float	c;
	float	t;

	oc = subtract_xyz(spos, ro);
	a = dot(rd, rd);
	b = 2.0 * dot(rd, oc);
	c = dot(oc, oc) - sr * sr;
	if (b * b - 4 * a * c < 0)
		return (-1);
	t = (-b - sqrt(b * b - 4 * a * c)) / (2.0 * a);
	if ((-b + sqrt(b * b - 4 * a * c)) / (2.0 * a) > t && t > 0)
		return (t);
	t = (-b + sqrt(b * b - 4 * a * c)) / (2.0 * a);
	return (t);
}

float	intersect_sphere(t_xyz origin, t_xyz ray, t_hittable *obj)
{
	float		t;
	t_sphere	*sp;

	sp = obj->obj;
	t = sphere_intersection(origin, ray, sp->pos, sp->d / 2);
	return (t);
}
