/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_objs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 18:00:57 by ateow             #+#    #+#             */
/*   Updated: 2024/01/24 09:53:53 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	objects_menu(t_params *p)
{
	char	*id;

	id = ft_itoa(p->f->objs->id);
	draw_rectangle(p->vars.mlx, p->vars.win, 220, 230);
	mlx_string_put(p->vars.mlx, p->vars.win, 30, 40, 0xFFFFFF, "OBJECTS");
	mlx_string_put(p->vars.mlx, p->vars.win, 80, 40, 0x505050, "<");
	mlx_string_put(p->vars.mlx, p->vars.win, 90, 40, 0xFFFFFF,
		p->f->objs->type);
	mlx_string_put(p->vars.mlx, p->vars.win, 110, 40, 0xFFFFFF, id);
	mlx_string_put(p->vars.mlx, p->vars.win, 120, 40, 0x505050, ">");
	if (ft_strncmp(p->f->objs->type, "sp", 2) == 0)
		objects_menu_sphere(p);
	if (ft_strncmp(p->f->objs->type, "pl", 2) == 0)
		objects_menu_plane(p);
	if (ft_strncmp(p->f->objs->type, "cy", 2) == 0)
		objects_menu_cylinder(p);
	if (ft_strncmp(p->f->objs->type, "co", 2) == 0)
		objects_menu_cone(p);
	free(id);
}

void	key_hook_object_controls(int keycode, t_params *p)
{
	if (ft_strncmp(p->f->objs->type, "sp", 2) == 0)
		key_hook_object_controls_sphere(keycode, p);
	if (ft_strncmp(p->f->objs->type, "cy", 2) == 0)
		key_hook_object_controls_cylinder(keycode, p);
	if (ft_strncmp(p->f->objs->type, "pl", 2) == 0)
		key_hook_object_controls_plane(keycode, p);
	if (ft_strncmp(p->f->objs->type, "co", 2) == 0)
		key_hook_object_controls_cone(keycode, p);
}

int	key_hook_objects(int keycode, t_params *p)
{
	if (keycode == 65307)
		close_program(p);
	if (keycode == 32)
	{
		while (p->f->objs->id != 0)
			p->f->objs = p->f->objs->prev;
		regenerate_image(p);
	}
	if (p->f->objs->next != NULL && keycode == 65363)
	{
		p->f->objs = p->f->objs->next;
		objects_menu(p);
	}
	if (p->f->objs->id != 0 && keycode == 65361)
	{
		p->f->objs = p->f->objs->prev;
		objects_menu(p);
	}
	key_hook_object_controls(keycode, p);
	return (1);
}
