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

void	scale(t_coord **node, int xy_offset, int z_offset)
{
	int			i;

	i = 0;
	while (node[i] != NULL)
	{
		node[i]->x = xy_offset * node[i]->x;
		node[i]->y = xy_offset * node[i]->y;
		node[i]->z = z_offset * node[i]->z;
		//printf("SCALE(temp) >> x:%d | y:%d | z:%d\n", node[i]->x, node[i]->y, node[i]->z);
		//printf("SCALE(node) >> x:%d | y:%d | z:%d\n", temp_node[i]->x, temp_node[i]->y, temp_node[i]->z);
		i++;
	}
}

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

void	translate_center(t_coord **node, t_xyaxis win_size)
{
	int	i;
	//int	x_offset;
	//int	y_offset;
	/*
	i = 0;
	x_offset = 0;
	y_offset = 0;
	while (node[i] != NULL)
	{
		if (node[i]->x < x_offset)
			x_offset = node[i]->x;
		if (node[i]->y < y_offset)
			y_offset = node[i]->y;		
		i++;
	}
	x_offset = x_offset * -1;
	y_offset = y_offset * -1;
	i = 0;
	while (node[i] != NULL)
	{
		node[i]->x = node[i]->x + x_offset;
		node[i]->y = node[i]->y + y_offset;
		i++;
	}
	*/
	i = 0;
	while (node[i] != NULL)
	{
		node[i]->x = node[i]->x + (win_size.x / 2);
		node[i]->y = node[i]->y + (win_size.y / 2);
		i++;
	}

}
void	render(t_coord **node, t_xyaxis map_size, t_vars vars)
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
				plot_line(p1, p2, vars);
			}
			else if (k == map_size.x - 1)
			{
				p1.x = node[i]->x;
				p1.y = node[i]->y;
				p2.x = node[i + map_size.x]->x;
				p2.y = node[i + map_size.x]->y;
				plot_line(p1, p2, vars);
			}
			else
			{
				p1.x = node[i]->x;
				p1.y = node[i]->y;
				p2.x = node[i + 1]->x;
				p2.y = node[i + 1]->y;
				plot_line(p1, p2, vars);
				p1.x = node[i]->x;
				p1.y = node[i]->y;
				p2.x = node[i + map_size.x]->x;
				p2.y = node[i + map_size.x]->y;
				plot_line(p1, p2, vars);
			}
			k++;
			i++;
		}
		j++;
	}
}

t_coord	**project_node(t_coord **node, t_xyaxis map_size)
{
	t_matrix	p_matrix;
	t_coord		**temp_node;
	int	i;

	p_matrix.r1[0] = 0.7071;  // 1/sqrt(2)
	p_matrix.r1[1] = 0.4082;  // 1/sqrt(6)
	p_matrix.r1[2] = 0.5774;  // 1/sqrt(3)
	p_matrix.r2[0] = -0.7071;  // -1/sqrt(2)
	p_matrix.r2[1] = 0.4082;  // 1/sqrt(6)
	p_matrix.r2[2] = 0.5774;  // 1/sqrt(3)
	p_matrix.r3[0] = 0;       // 0
	p_matrix.r3[1] = -0.8165;  // -2/sqrt(6)
	p_matrix.r3[2] = 0.5774;  // 1/sqrt(3)

	temp_node = malloc(sizeof(t_coord) * ((map_size.x * map_size.y) + 1));
	i = 0;
	while (node[i] != NULL)
	{
		temp_node[i] = malloc(sizeof(t_coord));
		temp_node[i]->x = (p_matrix.r1[0] * node[i]->x) + (p_matrix.r1[1] * node[i]->y) + (p_matrix.r1[2] * node[i]->z);
		temp_node[i]->y = (p_matrix.r2[0] * node[i]->x) + (p_matrix.r2[1] * node[i]->y) + (p_matrix.r2[2] * node[i]->z);
		//printf("PROJECTNODE >> x:%d | y:%d | z:%d\n", temp_node[i]->x, temp_node[i]->y, temp_node[i]->z);
		i++;
	}
	temp_node[i] = NULL;
	free_struct_arr(node);
	return (temp_node);
}

int	main(int argc, char **argv)
{
	t_vars	vars;
	t_coord	**node;
	t_xyaxis	win_size;
	t_xyaxis	map_size;
	int	xy_offset;
	int	z_offset;
	// init
	if (argc != 2)
		return (0);
	win_size.x = 1000;
	win_size.y = 1000;
	xy_offset = 20;
	z_offset = xy_offset / 8;
	vars.mlx = mlx_init ();
	vars.win = mlx_new_window (vars.mlx, win_size.x, win_size.y, "ateow_fdf");
	
	node = get_coordinates(argv[1]);
	get_map_size(node, &map_size);
	scale(node, xy_offset, z_offset);
	translate_orgin(node, map_size);
	rotate_node(node);
	translate_center(node, win_size);

	//node = project_node(node, map_size);
	render(node, map_size, vars);

	// exit
	mlx_key_hook(vars.win, &key_hook, &vars);
	mlx_hook(vars.win, 17, 0, &close_window, &vars);
	mlx_loop(vars.mlx);
	free_struct_arr(node);
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
