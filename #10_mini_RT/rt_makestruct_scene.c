/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_makestruct_scene.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 10:17:47 by cooi              #+#    #+#             */
/*   Updated: 2024/01/28 04:27:12 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	add_hittable(t_rt **f, void *obj, char *type)
{
	t_hittable	*tmp;
	t_hittable	*new;
	static int	i = 0;

	new = ft_calloc(1, sizeof(t_hittable));
	new->obj = obj;
	new->type = type;
	new->next = NULL;
	new->id = i;
	i++;
	tmp = (*f)->objs;
	if (!tmp)
		(*f)->objs = new;
	else
	{
		while (tmp && tmp->next)
			tmp = tmp->next;
		tmp->next = new;
		tmp->next->prev = tmp;
	}
}

int	get_ambient(t_rt **f, char **split)
{
	t_ambient	*a;
	t_xyz		rgb;

	if ((*f)->a != NULL || arrlen(split) != 3)
		return (free_array(split), -1);
	a = ft_calloc(1, sizeof(t_ambient));
	if (!a)
		return (free_array(split), -1);
	a->lum = ft_atof(split[1]);
	if (a->lum > 1 || a->lum < 0 || check_float(split[1], 0) == 0)
		return (free(a), free_array(split), -1);
	if (get_xyz(&rgb, split[2], 1) == -1)
		return (free(a), free_array(split), -1);
	if (check_rgb(rgb) == 0)
		return (free(a), free_array(split), -1);
	a->rgb = create_argb(1, rgb.x, rgb.y, rgb.z);
	(*f)->a = a;
	return (free_array(split), 0);
}

int	get_camera(t_rt **f, char **split)
{
	t_camera	*c;

	if ((*f)->c != NULL || arrlen(split) != 4)
		return (free_array(split), -1);
	c = ft_calloc(1, sizeof(t_camera));
	if (!c)
		return (free_array(split), -1);
	if (get_xyz(&c->pos, split[1], 1) == -1)
		return (free(c), free_array(split), -1);
	if (get_xyz(&c->dir, split[2], 0) == -1)
		return (free(c), free_array(split), -1);
	if (check_vector(c->dir) == 0)
		return (free(c), free_array(split), -1);
	c->fov = ft_atof(split[3]);
	if (c->fov < 0 || c->fov > 180 || check_float(split[3], 0) == 0)
		return (free(c), free_array(split), -1);
	(*f)->c = c;
	c->dir = normalize(c->dir);
	return (free_array(split), 0);
}
