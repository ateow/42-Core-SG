/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 21:26:29 by cooi              #+#    #+#             */
/*   Updated: 2024/01/28 04:50:12 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_xyz	rot_vector_to_cam_normal(t_xyz z_norm, t_xyz vec, t_xyz cam_nor)
{
	float	a;
	float	r_mat[3][3];
	t_xyz	r_axis;
	t_xyz	r_vec;

	r_axis = cross_prod(z_norm, cam_nor);
	a = acos(dot(z_norm, cam_nor));
	r_mat[0][0] = cos(a) + r_axis.x * r_axis.x * (1.0f - cos(a));
	r_mat[0][1] = r_axis.x * r_axis.y * (1.0f - cos(a)) - r_axis.z * sin(a);
	r_mat[0][2] = r_axis.x * r_axis.z * (1.0f - cos(a)) + r_axis.y * sin(a);
	r_mat[1][0] = r_axis.y * r_axis.x * (1.0f - cos(a)) + r_axis.z * sin(a);
	r_mat[1][1] = cos(a) + r_axis.y * r_axis.y * (1.0f - cos(a));
	r_mat[1][2] = r_axis.y * r_axis.z * (1.0f - cos(a)) - r_axis.x * sin(a);
	r_mat[2][0] = r_axis.z * r_axis.x * (1.0f - cos(a)) - r_axis.y * sin(a);
	r_mat[2][1] = r_axis.z * r_axis.y * (1.0f - cos(a)) + r_axis.x * sin(a);
	r_mat[2][2] = cos(a) + r_axis.z * r_axis.z * (1.0f - cos(a));
	r_vec.x = r_mat[0][0] * vec.x + r_mat[0][1] * vec.y + r_mat[0][2] * vec.z;
	r_vec.y = r_mat[1][0] * vec.x + r_mat[1][1] * vec.y + r_mat[1][2] * vec.z;
	r_vec.z = r_mat[2][0] * vec.x + r_mat[2][1] * vec.y + r_mat[2][2] * vec.z;
	return (r_vec);
}

t_quat	cquat(float angle, float axisX, float axisY, float axisZ)
{
	t_quat	quat;
	float	halfangle;
	float	sinhalfangle;

	halfangle = angle / 2.0f;
	sinhalfangle = sin(halfangle);
	quat.w = cos(halfangle);
	quat.x = axisX * sinhalfangle;
	quat.y = axisY * sinhalfangle;
	quat.z = axisZ * sinhalfangle;
	return (quat);
}

// Function to multiply two t_Quaternions
t_quat	mquat(t_quat q1, t_quat q2)
{
	t_quat	result;

	result.w = q1.w * q2.w - q1.x * q2.x - q1.y * q2.y - q1.z * q2.z;
	result.x = q1.w * q2.x + q1.x * q2.w + q1.y * q2.z - q1.z * q2.y;
	result.y = q1.w * q2.y - q1.x * q2.z + q1.y * q2.w + q1.z * q2.x;
	result.z = q1.w * q2.z + q1.x * q2.y - q1.y * q2.x + q1.z * q2.w;
	return (result);
}

// Function to rotate a 3D point using a t_Quaternion
t_xyz	rotate(t_xyz p, t_quat Quaternion)
{
	t_xyz	rp;
	float	w;
	float	x;
	float	y;
	float	z;

	w = Quaternion.w;
	x = Quaternion.x;
	y = Quaternion.y;
	z = Quaternion.z;
	rp.x = w * w * p.x + 2 * w * y * p.z - 2 * w * z * p.y + x * x * p.x
		+ 2 * x * y * p.y + 2 * z * x * p.z - z * z * p.x - y * y * p.x;
	rp.y = 2 * x * y * p.x + y * y * p.y + 2 * z * y * p.z + 2 * w * z * p.x
		- z * z * p.y + w * w * p.y - 2 * x * w * p.z - x * x * p.y;
	rp.z = 2 * x * z * p.x + 2 * y * z * p.y + z * z * p.z - 2 * w * y * p.x
		- y * y * p.z + 2 * w * x * p.y - x * x * p.z + w * w * p.z;
	return (normalize(rp));
}
