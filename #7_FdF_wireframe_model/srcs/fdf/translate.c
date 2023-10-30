/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ateow <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 00:19:15 by ateow             #+#    #+#             */
/*   Updated: 2023/10/29 00:19:16 by ateow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

void	translate_orgin(t_coord **node, t_xyaxis map_size)
{
	int	i;
	int	x_offset;
	int	y_offset;

	i = 0;
	x_offset = node[map_size.x - 1]->x / 2;
	y_offset = node[(map_size.y) * (map_size.x) - 1]->y / 2;
	while (node[i] != NULL)
	{
		node[i]->x = node[i]->x - x_offset;
		node[i]->y = node[i]->y - y_offset;
		i++;
	}
}

void	translate_position(t_data *data, int x, int y)
{
	int	i;

	i = 0;
	while (data->node[i] != NULL)
	{
		data->node[i]->x = data->node[i]->x + x;
		data->node[i]->y = data->node[i]->y + y;
		i++;
	}
}

void	translate_center(t_data *data)
{
	int	i;

	i = 0;
	while (data->node[i] != NULL)
	{
		data->node[i]->x = data->node[i]->x + (data->win_size.x / 2);
		data->node[i]->y = data->node[i]->y + (data->win_size.y / 2);
		i++;
	}
	data->rot_axis_x = data->win_size.x / 2;
	data->rot_axis_y = data->win_size.y / 2;
}
