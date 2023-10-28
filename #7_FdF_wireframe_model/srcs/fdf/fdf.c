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


t_coord	**create_node(char *string, t_coord **node, int row)
{
	t_coord	**ret;
	char	**string_arr;
	int		i;
	int		j;

	string_arr = ft_split(string, ' ');
	i = 0;
	j = 0;
	while (string_arr[i] != NULL)
		i++;
	if (node != NULL)
	{
		while (node[j] != NULL)
			j++;
	}
	//printf("i:%d | j:%d\n", i, j);
	ret = malloc(sizeof(t_coord) * (i + j + 1));
	i = 0;
	j = 0;
	if (node != NULL)
	{
		while (node[j] != NULL)
		{
			ret[j] = malloc(sizeof(t_coord));
			ret[j]->x = node[j]->x;
			ret[j]->y = node[j]->y;
			ret[j]->z = node[j]->z;
			j++;
		}
	}
	i = 0;
	while (string_arr[i] != NULL)
	{
		ret[j] = malloc(sizeof(t_coord));
		ret[j]->x = i;
		ret[j]->y = row;
		ret[j]->z = ft_atoi(string_arr[i]);
		i++;
		j++;
	}
	ret[j] = NULL;
	free_struct_arr(node);
	free_string_arr(string_arr);
	return (ret);
}

t_coord	**get_coordinates(char *file)
{
	char	*string;
	int		fd;
	int		row;
	t_coord	**node;

	row = 0;
	node = NULL;
	fd = open(file, O_RDONLY); // remb to handle error later
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

void	scale(t_coord **node, double xy_offset, double z_offset)
{
	int	i;

	i = 0;
	while (node[i] != NULL)
	{
		node[i]->x = xy_offset * node[i]->x;
		node[i]->y = xy_offset * node[i]->y;
		node[i]->z = z_offset * node[i]->z;
		i++;
	}
}

void	render(t_coord **node, t_xyaxis map_size, t_data data)
{
	t_xyaxis	p1;
	t_xyaxis	p2;
	int	i;
	int	j;
	int	k;

	j = 0;
	i = 0;
	while (j < map_size.y)
	{
		k = 0;
		while (k < map_size.x)
		{
			//printf("\ni:%d\n", i);
			if (j == map_size.y - 1)
			{
				if (k == map_size.x - 1)
					break ;
				p1.x = node[i]->x;
				p1.y = node[i]->y;
				p2.x = node[i + 1]->x;
				p2.y = node[i + 1]->y;
				plot_line(p1, p2, data);
			}
			else if (k == map_size.x - 1)
			{
				p1.x = node[i]->x;
				p1.y = node[i]->y;
				p2.x = node[i + map_size.x]->x;
				p2.y = node[i + map_size.x]->y;
				plot_line(p1, p2, data);
			}
			else
			{
				p1.x = node[i]->x;
				p1.y = node[i]->y;
				p2.x = node[i + 1]->x;
				p2.y = node[i + 1]->y;
				plot_line(p1, p2, data);
				p1.x = node[i]->x;
				p1.y = node[i]->y;
				p2.x = node[i + map_size.x]->x;
				p2.y = node[i + map_size.x]->y;
				plot_line(p1, p2, data);
			}
			k++;
			i++;
		}
		j++;
	}
}

void	project_node(t_coord **node)
{
	int	i;
	int	f;
	
	f = 600;
	i = 0;
	while (node[i] != NULL)
	{
		double scalingFactor = 20.0 / (20.0 + 0.1 * node[i]->z);
		printf("nodez:%d\n", node[i]->z);
		node[i]->x *= scalingFactor;
		node[i]->y *= scalingFactor;
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_data	data;

	// init
	if (argc != 2)
		return (0);
	data.win_size.x = 1000;
	data.win_size.y = 1000;
	data.zoom_xy = 30;
	data.zoom_z = data.zoom_xy / 8;
	data.mlx = mlx_init ();
	data.win = mlx_new_window (data.mlx, data.win_size.x, data.win_size.y, "ateow_fdf");
	
	data.node = get_coordinates(argv[1]);
	get_map_size(data.node, &(data.map_size));
	scale(data.node, data.zoom_xy, data.zoom_z);
	translate_orgin(data.node, data.map_size);
	
	data.node_org = get_coordinates(argv[1]);
	get_map_size(data.node_org, &(data.map_size));
	scale(data.node_org, data.zoom_xy, data.zoom_z);
	translate_orgin(data.node_org, data.map_size);

	rotate_node_default(&data);
	translate_center(&data);

	render(data.node, data.map_size, data);
	
	// exit

	mlx_key_hook(data.win, key_hook, &data);
	mlx_hook(data.win, 17, 0, close_window, &data);
	
	//mouse
	mlx_hook(data.win, 4, (1L<<2), mouse_press, &data);
	mlx_hook(data.win, 5, (1L<<3), mouse_release, &data);

	
	mlx_loop(data.mlx);
	free_struct_arr(data.node);
	free_struct_arr(data.node_org);
	return (0);
}

/*
	printf("row:%d\n", map_size.x);
	printf("col:%d\n", map_size.y);
	
	
	t_coord	**rotate_node(t_coord **node, t_xyaxis map_size)
{
	t_matrix	rot_x_matrix;
	t_matrix	rot_y_matrix;
	t_matrix	rot_z_matrix;
	t_coord		**temp_node;
	int	i;
	double	angle_x;
	double	angle_y;
	double	angle_z;

    	angle_x = 10 * M_PI / 180; // Convert degrees to radians
	angle_y = 45 * M_PI / 180;
	angle_z = 40 * M_PI / 180;

	rot_x_matrix.r1[0] = 1;
	rot_x_matrix.r1[1] = 0;
	rot_x_matrix.r1[2] = 0;
	rot_x_matrix.r2[0] = 0;
	rot_x_matrix.r2[1] = cos(angle_x);
	rot_x_matrix.r2[2] = -sin(angle_x);
	rot_x_matrix.r3[0] = 0;
	rot_x_matrix.r3[1] = sin(angle_x);
	rot_x_matrix.r3[2] = cos(angle_x);

	rot_y_matrix.r1[0] = cos(angle_y);
	rot_y_matrix.r1[1] = 0;
	rot_y_matrix.r1[2] = sin(angle_y);
	rot_y_matrix.r2[0] = 0;
	rot_y_matrix.r2[1] = 1;
	rot_y_matrix.r2[2] = 0;
	rot_y_matrix.r3[0] = -sin(angle_y);
	rot_y_matrix.r3[1] = 0;
	rot_y_matrix.r3[2] = cos(angle_y);

	rot_z_matrix.r1[0] = cos(angle_z);
	rot_z_matrix.r1[1] = -sin(angle_z);
	rot_z_matrix.r1[2] = 0;
	rot_z_matrix.r2[0] = sin(angle_z);
	rot_z_matrix.r2[1] = cos(angle_z);
	rot_z_matrix.r2[2] = 0;
	rot_z_matrix.r3[0] = 0;
	rot_z_matrix.r3[1] = 0;
	rot_z_matrix.r3[2] = 1;

	temp_node = malloc(sizeof(t_coord) * ((map_size.x * map_size.y) + 1));
	i = 0;
	while (node[i] != NULL)
	{
		//ft_rotate_x(&node[i]->y, &node[i]->z, angle_x);
		//ft_rotate_y(&node[i]->x, &node[i]->z, angle_y);
		//ft_rotate_z(&node[i]->x, &node[i]->y, angle_z);
		printf("rot:%4f\n", rot_x_matrix.r2[1]);
		temp_node[i] = malloc(sizeof(t_coord));
		temp_node[i]->x = (rot_x_matrix.r1[0] * node[i]->x) + (rot_x_matrix.r1[1] * node[i]->y) + (rot_x_matrix.r1[2] * node[i]->z);
		temp_node[i]->y = (rot_x_matrix.r2[0] * node[i]->x) + (rot_x_matrix.r2[1] * node[i]->y) + (rot_x_matrix.r2[2] * node[i]->z);
		temp_node[i]->z = (rot_x_matrix.r3[0] * node[i]->x) + (rot_x_matrix.r3[1] * node[i]->y) + (rot_x_matrix.r3[2] * node[i]->z);

		int x = temp_node[i]->x;
		temp_node[i]->x = (rot_y_matrix.r1[0] * x) + (rot_y_matrix.r1[1] * temp_node[i]->y) + (rot_z_matrix.r1[2] * temp_node[i]->z);
		//temp_node[i]->y = (rot_y_matrix.r2[0] * x) + (rot_y_matrix.r2[1] * temp_node[i]->y) + (rot_z_matrix.r2[2] * temp_node[i]->z);
		temp_node[i]->z = (rot_y_matrix.r3[0] * x) + (rot_y_matrix.r3[1] * temp_node[i]->y) + (rot_z_matrix.r3[2] * temp_node[i]->z);
		
		x = temp_node[i]->x;
		int y = temp_node[i]->y;
		temp_node[i]->x = (rot_z_matrix.r1[0] * x) + (rot_z_matrix.r1[1] * y) + (rot_z_matrix.r1[2] * temp_node[i]->z);
		temp_node[i]->y = (rot_z_matrix.r2[0] * x) + (rot_z_matrix.r2[1] * y) + (rot_z_matrix.r2[2] * temp_node[i]->z);
		//temp_node[i]->z = (rot_z_matrix.r3[0] * x) + (rot_z_matrix.r3[1] * y) + (rot_z_matrix.r3[2] * temp_node[i]->z);


		
		//printf("ROT_NODE >> x:%d | y:%d | z:%d\n", temp_node[i]->x, temp_node[i]->y, temp_node[i]->z);
		i++;
	}
	temp_node[i] = NULL;
	free_struct_arr(node);
	return (temp_node);
}
*/
/*
void	translate_position(t_coord **node, t_xyaxis win_size, int x, int y)
{
	int	i;
	t_coord	smallest;
	t_coord	largest;

	i = 0;
	smallest.x = node[i]->x;
	smallest.y = node[i]->y;
	largest.x = node[i]->x;
	largest.y = node[i]->y;
	while (node[i] != NULL)
	{
		if (node[i]->x < smallest.x)
			smallest.x  = node[i]->x;
		if (node[i]->y < smallest.y)
			smallest.y = node[i]->y;
		if (node[i]->x > largest.x)
			largest.x  = node[i]->x;
		if (node[i]->y > largest.y)
			largest.y = node[i]->y;
		i++;
	}
	i = 0;
	while (node[i] != NULL)
	{
		node[i]->x = node[i]->x - smallest.x - ((largest.x - smallest.x) / 2) + x;
		node[i]->y = node[i]->y - smallest.y - ((largest.y - smallest.y) / 2) + y;
		i++;
	}
}
*/
