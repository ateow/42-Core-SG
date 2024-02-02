/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_win_resize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 17:55:31 by ateow             #+#    #+#             */
/*   Updated: 2024/01/24 09:54:01 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	windows_resize_menu(t_params *p)
{
	char	*x;
	char	*y;

	x = ft_itoa(p->wx);
	y = ft_itoa(p->wy);
	draw_rectangle(p->vars.mlx, p->vars.win, 220, 80);
	mlx_string_put(p->vars.mlx, p->vars.win, 30, 40, 0xFFFFFF, "RESIZE WINDOW");
	mlx_string_put(p->vars.mlx, p->vars.win, 30, 60, 0x505050, "up");
	mlx_string_put(p->vars.mlx, p->vars.win, 150, 60, 0x505050, "a");
	mlx_string_put(p->vars.mlx, p->vars.win, 180, 60, 0x505050, "s");
	mlx_string_put(p->vars.mlx, p->vars.win, 30, 75, 0xFFFFFF,
		"window size (x,y)");
	mlx_string_put(p->vars.mlx, p->vars.win, 150, 75, 0xFFFFFF, x);
	mlx_string_put(p->vars.mlx, p->vars.win, 180, 75, 0xFFFFFF, y);
	mlx_string_put(p->vars.mlx, p->vars.win, 30, 90, 0x505050, "down");
	mlx_string_put(p->vars.mlx, p->vars.win, 150, 90, 0x505050, "z");
	mlx_string_put(p->vars.mlx, p->vars.win, 180, 90, 0x505050, "x");
	free(x);
	free(y);
}

int	key_hook_resize(int keycode, t_params *p)
{
	if (keycode == 65307)
		close_program(p);
	if (keycode == 97 && p->wx < 1600)
	{
		p->wx += 50;
		windows_resize_menu(p);
	}
	if (keycode == 122 && p->wx > 100)
	{
		p->wx -= 50;
		windows_resize_menu(p);
	}
	if (keycode == 115 && p->wy < 1200)
	{
		p->wy += 50;
		windows_resize_menu(p);
	}
	if (keycode == 120 && p->wy > 100)
	{
		p->wy -= 50;
		windows_resize_menu(p);
	}
	if (keycode == 32)
		regenerate_image(p);
	return (1);
}
