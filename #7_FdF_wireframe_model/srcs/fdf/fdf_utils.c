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

int	close_window(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	exit (1);
}

int	key_hook(int keycode, t_vars *vars)
{
	printf("keycode:%d\n", keycode); // rem to delete
	if (keycode == 65307)
		close_window(vars);
	return (0);
}
