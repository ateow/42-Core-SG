/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cooi <cooi@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 10:37:36 by cooi              #+#    #+#             */
/*   Updated: 2024/01/14 10:37:49 by cooi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	my_mlx_pixel_put(t_data *dat, int x, int y, int color)
{
	char	*dst;

	dst = dat->addr + (y * dat->line_length + x * (dat->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	clear_scene(t_params *params)
{
	int	i;
	int	j;

	i = 0;
	while (i < params->wx)
	{
		j = 0;
		while (j < params->wy)
		{
			my_mlx_pixel_put(&params->img, i, j, create_argb(255, 0, 0, 0));
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(params->vars.mlx, params->vars.win,
		params->img.img, 0, 0);
}
