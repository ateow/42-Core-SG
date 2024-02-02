/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xyz_math_0.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 10:33:29 by cooi              #+#    #+#             */
/*   Updated: 2024/01/14 10:46:19 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_xyz	scale_xyz(t_xyz a, float b)
{
	t_xyz	r;

	r.x = a.x * b;
	r.y = a.y * b;
	r.z = a.z * b;
	return (r);
}

t_xyz	add_xyz(t_xyz a, t_xyz b)
{
	t_xyz	r;

	r.x = b.x + a.x;
	r.y = b.y + a.y;
	r.z = b.z + a.z;
	return (r);
}

t_xyz	subtract_xyz(t_xyz a, t_xyz b)
{
	t_xyz	r;

	r.x = b.x - a.x;
	r.y = b.y - a.y;
	r.z = b.z - a.z;
	return (r);
}

t_xyz	multiply_xyz(t_xyz v, float f)
{
	t_xyz	dst;

	dst.x = v.x * f;
	dst.y = v.y * f;
	dst.z = v.z * f;
	return (dst);
}

//google vector reflection formula
t_xyz	reflect(t_xyz ray, t_xyz normal)
{
	t_xyz	r;

	r = subtract_xyz(ray, scale_xyz(normal, 2 * dot(ray, normal)));
	return (r);
}
