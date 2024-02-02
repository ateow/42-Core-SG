/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 10:24:58 by cooi              #+#    #+#             */
/*   Updated: 2024/01/28 02:46:12 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "libft/libft.h"
# include "mlx_linux/mlx.h"
# include "mlx_linux/mlx_int.h"
# include <stdio.h>
# include <stdlib.h>
# include <stddef.h>
# include <unistd.h>
# include <errno.h>
# include <fcntl.h>
# include <math.h>

# ifndef PI
#  define PI 3.14159265
# endif

typedef struct s_rt			t_rt;

typedef struct s_vars {
	void	*mlx;
	void	*win;
}	t_vars;

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_skin
{
	void	*img_ptr;
	int		*data;
	int		width;
	int		height;
	char	*path;
	int		bpp;
	int		endian;
	int		size;
}	t_skin;

typedef struct s_params {
	t_data	img;
	t_vars	vars;
	t_rt	*f;
	int		wx;
	int		wy;
	int		o_wx;
	int		o_wy;
	t_skin	moon;
	t_skin	moon_bump;
	t_skin	earth;
	t_skin	earth_bump;
	t_skin	sun;
	t_skin	sun_bump;
}	t_params;

typedef struct s_xyz {
	float	x;
	float	y;
	float	z;
}	t_xyz;

typedef struct s_xyz_strings {
	char	*x;
	char	*y;
	char	*z;
	char	*nx;
	char	*ny;
	char	*nz;
	char	*d;
	char	*h;
}	t_xyz_strings;

typedef struct s_quat {
	float	w;
	float	x;
	float	y;
	float	z;
}	t_quat;

typedef struct s_trace {
	float	kd;
	float	ks;
	float	bright;
	int		diffuse;
	int		specular;
}	t_trace;

typedef struct s_inter {
	t_xyz	surfnorm;
	t_xyz	inter;
	t_xyz	tolight;
}	t_inter;

typedef struct s_ambient {
	float	lum;
	int		rgb;
}	t_ambient;

typedef struct s_camera {
	t_xyz	pos;
	t_xyz	dir;
	float	fov;
}	t_camera;

typedef struct s_light		t_light;
typedef struct s_sphere		t_sphere;
typedef struct s_plane		t_plane;
typedef struct s_cylinder	t_cylinder;

typedef struct s_light {
	t_xyz	pos;
	float	lum;
	int		rgb;
	t_light	*next;
}	t_light;

typedef struct s_cb
{
	int			rgb1;
	int			rgb2;
	int			width;
	int			height;
	int			tilesize;
	float		uv[2];
}	t_cb;

typedef struct s_sphere {
	int			rgb;
	t_xyz		pos;
	float		d;
	int			is_checkered;
	int			has_skin;
	t_cb		cb;
	int			skin_type;
}	t_sphere;

typedef struct s_plane {
	int		rgb;
	t_xyz	pos;
	t_xyz	i_nor;
	t_xyz	nor;
}	t_plane;

typedef struct s_cylinder {
	int		rgb;
	t_xyz	pos;
	float	d;
	t_xyz	i_nor;
	t_xyz	nor;
	float	h;
	t_xyz	p1;
	t_xyz	p2;
	float	sqt_radius;
}	t_cylinder;

typedef struct s_cone {
	int		rgb;
	t_xyz	pos;
	float	d;
	t_xyz	i_nor;
	t_xyz	nor;
	float	h;
	float	cos2;
	float	half_angle;
	t_xyz	pt_top;
	t_xyz	pt_btt;
	float	rad_top;
	float	rad_btt;
}	t_cone;

typedef struct s_quadratic {
	float	a;
	float	b;
	float	c;
	float	delta;
	float	t1;
	float	t2;
}	t_quadratic;

typedef struct s_hittable	t_hittable;

typedef struct s_hittable {
	void		*obj;
	char		*type;
	int			id;
	t_hittable	*next;
	t_hittable	*prev;
}	t_hittable;

typedef struct s_rt {
	t_ambient	*a;
	t_camera	*c;
	t_light		*l;
	t_hittable	*objs;
	int			has_moon;
	int			has_earth;
	int			has_sun;
	int			has_moon_bump;
	int			has_earth_bump;
	int			has_sun_bump;
}	t_rt;

//colour.c
int		create_argb(int a, int r, int g, int b);
int		get_a(int argb);
int		get_r(int argb);
int		get_g(int argb);
int		get_b(int argb);

//close.c
int		close_program(t_params *params);
void	regenerate_image(t_params *params);
int		key_hook(int keycode, t_params *params);
void	generate_image(t_params *p);

//render_utils.c
void	my_mlx_pixel_put(t_data *dat, int x, int y, int color);
void	clear_scene(t_params *params);

//rgb_math_0.c
int		lerp(int low, int high, float t);
int		scale_rgb(int rgb, float x);
int		add_rgb(int rgb, int rgb2);
int		mul_rgb(int rgb, int rgb2);

//xyz_math_0.c
t_xyz	scale_xyz(t_xyz a, float b);
t_xyz	add_xyz(t_xyz a, t_xyz b);
t_xyz	subtract_xyz(t_xyz a, t_xyz b);
t_xyz	multiply_xyz(t_xyz v, float f);
t_xyz	reflect(t_xyz ray, t_xyz normal);

//xyz_math_1.c
float	dot(t_xyz a, t_xyz b);
float	length(t_xyz v);
t_xyz	normalize(t_xyz v);
t_xyz	cross_prod(t_xyz v1, t_xyz v2);
float	distance(t_xyz a, t_xyz b);

//main.c
void	render_scene(t_params *params);
int		trace_ray(t_params *params, t_xyz ray);
float	get_intersection(t_xyz origin, t_xyz ray, t_hittable *obj);

//intersection
t_xyz	intersect_pos(t_xyz ro, t_xyz rd, float t);
int		solve_quadratic(t_quadratic *q);
float	get_intersection(t_xyz origin, t_xyz ray, t_hittable *obj);
float	plane_intersection(t_xyz ro, t_xyz rd, t_xyz pp, t_xyz pn);
float	intersect_cylinder(t_xyz origin, t_xyz ray, t_hittable *obj);
float	intersect_plane(t_xyz origin, t_xyz ray, t_hittable *obj);
float	intersect_sphere(t_xyz origin, t_xyz ray, t_hittable *obj);
float	intersect_cone(t_xyz origin, t_xyz ray, t_hittable *obj);

//rotate.c
t_quat	cquat(float angle, float axisX, float axisY, float axisZ);
t_quat	mquat(t_quat q1, t_quat q2);
t_xyz	rotate(t_xyz p, t_quat Quaternion);
t_xyz	rot_vector_to_cam_normal(t_xyz z_norm, t_xyz vec, t_xyz cam_nor);

//readfile_0.c
t_rt	*open_scene(char **argv);
void	read_scene(t_rt **f, int fd);
int		parse_object(t_rt **f, char **split);
void	put_error(char *str);

//freestruct_0.c
void	free_rt(t_rt **f);
void	free_lights(t_light *l);
void	free_hittable(t_hittable *objs);

//makestruct_0.c
int		check_vector(t_xyz xyz);
int		check_rgb(t_xyz rgb);
char	**validate_xyz(char *str, int c);
int		check_float(char *str, int c);
int		get_xyz(t_xyz *xyz, char *str, int c);

//makestruct_scene.c
int		get_ambient(t_rt **f, char **split);
int		get_camera(t_rt **f, char **split);
void	add_hittable(t_rt **f, void *obj, char *type);

//makestruct_lights.c
int		get_light(t_rt **f, char **split);
void	append_light(t_rt **f, t_light *l);

//makestruct_sphere.c
int		get_sphere(t_rt **f, char **split);
void	append_sphere(t_rt **f, t_sphere *sp);

//makestruct_plane.c
int		get_plane(t_rt **f, char **split);
void	append_plane(t_rt **f, t_plane *pl);

//makestruct_cylinder.c
int		get_cylinder(t_rt **f, char **split);
void	append_cylinder(t_rt **f, t_cylinder *cy);

//makestruct_cone.c
int		get_cone(t_rt **f, char **split);

//debug_utils.c
void	print_rt(t_rt *f);
void	print_rgb(int rgb);
void	print_xyz(t_xyz a);

//trace_light_ray.c
int		trace_ray_lights(t_params *params, t_xyz ray, t_hittable *obj, float t);
int		check_shadowed(t_params *params, t_inter in, int id);
int		get_specular_diffuse(t_inter in, t_light *light, int rgb, t_xyz ray);
t_xyz	get_cone_surfacenorm(t_inter in, t_cone *co);
t_xyz	get_cylinder_surfacenorm(t_inter in, t_cylinder *cy);

//main
void	generate_image(t_params *p);
void	render_scene(t_params *params);

//UI
void	draw_rectangle(void *mlx, void *win, int width, int height);
int		close_program(t_params *params);
int		key_hook(int keycode, t_params *p);
void	objects_menu(t_params *p);
void	objects_menu_plane(t_params *p);
void	objects_menu_sphere(t_params *p);
void	objects_menu_cylinder(t_params *p);
void	objects_menu_cone(t_params *p);
void	display_pos_controls(t_params *p);
void	display_nor_controls(t_params *p);
void	display_dia_controls(t_params *p);
void	display_height_controls(t_params *p);
int		key_hook_objects(int keycode, t_params *p);
int		key_hook_resize(int keycode, t_params *p);
void	key_hook_object_controls_cone(int keycode, t_params *p);
void	key_hook_object_controls_sphere(int keycode, t_params *p);
void	key_hook_object_controls_cylinder(int keycode, t_params *p);
void	key_hook_object_controls_plane(int keycode, t_params *p);
void	windows_resize_menu(t_params *p);
void	free_display(t_xyz_strings s);

// texture c
void	generate_texture(t_params *p);
t_xyz	sphere_mapping(t_xyz inter, t_xyz cam_orient, t_sphere *sp);
int		map_cb_texture(t_xyz inter, t_xyz cam_orient, t_sphere *sp);
int		map_skin_texture(t_params *p, t_xyz inter,
			t_xyz cam_orient, t_sphere *sp);
t_xyz	map_skin_bump(t_params *p, t_inter in, t_xyz cam_orient, t_sphere *sp);

#endif