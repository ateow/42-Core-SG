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
#include "../../includes/mlx.h"
#include <math.h> 

void	rotate_x(int *y, int *z, double angle_x)
{
	int	prev_y;

	prev_y = *y;
	*y = prev_y * cos(angle_x) - *z * sin(angle_x);
	*z = prev_y * sin(angle_x) + *z * cos(angle_x);
}

void	rotate_y(int *x, int *z, int *y, double angle_y)
{
	int	prev_x;

	prev_x = *x;
	*x = prev_x * cos(angle_y) + *z * sin(angle_y);
	*z = prev_x * -sin(angle_y) + *y * cos(angle_y);
}

void	rotate_z(int *x, int *y, double angle_z)
{
	int	prev_x;
	int	prev_y;
	
	prev_x = *x;
	prev_y = *y;
	*x = prev_x * cos(angle_z) - prev_y * sin(angle_z);
	*y = prev_x * sin(angle_z) + prev_y * cos(angle_z);
}

void	rotate_node_default(t_data *data)
{
	int	i;

    	data->angle.x = 30 * M_PI / 180;
	data->angle.y = 330 * M_PI / 180;
	data->angle.z = 35 * M_PI / 180;

	i = 0;
	while (data->node[i] != NULL)
	{
		data->node[i]->x = data->node_org[i]->x;
		data->node[i]->y = data->node_org[i]->y;
		data->node[i]->z = data->node_org[i]->z;
		rotate_x(&data->node[i]->y, &data->node[i]->z, data->angle.x);
		rotate_y(&data->node[i]->x, &data->node[i]->z, &data->node[i]->y, data->angle.y);
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
		rotate_y(&data->node[i]->x, &data->node[i]->z, &data->node[i]->y, data->angle.y);
		rotate_z(&data->node[i]->x, &data->node[i]->y, data->angle.z);
		i++;
	}
}

void	rotate_node_z(t_data *data, int keycode)
{
	int	i;

	if (keycode == 65362) //key:up
	    	data->angle.x += 5 * M_PI / 180;
	else if (keycode == 65364) //key:down
	    	data->angle.x -= 5 * M_PI / 180;	    	
	if (keycode == 65361) // key:left
		data->angle.y -= 5 * M_PI / 180;
	else if (keycode == 65363) // key:right
		data->angle.y += 5 * M_PI / 180;
	if (keycode == 91) // key: [
		data->angle.z += 5 * M_PI / 180;
	else if (keycode == 93) // key: ]
		data->angle.z -= 5 * M_PI / 180;
	i = 0;
	while (data->node[i] != NULL)
	{
		data->node[i]->x = data->node_org[i]->x;
		data->node[i]->y = data->node_org[i]->y;
		data->node[i]->z = data->node_org[i]->z;
		rotate_x(&data->node[i]->y, &data->node[i]->z, data->angle.x);
		rotate_y(&data->node[i]->x, &data->node[i]->z, &data->node[i]->y, data->angle.y);
		rotate_z(&data->node[i]->x, &data->node[i]->y, data->angle.z);
		i++;
	}
}
