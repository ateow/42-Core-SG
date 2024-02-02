/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace_get_surfnorm.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 04:25:38 by kali              #+#    #+#             */
/*   Updated: 2024/01/27 11:40:46 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_xyz	get_cone_surfacenorm(t_inter in, t_cone *co)
{
	float	ho;
	float	adj;
	float	btt;
	t_xyz	pt;

	btt = dot(normalize(subtract_xyz(co->pt_btt, in.inter)), co->nor);
	if (btt >= -0.001 && btt <= 0.01)
		if (length(subtract_xyz(in.inter, co->pt_btt)) < co->d / 2)
			return (co->nor);
	adj = length(subtract_xyz(co->pt_top, in.inter));
	ho = adj / cos(co->half_angle);
	pt = add_xyz(co->pt_top, scale_xyz(scale_xyz(co->nor, -1), ho));
	return (normalize(subtract_xyz(in.inter, pt)));
}

t_xyz	get_cylinder_surfacenorm(t_inter in, t_cylinder *cy)
{
	float	t;
	t_xyz	pt;
	float	btt;
	float	top;

	btt = dot(normalize(subtract_xyz(cy->p1, in.inter)), cy->nor);
	if (btt >= -0.001 && btt <= 0.01)
		if (length(subtract_xyz(in.inter, cy->p1)) < cy->d / 2)
			return (scale_xyz(cy->nor, -1));
	top = dot(normalize(subtract_xyz(cy->p2, in.inter)), cy->nor);
	if (top >= -0.001 && top <= 0.01)
		if (length(subtract_xyz(in.inter, cy->p2)) < cy->d / 2)
			return (cy->nor);
	t = dot(subtract_xyz(cy->p1, in.inter), cy->nor);
	pt = add_xyz(cy->p1, scale_xyz(cy->nor, t));
	return (normalize(subtract_xyz(in.inter, pt)));
}
