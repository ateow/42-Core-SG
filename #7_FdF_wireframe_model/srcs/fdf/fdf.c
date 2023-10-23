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

int	main(int argc, char **argv)
{
	int		size_x;
	int		size_y;
	t_vars	vars;
	t_coord	**node;

	// init
	if (argc != 2)
		return (0);
	size_x = 1000;
	size_y = 1000;
	vars.mlx = mlx_init ();
	vars.win = mlx_new_window (vars.mlx, size_x, size_y, "ateow_fdf");

	node = get_coordinates(argv[1]);
	
	t_xyaxis	p1;
	t_xyaxis	p2;
	int	i;
	int	j;
	int	row;
	int	offset;
	offset = 20;
	i = 0;
	j = 0;
	row = 0;
	while (j < 10)
	{
		while (node[i+1]->y == row)
		{
			
			p1.x = offset * node[i]->x;
			p1.y = offset * node[i]->y;
			p2.x = offset * node[i+1]->x;
			p2.y = offset * node[i+1]->y;
			plot_line(p1, p2, vars);
			printf("p1[%d].x:%d | p1[%d].y:%d\n", i, p1.x, i, p1.y);
			printf("p2[%d].x:%d | p2[%d].y:%d\n", i, p2.x, i, p2.y);
			printf("\n");
			p1.x = offset * node[i]->x;
			p1.y = offset * node[i]->y;
			p2.x = offset * node[i+19]->x;
			p2.y = offset * node[i+19]->y;
			plot_line(p1, p2, vars);
			i++;
		}
		row++;
		i++;
		j++;
	}
	// exit
	mlx_key_hook(vars.win, &key_hook, &vars);
	mlx_hook(vars.win, 17, 0, &close_window, &vars);
	mlx_loop(vars.mlx);
	free_struct_arr(node);
	return (0);
}
