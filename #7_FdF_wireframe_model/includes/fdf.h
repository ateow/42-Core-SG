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

typedef struct s_angle
{
	double	x;
	double	y;
	double	z;
}	t_angle;


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

typedef struct s_data
{
	void		*mlx;
	void		*win;
	int			mouse_x;
	int			mouse_y;
	int			click_drag_x;
	int			click_drag_y;
	int			middle_drag_x;
	int			middle_drag_y;
	int			center_x;
	int			center_y;
	double			zoom_xy;
	double			zoom_z;
	t_angle		angle;
	t_coord		**node;
	t_coord		**node_org;
	t_xyaxis	win_size;
	t_xyaxis	map_size;
}	t_data;

int		close_window(t_data data);
int		key_hook(int keycode, t_data *data);
int		mouse_press(int button, int x, int y, t_data *data);
int		mouse_release(int button, int x, int y, t_data *data);
int		mouse_move(int button, int x, int y, t_data *data);
void	free_struct_arr(t_coord **arr);
void	free_string_arr(char **arr);

void	plot_line_low(t_xyaxis p1, t_xyaxis p2, t_data data);
void	plot_line_high(t_xyaxis p1, t_xyaxis p2, t_data data);
void	plot_line(t_xyaxis p1, t_xyaxis p2, t_data data);

void	render(t_coord **node, t_xyaxis map_size, t_data data);

void	translate_orgin(t_coord **node, t_xyaxis map_size);
void	translate_center(t_data *data);
void	translate_position(t_data *data, int x, int y);

void	rotate_node_default(t_data *data);
void	rotate_node(t_data *data, int x, int y);
void	rotate_node_z(t_data *data, int keycode);

void	scale(t_coord **node, double xy_offset, double z_offset);

#endif
