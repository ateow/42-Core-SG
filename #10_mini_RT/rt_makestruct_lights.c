/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_makestruct_lights.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 10:19:12 by cooi              #+#    #+#             */
/*   Updated: 2024/01/28 08:25:24 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	append_light(t_rt **f, t_light *l)
{
	t_light	*tmp;

	tmp = (*f)->l;
	if (!tmp)
		(*f)->l = l;
	else
	{
		while (tmp && tmp->next)
			tmp = tmp->next;
		tmp->next = l;
	}
}

int	get_light(t_rt **f, char **split)
{
	t_light	*l;
	t_xyz	rgb;

	l = ft_calloc(1, sizeof(t_light));
	if (!l)
		return (free_array(split), -1);
	if (get_xyz(&l->pos, split[1], 1) == -1)
		return (free(l), free_array(split), -1);
	l->lum = ft_atof(split[2]);
	if (l->lum > 1 || l->lum < 0 || check_float(split[2], 0) == 0)
		return (free(l), free_array(split), -1);
	if (get_xyz(&rgb, split[3], 1) == -1 || check_rgb(rgb) == 0)
		return (free(l), free_array(split), -1);
	rgb.x = l->lum * rgb.x;
	rgb.y = l->lum * rgb.y;
	rgb.z = l->lum * rgb.z;
	l->rgb = create_argb(1, rgb.x, rgb.y, rgb.z);
	append_light(f, l);
	return (free_array(split), 0);
}
