/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ateow <ateow@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 14:37:20 by ateow             #+#    #+#             */
/*   Updated: 2023/10/30 14:37:22 by ateow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"
#include "../../includes/mlx.h"

int	key_hook(int keycode, t_data *data)
{
	if (keycode == 65307)
		close_window(data);
	if (keycode == 65362 || keycode == 65364 || keycode == 65361
		|| keycode == 65363 || keycode == 91 || keycode == 93)
	{
		rotate_node_z(data, keycode);
		translate_position(data, data->rot_axis_x, data->rot_axis_y);
		render(*data);
	}
	if (keycode == 114 || keycode == 48)
		project_default(data);
	if (keycode == 49)
		project_iso(data);
	if (keycode == 50)
		project_top(data);
	if (keycode == 51)
		project_front(data);
	if (keycode == 52)
		project_side(data);
	adjust_altitude(keycode, data);
	return (0);
}

int	mouse_press(int button, int x, int y, t_data *data)
{
	if (button == 1)
	{
		data->click_drag_x = x;
		data->click_drag_y = y;
	}
	else if (button == 2)
	{
		data->middle_drag_x = x;
		data->middle_drag_y = y;
	}
	ajust_scale(button, data);
	return (0);
}

int	mouse_release(int button, int x, int y, t_data *data)
{
	if (button == 1)
	{
		translate_position(data, x - data->click_drag_x,
			y - data->click_drag_y);
		data->rot_axis_x += x - data->click_drag_x;
		data->rot_axis_y += y - data->click_drag_y;
		render(*data);
	}
	else if (button == 2)
	{
		if (x - data->middle_drag_x == 0 && y - data->middle_drag_y == 0)
			return (0);
		rotate_node(data, x, y);
		translate_position(data, data->rot_axis_x, data->rot_axis_y);
		render(*data);
	}
	return (0);
}
/*
(keycode == 61) // enter + and increase height
(keycode == 45) // enter - and reduce height
(keycode == 114 || keycode == 48) // enter r or 0 for default view
(keycode == 49) // enter 1 for iso view
(keycode == 50) // enter 2 for plan view
(keycode == 51) // enter 3 for front view
(keycode == 52) // enter 4 for side view
(button == 4) // scroll up for to zoom in
(button == 5) // scroll down for to zoom in	
(keycode == 65307) // esc key to exit
(keycode == 65362) // enter up to rotate x
(keycode == 65364) // enter down to rotate x
(keycode == 65361) // enter left to rotate y
(keycode == 65363) // enter right to rotate y
(keycode == 91) // enter [ to rotate z
(keycode == 93) // enter ] to rotate z
*/
