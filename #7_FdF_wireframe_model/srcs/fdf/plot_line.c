/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plot_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ateow <ateow@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 13:10:15 by ateow             #+#    #+#             */
/*   Updated: 2023/10/23 13:10:16 by ateow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"
#include "../../includes/mlx.h"

void	plot_line_low(t_xyaxis p1, t_xyaxis p2, t_data data)
{
	t_xyaxis	plot;
	t_plot_line	tools;

	tools.diffx = p2.x - p1.x;
	tools.diffy = p2.y - p1.y;
	tools.i = 1;
	if (tools.diffy < 0)
	{
		tools.i = -1;
		tools.diffy = -tools.diffy;
	}
	tools.d = (2 * tools.diffy) - tools.diffx;
	plot.y = p1.y;
	plot.x = p1.x;
	while (plot.x <= p2.x)
	{
		mlx_pixel_put(data.mlx, data.win, plot.x, plot.y, 0xFFFFFF);
		if (tools.d > 0)
		{
			plot.y = plot.y + tools.i;
			tools.d += -2 * tools.diffx;
		}
		tools.d += 2 * tools.diffy;
		plot.x++;
	}
}

void	plot_line_high(t_xyaxis p1, t_xyaxis p2, t_data data)
{
	t_xyaxis	plot;
	t_plot_line	tools;

	tools.diffx = p2.x - p1.x;
	tools.diffy = p2.y - p1.y;
	tools.i = 1;
	if (tools.diffx < 0)
	{
		tools.i = -1;
		tools.diffx = -tools.diffx;
	}
	tools.d = (2 * tools.diffx) - tools.diffy;
	plot.y = p1.y;
	plot.x = p1.x;
	while (plot.y <= p2.y)
	{
		mlx_pixel_put(data.mlx, data.win, plot.x, plot.y, 0xFFFFFF);
		if (tools.d > 0)
		{
			plot.x = plot.x + tools.i;
			tools.d += -2 * tools.diffy;
		}
		tools.d += 2 * tools.diffx;
		plot.y++;
	}
}

void	plot_line(t_xyaxis p1, t_xyaxis p2, t_data data)
{
	t_xyaxis	diff;

	diff.x = p2.x - p1.x;
	diff.y = p2.y - p1.y;
	if (diff.x < 0)
		diff.x = -diff.x;
	if (diff.y < 0)
		diff.y = -diff.y;
	if (diff.y < diff.x)
	{
		if (p1.x > p2.x)
			plot_line_low(p2, p1, data);
		else
			plot_line_low(p1, p2, data);
	}
	else if (p1.y > p2.y)
		plot_line_high(p2, p1, data);
	else
		plot_line_high(p1, p2, data);
}
/*
plot line high are for steep slope (between 45deg to vert line)
	this means that you increament y more then x
	note that y always increase by 1 per iteration
	while x only increase on a fix iteration
	
plot line low are for gentle slope (beteen hort line to 45deg)
	this means that you increament x more then y
	note that x always increase by 1 per iteration
	while y only increase on a fix iteration

plot line function calc the slope and determine which function to pass
it also reverse point 1 and point 2 if point 1 is > then point 2

printf("x:%d, y:%d, D:%d\n", x, y, D);
*/
