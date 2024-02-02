/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_objs_display_cy_co.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ateow <ateow@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 18:19:44 by ateow             #+#    #+#             */
/*   Updated: 2024/01/21 19:11:15 by ateow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	objects_menu_cylinder(t_params *p)
{
	t_cylinder		*o;
	t_xyz_strings	display;

	o = p->f->objs->obj;
	display.x = ft_itoa(o->pos.x);
	display.y = ft_itoa(o->pos.y);
	display.z = ft_itoa(o->pos.z);
	display.nx = ft_itoa(o->i_nor.x);
	display.ny = ft_itoa(o->i_nor.y);
	display.nz = ft_itoa(o->i_nor.z);
	display.d = ft_itoa(o->d);
	display.h = ft_itoa(o->h);
	display_pos_controls(p);
	mlx_string_put(p->vars.mlx, p->vars.win, 150, 75, 0xFFFFFF, display.x);
	mlx_string_put(p->vars.mlx, p->vars.win, 180, 75, 0xFFFFFF, display.y);
	mlx_string_put(p->vars.mlx, p->vars.win, 210, 75, 0xFFFFFF, display.z);
	display_nor_controls(p);
	mlx_string_put(p->vars.mlx, p->vars.win, 150, 125, 0xFFFFFF, display.nx);
	mlx_string_put(p->vars.mlx, p->vars.win, 180, 125, 0xFFFFFF, display.ny);
	mlx_string_put(p->vars.mlx, p->vars.win, 210, 125, 0xFFFFFF, display.nz);
	display_dia_controls(p);
	mlx_string_put(p->vars.mlx, p->vars.win, 150, 175, 0xFFFFFF, display.d);
	display_height_controls(p);
	mlx_string_put(p->vars.mlx, p->vars.win, 150, 225, 0xFFFFFF, display.h);
	free_display(display);
}

void	objects_menu_cone(t_params *p)
{
	t_cone			*o;
	t_xyz_strings	display;

	o = p->f->objs->obj;
	display.x = ft_itoa(o->pos.x);
	display.y = ft_itoa(o->pos.y);
	display.z = ft_itoa(o->pos.z);
	display.nx = ft_itoa(o->i_nor.x);
	display.ny = ft_itoa(o->i_nor.y);
	display.nz = ft_itoa(o->i_nor.z);
	display.d = ft_itoa(o->d);
	display.h = ft_itoa(o->h);
	display_pos_controls(p);
	mlx_string_put(p->vars.mlx, p->vars.win, 150, 75, 0xFFFFFF, display.x);
	mlx_string_put(p->vars.mlx, p->vars.win, 180, 75, 0xFFFFFF, display.y);
	mlx_string_put(p->vars.mlx, p->vars.win, 210, 75, 0xFFFFFF, display.z);
	display_nor_controls(p);
	mlx_string_put(p->vars.mlx, p->vars.win, 150, 125, 0xFFFFFF, display.nx);
	mlx_string_put(p->vars.mlx, p->vars.win, 180, 125, 0xFFFFFF, display.ny);
	mlx_string_put(p->vars.mlx, p->vars.win, 210, 125, 0xFFFFFF, display.nz);
	display_dia_controls(p);
	mlx_string_put(p->vars.mlx, p->vars.win, 150, 175, 0xFFFFFF, display.d);
	display_height_controls(p);
	mlx_string_put(p->vars.mlx, p->vars.win, 150, 225, 0xFFFFFF, display.h);
	free_display(display);
}
