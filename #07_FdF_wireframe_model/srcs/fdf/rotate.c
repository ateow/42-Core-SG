/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ateow <ateow@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 23:46:32 by ateow             #+#    #+#             */
/*   Updated: 2023/10/26 23:46:34 by ateow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"
#include <math.h>

void	rotate_node_default(t_data *data)
{
	int	i;

	i = 0;
	while (data->node[i] != NULL)
	{
		data->node[i]->x = data->node_org[i]->x;
		data->node[i]->y = data->node_org[i]->y;
		data->node[i]->z = data->node_org[i]->z;
		rotate_x(&data->node[i]->y, &data->node[i]->z, data->angle.x);
		rotate_y(&data->node[i]->x, &data->node[i]->z,
			&data->node[i]->y, data->angle.y);
		rotate_z(&data->node[i]->x, &data->node[i]->y, data->angle.z);
		i++;
	}
}

void	rotate_node(t_data *data, int x, int y)
{
	int	i;
	int	x_diff;
	int	y_diff;

	x_diff = x - data->middle_drag_x;
	y_diff = y - data->middle_drag_y;
	data->angle.x -= y_diff / 5 * M_PI / 180;
	data->angle.y += x_diff / 5 * M_PI / 180;
	data->angle.z += 0 * M_PI / 180;
	i = 0;
	while (data->node[i] != NULL)
	{
		data->node[i]->x = data->node_org[i]->x;
		data->node[i]->y = data->node_org[i]->y;
		data->node[i]->z = data->node_org[i]->z;
		rotate_x(&data->node[i]->y, &data->node[i]->z, data->angle.x);
		rotate_y(&data->node[i]->x, &data->node[i]->z,
			&data->node[i]->y, data->angle.y);
		rotate_z(&data->node[i]->x, &data->node[i]->y, data->angle.z);
		i++;
	}
}

void	rotate_node_scale(t_data *data)
{
	int	i;

	data->angle.x += 0 * M_PI / 180;
	data->angle.y += 0 * M_PI / 180;
	data->angle.z += 0 * M_PI / 180;
	i = 0;
	while (data->node[i] != NULL)
	{
		data->node[i]->x = data->node_org[i]->x;
		data->node[i]->y = data->node_org[i]->y;
		data->node[i]->z = data->node_org[i]->z;
		rotate_x(&data->node[i]->y, &data->node[i]->z, data->angle.x);
		rotate_y(&data->node[i]->x, &data->node[i]->z,
			&data->node[i]->y, data->angle.y);
		rotate_z(&data->node[i]->x, &data->node[i]->y, data->angle.z);
		i++;
	}
}

void	rotate_node_z(t_data *data, int keycode)
{
	int	i;

	if (keycode == 65362)
		data->angle.x += 5 * M_PI / 180;
	else if (keycode == 65364)
		data->angle.x -= 5 * M_PI / 180;
	if (keycode == 65361)
		data->angle.y -= 5 * M_PI / 180;
	else if (keycode == 65363)
		data->angle.y += 5 * M_PI / 180;
	if (keycode == 91)
		data->angle.z += 5 * M_PI / 180;
	else if (keycode == 93)
		data->angle.z -= 5 * M_PI / 180;
	i = -1;
	while (data->node[++i] != NULL)
	{
		data->node[i]->x = data->node_org[i]->x;
		data->node[i]->y = data->node_org[i]->y;
		data->node[i]->z = data->node_org[i]->z;
		rotate_x(&data->node[i]->y, &data->node[i]->z, data->angle.x);
		rotate_y(&data->node[i]->x, &data->node[i]->z,
			&data->node[i]->y, data->angle.y);
		rotate_z(&data->node[i]->x, &data->node[i]->y, data->angle.z);
	}
}
