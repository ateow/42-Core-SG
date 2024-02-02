/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_main_keyhook.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 17:53:50 by ateow             #+#    #+#             */
/*   Updated: 2024/01/27 04:41:45 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	draw_rectangle(void *mlx, void *win, int width, int height)
{
	int	i;
	int	j;

	i = 20;
	while (i < 20 + width)
	{
		j = 20;
		while (j < 20 + height)
		{
			mlx_pixel_put(mlx, win, i, j, 0x202020);
			j++;
		}
		i++;
	}
}

void	destroy_skin_image(t_params *params)
{
	if (params->f->has_moon == 1)
	{
		mlx_destroy_image(params->vars.mlx, params->moon.img_ptr);
		mlx_destroy_image(params->vars.mlx, params->moon_bump.img_ptr);
	}
	if (params->f->has_earth == 1)
	{
		mlx_destroy_image(params->vars.mlx, params->earth.img_ptr);
		mlx_destroy_image(params->vars.mlx, params->earth_bump.img_ptr);
	}
	if (params->f->has_sun == 1)
	{
		mlx_destroy_image(params->vars.mlx, params->sun.img_ptr);
		mlx_destroy_image(params->vars.mlx, params->sun_bump.img_ptr);
	}
}

int	close_program(t_params *params)
{
	destroy_skin_image(params);
	mlx_destroy_image(params->vars.mlx, params->img.img);
	mlx_destroy_window(params->vars.mlx, params->vars.win);
	mlx_destroy_display(params->vars.mlx);
	free_rt(&params->f);
	free (params->vars.mlx);
	exit (0);
}

void	regenerate_image(t_params *params)
{
	destroy_skin_image(params);
	mlx_destroy_image(params->vars.mlx, params->img.img);
	mlx_destroy_window(params->vars.mlx, params->vars.win);
	mlx_destroy_display(params->vars.mlx);
	free (params->vars.mlx);
	generate_image(params);
}

int	key_hook(int keycode, t_params *p)
{
	if (keycode == 65307)
		close_program(p);
	if (keycode == 32)
		regenerate_image(p);
	if (keycode == 119)
	{
		windows_resize_menu(p);
		mlx_key_hook(p->vars.win, key_hook_resize, p);
	}
	if (keycode == 111)
	{
		objects_menu(p);
		mlx_key_hook(p->vars.win, key_hook_objects, p);
	}
	return (0);
}
