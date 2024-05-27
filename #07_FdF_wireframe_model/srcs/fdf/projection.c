/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ateow <ateow@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 13:49:04 by ateow             #+#    #+#             */
/*   Updated: 2023/10/30 13:49:06 by ateow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"
#include "../../includes/mlx.h"
#include <math.h>

void	project_default(t_data *data)
{
	data->counter_zoom = 0;
	data->counter_scale = 0;
	data->node = get_coordinates(data->map_info);
	data->node_org = get_coordinates(data->map_info);
	get_map_size(data->node, &(data->map_size));
	get_map_size(data->node_org, &(data->map_size));
	data->zoom_xy = data->win_size.x / (2 * data->map_size.x);
	data->zoom_z = data->zoom_xy / 8;
	scale(data->node, data->zoom_xy, data->zoom_z);
	scale(data->node_org, data->zoom_xy, data->zoom_z);
	translate_orgin(data->node_org, data->map_size);
	translate_orgin(data->node, data->map_size);
	data->angle.x = 30 * M_PI / 180;
	data->angle.y = -30 * M_PI / 180;
	data->angle.z = 30 * M_PI / 180;
	rotate_node_default(data);
	translate_center(data);
	render(*data);
}

void	project_iso(t_data *data)
{
	data->angle.x = 45 * M_PI / 180;
	data->angle.y = -45 * M_PI / 180;
	data->angle.z = 35 * M_PI / 180;
	rotate_node_default(data);
	translate_position(data, data->rot_axis_x, data->rot_axis_y);
	render(*data);
}

void	project_top(t_data *data)
{
	data->angle.x = 0 * M_PI / 180;
	data->angle.y = 0 * M_PI / 180;
	data->angle.z = 0 * M_PI / 180;
	rotate_node_default(data);
	translate_position(data, data->rot_axis_x, data->rot_axis_y);
	render(*data);
}

void	project_front(t_data *data)
{
	data->angle.x = 90 * M_PI / 180;
	data->angle.y = 0 * M_PI / 180;
	data->angle.z = 0 * M_PI / 180;
	rotate_node_default(data);
	translate_position(data, data->rot_axis_x, data->rot_axis_y);
	render(*data);
}

void	project_side(t_data *data)
{
	data->angle.x = 90 * M_PI / 180;
	data->angle.y = 90 * M_PI / 180;
	data->angle.z = 0 * M_PI / 180;
	rotate_node_default(data);
	translate_position(data, data->rot_axis_x, data->rot_axis_y);
	render(*data);
}
