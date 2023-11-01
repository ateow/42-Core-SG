/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ateow <ateow@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 03:58:24 by ateow             #+#    #+#             */
/*   Updated: 2023/10/22 03:58:26 by ateow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"
#include "../../includes/mlx.h"
#include "../../includes/libft.h"
#include "../../includes/get_next_line.h"
#include <math.h>

t_coord	**get_coordinates(char *file)
{
	char	*string;
	int		fd;
	int		row;
	t_coord	**node;

	row = 0;
	node = NULL;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (0);
	while (fd != -1)
	{
		string = get_next_line(fd);
		if (string == NULL)
			break ;
		node = create_node(string, node, row);
		free(string);
		row++;
	}
	return (node);
}

void	get_map_size(t_coord **node, t_xyaxis *map_size)
{
	int	i;

	i = 0;
	while (node[i] != NULL)
	{
		if (node[i]->y != node[i + 1]->y)
			break ;
		i++;
	}
	map_size->x = i + 1;
	i = 0;
	while (node[i] != NULL)
		i++;
	map_size->y = i / map_size->x;
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
		return (0);
	data.map_info = argv[1];
	data.win_size.x = 1000;
	data.win_size.y = 1000;
	data.mlx = mlx_init ();
	data.win = mlx_new_window (data.mlx, data.win_size.x,
			data.win_size.y, "ateow_fdf");
	project_default(&data);
	mlx_key_hook(data.win, key_hook, &data);
	mlx_hook(data.win, 17, 0, close_window, &data);
	mlx_hook(data.win, 4, (1L << 2), mouse_press, &data);
	mlx_hook(data.win, 5, (1L << 3), mouse_release, &data);
	mlx_loop(data.mlx);
	free_struct_arr(data.node);
	free_struct_arr(data.node_org);
	return (0);
}
