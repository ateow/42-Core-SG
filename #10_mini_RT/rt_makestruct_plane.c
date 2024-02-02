/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_makestruct_plane.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ateow <ateow@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 10:20:17 by cooi              #+#    #+#             */
/*   Updated: 2024/01/21 16:36:03 by ateow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	get_plane(t_rt **f, char **split)
{
	t_plane	*pl;
	t_xyz	rgb;

	pl = ft_calloc(1, sizeof(t_plane));
	if (!pl)
		return (free_array(split), -1);
	if (get_xyz(&pl->pos, split[1], 0) == -1)
		return (free(pl), free_array(split), -1);
	if (get_xyz(&pl->i_nor, split[2], 0) == -1
		|| check_vector(pl->i_nor) == 0)
		return (free(pl), free_array(split), -1);
	if (get_xyz(&rgb, split[3], 1) == -1 || check_rgb(rgb) == 0)
		return (free(pl), free_array(split), -1);
	pl->rgb = create_argb(1, rgb.x, rgb.y, rgb.z);
	pl->nor = normalize(pl->i_nor);
	add_hittable(f, pl, "pl");
	return (free_array(split), 0);
}
