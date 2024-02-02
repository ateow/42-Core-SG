/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace_shadow.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ateow <ateow@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 04:19:37 by kali              #+#    #+#             */
/*   Updated: 2024/01/31 17:07:13 by ateow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	get_specular_diffuse(t_inter in, t_light *light, int rgb, t_xyz ray)
{
	t_trace	tr;
	t_xyz	tolight;

	tolight = scale_xyz(in.tolight, -1);
	tr.kd = fmax(0, dot(normalize(tolight), in.surfnorm));
	tr.diffuse = scale_rgb(rgb, tr.kd);
	tr.ks = pow(fmax(0, dot(normalize(tolight),
					reflect(ray, in.surfnorm))), 1);
	tr.specular = scale_rgb(light->rgb, tr.ks);
	tr.bright = 1 / (1 + length(tolight) * 0.001);
	return (scale_rgb(add_rgb(tr.diffuse, tr.specular), tr.bright));
}

int	check_shadowed(t_params *params, t_inter in, int id)
{
	t_hittable	*tmp;
	float		dis_pt_obj;

	tmp = params->f->objs;
	while (tmp)
	{
		if ((tmp->id == id))
		{
			tmp = tmp->next;
			continue ;
		}
		dis_pt_obj = get_intersection(in.inter, normalize(in.tolight), tmp);
		if (dis_pt_obj == -1 || dis_pt_obj > length(in.tolight))
		{
			tmp = tmp->next;
			continue ;
		}
		if (dis_pt_obj > 0.0001)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}
