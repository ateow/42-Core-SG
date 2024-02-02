/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_objs_display_pl_sp.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ateow <ateow@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 18:09:20 by ateow             #+#    #+#             */
/*   Updated: 2024/01/21 19:41:32 by ateow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	objects_menu_plane(t_params *p)
{
	t_plane			*o;
	t_xyz_strings	display;

	o = p->f->objs->obj;
	display.x = ft_itoa(o->pos.x);
	display.y = ft_itoa(o->pos.y);
	display.z = ft_itoa(o->pos.z);
	display.nx = ft_itoa(o->i_nor.x);
	display.ny = ft_itoa(o->i_nor.y);
	display.nz = ft_itoa(o->i_nor.z);
	display.d = NULL;
	display.h = NULL;
	display_pos_controls(p);
	mlx_string_put(p->vars.mlx, p->vars.win, 150, 75, 0xFFFFFF, display.x);
	mlx_string_put(p->vars.mlx, p->vars.win, 180, 75, 0xFFFFFF, display.y);
	mlx_string_put(p->vars.mlx, p->vars.win, 210, 75, 0xFFFFFF, display.z);
	display_nor_controls(p);
	mlx_string_put(p->vars.mlx, p->vars.win, 150, 125, 0xFFFFFF, display.nx);
	mlx_string_put(p->vars.mlx, p->vars.win, 180, 125, 0xFFFFFF, display.ny);
	mlx_string_put(p->vars.mlx, p->vars.win, 210, 125, 0xFFFFFF, display.nz);
	free_display(display);
}

void	objects_menu_sphere(t_params *p)
{
	t_sphere		*o;
	t_xyz_strings	display;

	o = p->f->objs->obj;
	display.x = ft_itoa(o->pos.x);
	display.y = ft_itoa(o->pos.y);
	display.z = ft_itoa(o->pos.z);
	display.d = ft_itoa(o->d);
	display_pos_controls(p);
	mlx_string_put(p->vars.mlx, p->vars.win, 150, 75, 0xFFFFFF, display.x);
	mlx_string_put(p->vars.mlx, p->vars.win, 180, 75, 0xFFFFFF, display.y);
	mlx_string_put(p->vars.mlx, p->vars.win, 210, 75, 0xFFFFFF, display.z);
	mlx_string_put(p->vars.mlx, p->vars.win, 30, 110, 0x505050, "up");
	mlx_string_put(p->vars.mlx, p->vars.win, 150, 110, 0x505050, "j");
	mlx_string_put(p->vars.mlx, p->vars.win, 30, 125, 0xFFFFFF, "diameter");
	mlx_string_put(p->vars.mlx, p->vars.win, 150, 125, 0xFFFFFF, display.d);
	mlx_string_put(p->vars.mlx, p->vars.win, 30, 140, 0x505050, "down");
	mlx_string_put(p->vars.mlx, p->vars.win, 150, 140, 0x505050, "m");
	free(display.x);
	free(display.y);
	free(display.z);
	free(display.d);
}
