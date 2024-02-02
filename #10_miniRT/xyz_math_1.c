/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xyz_math_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 10:35:15 by cooi              #+#    #+#             */
/*   Updated: 2024/01/14 10:34:33 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

float	dot(t_xyz a, t_xyz b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}

// Function to calculate the length of a vector
float	length(t_xyz v)
{
	return (sqrt(v.x * v.x + v.y * v.y + v.z * v.z));
}

// Function to normalize a vector
t_xyz	normalize(t_xyz v)
{
	float	len;
	t_xyz	r;

	len = length(v);
	r.x = v.x / len;
	r.y = v.y / len;
	r.z = v.z / len;
	return (r);
}

float	distance(t_xyz a, t_xyz b)
{
	float	x;
	float	y;
	float	z;

	x = a.x - b.x;
	y = a.y - b.y;
	z = a.z - b.z;
	x = pow(x, 2);
	y = pow(y, 2);
	z = pow(z, 2);
	return (sqrt(x + y + z));
}

t_xyz	cross_prod(t_xyz v1, t_xyz v2)
{
	t_xyz	result;

	result.x = v1.y * v2.z - v1.z * v2.y;
	result.y = v1.z * v2.x - v1.x * v2.z;
	result.z = v1.x * v2.y - v1.y * v2.x;
	return (result);
}
