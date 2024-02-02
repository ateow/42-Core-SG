/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ateow <ateow@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 10:24:33 by cooi              #+#    #+#             */
/*   Updated: 2024/01/31 17:02:32 by ateow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_xyz	camera_ray(t_params *params, int i, int j)
{
	float	inc;
	t_quat	rot;
	t_xyz	rot2;
	t_xyz	normal;

	if (params->wx > params->wy)
		inc = params->f->c->fov / params->wy;
	else
		inc = params->f->c->fov / params->wx;
	inc = PI / 180 * inc;
	rot = mquat(cquat((i - params->wx / 2) * inc, -1, 0, 0),
			cquat((j - params->wy / 2) * inc, 0, -1, 0));
	normal.x = 0;
	normal.y = 0;
	normal.z = 1;
	rot2.x = rot.x;
	rot2.y = rot.y;
	rot2.z = rot.z;
	rot2 = rot_vector_to_cam_normal(normal, rot2, params->f->c->dir);
	rot.x = rot2.x;
	rot.y = rot2.y;
	rot.z = rot2.z;
	return (rotate(params->f->c->dir, rot));
}

int	trace_ray(t_params *params, t_xyz ray)
{
	float		t;
	float		t_min;
	int			rgb;
	t_hittable	*tmp;
	t_hittable	*front;

	tmp = params->f->objs;
	t_min = 0;
	while (tmp)
	{
		t = get_intersection(params->f->c->pos, ray, tmp);
		if (t > 0 && (t < t_min || t_min == 0))
		{
			t_min = t;
			front = tmp;
		}
		tmp = tmp->next;
	}
	if (t_min <= 0)
		return (create_argb(255, 0, 0, 0));
	t = get_intersection(params->f->c->pos, ray, front);
	rgb = trace_ray_lights(params, ray, front, t);
	return (rgb);
}

void	render_scene(t_params *params)
{
	int		xi;
	int		yi;
	int		rgb;
	t_xyz	ray;

	clear_scene(params);
	xi = 0;
	while (xi < params->wx)
	{
		yi = 0;
		while (yi < params->wy)
		{
			ray = camera_ray(params, xi, yi);
			rgb = trace_ray(params, ray);
			my_mlx_pixel_put(&params->img, xi, yi, rgb);
			yi++;
		}
		xi++;
	}
	mlx_put_image_to_window(params->vars.mlx,
		params->vars.win, params->img.img, 0, 0);
}

void	generate_image(t_params *p)
{
	p->vars.mlx = mlx_init();
	p->vars.win = mlx_new_window(p->vars.mlx, p->wx, p->wy, "da_ray");
	p->img.img = mlx_new_image(p->vars.mlx, p->wx, p->wy);
	p->img.addr = mlx_get_data_addr(p->img.img, &p->img.bits_per_pixel,
			&p->img.line_length, &p->img.endian);
	generate_texture(p);
	render_scene(p);
	mlx_key_hook(p->vars.win, key_hook, p);
	mlx_hook(p->vars.win, 17, 0, close_program, p);
	mlx_loop(p->vars.mlx);
}

int	main(int argc, char **argv)
{
	t_params	p;

	if (argc != 2 || (ft_strlen(argv[1]) >= 3
			&& ft_strncmp(argv[1] + ft_strlen(argv[1]) - 3, ".rt", 3) != 0))
		put_error("Error\ninvalid inputs\n");
	else
	{
		p.f = open_scene(argv);
		if (!p.f)
			exit (1);
		p.wx = 800;
		p.wy = 600;
		generate_image(&p);
	}
	return (0);
}
