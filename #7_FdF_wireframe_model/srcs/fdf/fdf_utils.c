/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ateow <ateow@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 10:56:41 by ateow             #+#    #+#             */
/*   Updated: 2023/10/22 10:56:43 by ateow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"
#include "../../includes/mlx.h"

int	close_window(t_data data)
{
	mlx_destroy_window(data.mlx, data.win);
	exit (1);
}

int	key_hook(int keycode, t_data *data)
{
	printf("keycode:%d\n", keycode); // rem to delete
	if (keycode == 65307)
		close_window(*data);
	if (keycode == 65362 || keycode == 65364 || keycode == 65361 || keycode == 65363|| keycode == 91 || keycode == 93)
	{
		rotate_node_z(data, keycode);
		translate_position(data, data->center_x, data->center_y);
		mlx_clear_window(data->mlx, data->win);
		render(data->node, data->map_size, *data);
	}
	if (keycode == 114) // press R to go to default
	{
		rotate_node_default(data);
		translate_center(data);
		mlx_clear_window(data->mlx, data->win);
		render(data->node, data->map_size, *data);
	}
	return (0);
}

int	mouse_press(int button, int x, int y, t_data *data)
{
	if (button == 1) // Check for left mouse button press (button 1)
	{
		data->click_drag_x = x;
		data->click_drag_y = y;
		printf("drag_start_x_b1_press:%d\n", data->click_drag_x); // rem to delete
		printf("drag_start_y_b1_press:%d\n", data->click_drag_y); // rem to delete
	}
	else if (button == 2) // Check for left mouse button press (button 1)
	{
		data->middle_drag_x = x;
		data->middle_drag_y = y;
	}
	else if (button == 4)
	{
		int org = data->node[0]->x;
		int org2 = data->node[0]->y;
		data->zoom_xy = 2;
		data->zoom_z = 2;
		scale(data->node, data->zoom_xy, data->zoom_z);
		int move = org - data->node[0]->x;
		int move2 = org2 - data->node[0]->y;
		translate_position(data, move + move/2, move2 + move2/2);
		mlx_clear_window(data->mlx, data->win);
		render(data->node, data->map_size, *data);
		printf("ZOOMUP\n");
	}
	else if (button == 5)
	{
		int org = data->node[0]->x;
		int org2 = data->node[0]->y;
		data->zoom_xy = 0.5;
		data->zoom_z = 0.5;
		scale(data->node, data->zoom_xy, data->zoom_z);
		int move = org - data->node[0]->x;
		int move2 = org2 - data->node[0]->y;
		translate_position(data, move + move/2, move2 + move2/2);
		mlx_clear_window(data->mlx, data->win);
		render(data->node, data->map_size, *data);
		printf("ZOOMDOWN\n");
	}
	return (0);
}

int	mouse_release(int button, int x, int y, t_data *data)
{
	if (button == 1)
	{
		printf("buttoninrelease_1\n\n");
		printf("x:%d\n", x);
		printf("y:%d\n", y);
		data->center_x += x - data->click_drag_x;
		data->center_y += y - data->click_drag_y;
		translate_position(data, x - data->click_drag_x, y - data->click_drag_y);
		mlx_clear_window(data->mlx, data->win);
		render(data->node, data->map_size, *data);
	}
	else if (button == 2)
	{
		if (x - data->middle_drag_x == 0 && y - data->middle_drag_y == 0)
			return (0);
		rotate_node(data, x, y);
		translate_position(data, data->center_x, data->center_y);
		mlx_clear_window(data->mlx, data->win);
		render(data->node, data->map_size, *data);
	}
	return (0);
}

