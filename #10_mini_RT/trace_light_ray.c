/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace_light_ray.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ateow <ateow@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 11:08:29 by cooi              #+#    #+#             */
/*   Updated: 2024/01/31 16:35:32 by ateow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	trace_ray_cone(t_params *params, t_xyz ray, t_hittable *obj, float t)
{
	t_light	*light;
	t_inter	in;
	int		col;
	t_cone	*co;

	co = obj->obj;
	light = params->f->l;
	col = scale_rgb(mul_rgb(co->rgb, params->f->a->rgb), params->f->a->lum);
	while (light)
	{
		in.inter = add_xyz(params->f->c->pos, scale_xyz(ray, t));
		in.surfnorm = get_cone_surfacenorm(in, co);
		in.tolight = subtract_xyz(in.inter, light->pos);
		if (check_shadowed(params, in, obj->id) == 0)
			col = add_rgb(col, get_specular_diffuse(in, light, co->rgb, ray));
		light = light->next;
	}
	return (col);
}

int	trace_ray_plane(t_params *params, t_xyz ray, t_hittable *obj, float t)
{
	t_light	*light;
	t_inter	in;
	int		col;
	t_plane	*pl;

	pl = obj->obj;
	light = params->f->l;
	col = scale_rgb(mul_rgb(pl->rgb, params->f->a->rgb), params->f->a->lum);
	while (light)
	{
		in.inter = add_xyz(params->f->c->pos, scale_xyz(ray, t));
		in.surfnorm = normalize(pl->nor);
		in.tolight = subtract_xyz(in.inter, light->pos);
		if (get_intersection(params->f->c->pos,
				normalize(in.tolight), obj) == -1)
			if (check_shadowed(params, in, obj->id) == 0)
				col = add_rgb(col,
						get_specular_diffuse(in, light, pl->rgb, ray));
		light = light->next;
	}
	return (col);
}

int	trace_ray_sphere(t_params *params, t_xyz ray, t_hittable *obj, float t)
{
	t_light		*light;
	t_inter		in;
	int			col;
	t_sphere	*sp;

	sp = obj->obj;
	light = params->f->l;
	col = scale_rgb(mul_rgb(sp->rgb, params->f->a->rgb), params->f->a->lum);
	while (light)
	{
		in.inter = add_xyz(params->f->c->pos, scale_xyz(ray, t));
		in.surfnorm = normalize(subtract_xyz(in.inter, sp->pos));
		in.tolight = subtract_xyz(in.inter, light->pos);
		if (sp->is_checkered == 1)
			sp->rgb = map_cb_texture(in.inter, params->f->c->dir, sp);
		if (sp->has_skin == 1)
		{
			sp->rgb = map_skin_texture(params, in.inter, params->f->c->dir, sp);
			in.surfnorm = map_skin_bump(params, in, params->f->c->dir, sp);
		}
		if (check_shadowed(params, in, obj->id) == 0)
			col = add_rgb(col, get_specular_diffuse(in, light, sp->rgb, ray));
		light = light->next;
	}
	return (col);
}

int	trace_ray_cylinder(t_params *params, t_xyz ray, t_hittable *obj, float t)
{
	t_light		*light;
	t_inter		in;
	int			col;
	t_cylinder	*cy;

	cy = obj->obj;
	light = params->f->l;
	col = scale_rgb(mul_rgb(cy->rgb, params->f->a->rgb), params->f->a->lum);
	while (light)
	{
		in.inter = add_xyz(params->f->c->pos, scale_xyz(ray, t));
		in.surfnorm = get_cylinder_surfacenorm(in, cy);
		in.tolight = subtract_xyz(in.inter, light->pos);
		if (check_shadowed(params, in, obj->id) == 0)
			col = add_rgb(col, get_specular_diffuse(in, light, cy->rgb, ray));
		light = light->next;
	}
	return (col);
}

int	trace_ray_lights(t_params *params, t_xyz ray, t_hittable *obj, float t)
{
	if (ft_strncmp(obj->type, "sp", 2) == 0)
		return (trace_ray_sphere(params, ray, obj, t));
	else if (ft_strncmp(obj->type, "pl", 2) == 0)
		return (trace_ray_plane(params, ray, obj, t));
	else if (ft_strncmp(obj->type, "cy", 2) == 0)
		return (trace_ray_cylinder(params, ray, obj, t));
	else if (ft_strncmp(obj->type, "co", 2) == 0)
		return (trace_ray_cone(params, ray, obj, t));
	return (0);
}
