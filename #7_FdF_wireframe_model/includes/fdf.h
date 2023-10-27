/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ateow <ateow@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 10:54:06 by ateow             #+#    #+#             */
/*   Updated: 2023/10/22 10:54:08 by ateow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct s_vars
{
	void	*mlx;
	void	*win;
}	t_vars;

typedef struct s_coord
{
	int	x;
	int	y;
	int	z;
}	t_coord;

typedef struct s_xyaxis
{
	int	x;
	int	y;
}	t_xyaxis;

typedef struct s_plot_line
{
	int	diffx;
	int	diffy;
	int	i;
	int	d;
}	t_plot_line;

typedef struct s_matrix
{
	double	r1[3];
	double	r2[3];
	double	r3[3];
	double	r4[3];
}	t_matrix;

int		close_window(t_vars *vars);
int		key_hook(int keycode, t_vars *vars);
void	free_struct_arr(t_coord **arr);
void	free_string_arr(char **arr);

void	plot_line_low(t_xyaxis p1, t_xyaxis p2, t_vars vars);
void	plot_line_high(t_xyaxis p1, t_xyaxis p2, t_vars vars);
void	plot_line(t_xyaxis p1, t_xyaxis p2, t_vars vars);

void	rotate_node(t_coord **node);
#endif
