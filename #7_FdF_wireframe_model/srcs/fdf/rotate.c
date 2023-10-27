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


void	rotate_node(t_coord **node)
{
	int	i;
	double	angle_x;
	double	angle_y;
	double	angle_z;

    	//angle_x = 330 * M_PI / 180;
	//angle_y = -30 * M_PI / 180;
	//angle_z = 40 * M_PI / 180;
    	angle_x = 30 * M_PI / 180;
	angle_y = 330 * M_PI / 180;
	angle_z = 35 * M_PI / 180;

	i = 0;
	while (node[i] != NULL)
	{
		rotate_x(&node[i]->y, &node[i]->z, angle_x);
		rotate_y(&node[i]->x, &node[i]->z, &node[i]->y, angle_y);
		rotate_z(&node[i]->x, &node[i]->y, angle_z);
		i++;
	}
}
