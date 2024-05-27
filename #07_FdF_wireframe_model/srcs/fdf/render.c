/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ateow <ateow@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 14:46:22 by ateow             #+#    #+#             */
/*   Updated: 2023/10/30 14:46:29 by ateow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"
#include "../../includes/mlx.h"

void	draw_last_row(t_data *data, int *i)
{
	t_xyaxis	p1;
	t_xyaxis	p2;

	p1.x = data->node[*i]->x;
	p1.y = data->node[*i]->y;
	p2.x = data->node[*i + 1]->x;
	p2.y = data->node[*i + 1]->y;
	plot_line(p1, p2, *data);
}

void	draw_last_col(t_data *data, int *i)
{
	t_xyaxis	p1;
	t_xyaxis	p2;

	p1.x = data->node[*i]->x;
	p1.y = data->node[*i]->y;
	p2.x = data->node[*i + data->map_size.x]->x;
	p2.y = data->node[*i + data->map_size.x]->y;
	plot_line(p1, p2, *data);
}

int	draw(t_data *data, int *i, int *j, int *k)
{
	if (*j == data->map_size.y - 1)
	{
		if (*k == data->map_size.x - 1)
			return (-1);
		draw_last_row(data, i);
	}
	else if (*k == data->map_size.x - 1)
		draw_last_col(data, i);
	else
	{
		draw_last_row(data, i);
		draw_last_col(data, i);
	}
	return (0);
}

void	render(t_data data)
{
	int			i;
	int			j;
	int			k;	

	mlx_clear_window(data.mlx, data.win);
	i = 0;
	j = 0;
	while (j < data.map_size.y)
	{
		k = 0;
		while (k < data.map_size.x)
		{
			if (draw(&data, &i, &j, &k) == -1)
				break ;
			k++;
			i++;
		}
		j++;
	}
}
