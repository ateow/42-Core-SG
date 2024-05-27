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

int	close_window(t_data *data)
{
	mlx_destroy_display(data->mlx);
	mlx_destroy_window(data->mlx, data->win);
	free_struct_arr(data->node);
	free_struct_arr(data->node_org);
	exit (1);
}

void	adjust_altitude(int keycode, t_data *data)
{
	if (keycode == 61)
	{
		data->zoom_z = 0.1;
		scale(data->node, 0, data->zoom_z);
		scale(data->node_org, 0, data->zoom_z);
		rotate_node_scale(data);
		translate_position(data, data->rot_axis_x, data->rot_axis_y);
		render(*data);
		data->counter_scale += 1;
	}
	if (keycode == 45)
	{
		data->zoom_z = -0.1;
		if (data->counter_scale > 0)
		{
			scale(data->node, 0, data->zoom_z);
			scale(data->node_org, 0, data->zoom_z);
			rotate_node_scale(data);
			translate_position(data, data->rot_axis_x, data->rot_axis_y);
			render(*data);
			data->counter_scale -= 1;
		}
	}
}

void	scale(t_coord **node, double xy_offset, double z_offset)
{
	int	i;

	i = 0;
	while (node[i] != NULL)
	{
		node[i]->x = node[i]->x + xy_offset * node[i]->x;
		node[i]->y = node[i]->y + xy_offset * node[i]->y;
		node[i]->z = node[i]->z + z_offset * node[i]->z;
		i++;
	}
}

void	ajust_scale(int button, t_data *data)
{
	if (button == 4)
	{
		data->zoom_xy = 0.1;
		data->zoom_z = 0.1;
		scale(data->node, data->zoom_xy, data->zoom_z);
		scale(data->node_org, data->zoom_xy, data->zoom_z);
		rotate_node_scale(data);
		translate_position(data, data->rot_axis_x, data->rot_axis_y);
		render(*data);
		data->counter_zoom += 1;
	}
	else if (button == 5)
	{
		data->zoom_xy = -0.1;
		data->zoom_z = -0.1;
		if (data->counter_zoom > 0)
		{
			scale(data->node, data->zoom_xy, data->zoom_z);
			scale(data->node_org, data->zoom_xy, data->zoom_z);
			rotate_node_scale(data);
			translate_position(data, data->rot_axis_x, data->rot_axis_y);
			render(*data);
			data->counter_zoom -= 1;
		}
	}
}
