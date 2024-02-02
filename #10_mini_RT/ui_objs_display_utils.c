/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_objs_display_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ateow <ateow@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 18:15:48 by ateow             #+#    #+#             */
/*   Updated: 2024/01/21 19:40:59 by ateow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	display_pos_controls(t_params *p)
{
	mlx_string_put(p->vars.mlx, p->vars.win, 30, 60, 0x505050, "up");
	mlx_string_put(p->vars.mlx, p->vars.win, 150, 60, 0x505050, "a");
	mlx_string_put(p->vars.mlx, p->vars.win, 180, 60, 0x505050, "s");
	mlx_string_put(p->vars.mlx, p->vars.win, 210, 60, 0x505050, "d");
	mlx_string_put(p->vars.mlx, p->vars.win, 30, 75, 0xFFFFFF,
		"position (x,y,z)");
	mlx_string_put(p->vars.mlx, p->vars.win, 30, 90, 0x505050, "down");
	mlx_string_put(p->vars.mlx, p->vars.win, 150, 90, 0x505050, "z");
	mlx_string_put(p->vars.mlx, p->vars.win, 180, 90, 0x505050, "x");
	mlx_string_put(p->vars.mlx, p->vars.win, 210, 90, 0x505050, "c");
}

void	display_nor_controls(t_params *p)
{
	mlx_string_put(p->vars.mlx, p->vars.win, 30, 110, 0x505050, "up");
	mlx_string_put(p->vars.mlx, p->vars.win, 150, 110, 0x505050, "f");
	mlx_string_put(p->vars.mlx, p->vars.win, 180, 110, 0x505050, "g");
	mlx_string_put(p->vars.mlx, p->vars.win, 210, 110, 0x505050, "h");
	mlx_string_put(p->vars.mlx, p->vars.win, 30, 125, 0xFFFFFF,
		"normal (x,y,z)");
	mlx_string_put(p->vars.mlx, p->vars.win, 30, 140, 0x505050, "down");
	mlx_string_put(p->vars.mlx, p->vars.win, 150, 140, 0x505050, "v");
	mlx_string_put(p->vars.mlx, p->vars.win, 180, 140, 0x505050, "b");
	mlx_string_put(p->vars.mlx, p->vars.win, 210, 140, 0x505050, "n");
}

void	display_dia_controls(t_params *p)
{
	mlx_string_put(p->vars.mlx, p->vars.win, 30, 160, 0x505050, "up");
	mlx_string_put(p->vars.mlx, p->vars.win, 150, 160, 0x505050, "j");
	mlx_string_put(p->vars.mlx, p->vars.win, 30, 175, 0xFFFFFF, "diameter");
	mlx_string_put(p->vars.mlx, p->vars.win, 30, 190, 0x505050, "down");
	mlx_string_put(p->vars.mlx, p->vars.win, 150, 190, 0x505050, "m");
}

void	display_height_controls(t_params *p)
{
	mlx_string_put(p->vars.mlx, p->vars.win, 30, 210, 0x505050, "up");
	mlx_string_put(p->vars.mlx, p->vars.win, 150, 210, 0x505050, "k");
	mlx_string_put(p->vars.mlx, p->vars.win, 30, 225, 0xFFFFFF, "height");
	mlx_string_put(p->vars.mlx, p->vars.win, 30, 240, 0x505050, "down");
	mlx_string_put(p->vars.mlx, p->vars.win, 150, 240, 0x505050, ",");
}

void	free_display(t_xyz_strings s)
{
	if (s.x != NULL)
		free(s.x);
	if (s.y != NULL)
		free(s.y);
	if (s.z != NULL)
		free(s.z);
	if (s.nx != NULL)
		free(s.nx);
	if (s.ny != NULL)
		free(s.ny);
	if (s.nz != NULL)
		free(s.nz);
	if (s.d != NULL)
		free(s.d);
	if (s.h != NULL)
		free(s.h);
}
