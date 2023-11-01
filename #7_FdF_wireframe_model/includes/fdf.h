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
	char		*map_info;
	int			mouse_x;
	int			mouse_y;
	int			click_drag_x;
	int			click_drag_y;
	int			middle_drag_x;
	int			middle_drag_y;
	int			rot_axis_x;
	int			rot_axis_y;
	double		zoom_xy;
	double		zoom_z;
	int			counter_scale;
	int			counter_zoom;
	t_angle		angle;
	t_coord		**node;
	t_coord		**node_org;
	t_xyaxis	win_size;
	t_xyaxis	map_size;
}	t_data;

void	project_default(t_data *data);
void	project_iso(t_data *data);
void	project_top(t_data *data);
void	project_front(t_data *data);
void	project_side(t_data *data);

t_coord	**create_node(char *string, t_coord **node, int row);
void	get_map_size(t_coord **node, t_xyaxis *map_size);
t_coord	**get_coordinates(char *file);

void	render(t_data data);
void	scale(t_coord **node, double xy_offset, double z_offset);
void	adjust_altitude(int keycode, t_data *data);
void	ajust_scale(int button, t_data *data);

t_coord	update_center(t_data *data);
void	plot_line_low(t_xyaxis p1, t_xyaxis p2, t_data data);
void	plot_line_high(t_xyaxis p1, t_xyaxis p2, t_data data);
void	plot_line(t_xyaxis p1, t_xyaxis p2, t_data data);

void	translate_orgin(t_coord **node, t_xyaxis map_size);
void	translate_center(t_data *data);
void	translate_position(t_data *data, int x, int y);

void	rotate_x(int *y, int *z, double angle_x);
void	rotate_y(int *x, int *z, int *y, double angle_y);
void	rotate_z(int *x, int *y, double angle_z);
void	rotate_node_default(t_data *data);
void	rotate_node(t_data *data, int x, int y);
void	rotate_node_z(t_data *data, int keycode);
void	rotate_node_scale(t_data *data);

int		close_window(t_data *data);
int		key_hook(int keycode, t_data *data);
int		mouse_press(int button, int x, int y, t_data *data);
int		mouse_release(int button, int x, int y, t_data *data);
int		mouse_move(int button, int x, int y, t_data *data);
void	free_struct_arr(t_coord **arr);
void	free_string_arr(char **arr);

#endif
