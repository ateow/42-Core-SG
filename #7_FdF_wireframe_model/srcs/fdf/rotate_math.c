/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_math.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ateow <ateow@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 14:01:46 by ateow             #+#    #+#             */
/*   Updated: 2023/10/30 14:01:48 by ateow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"
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
