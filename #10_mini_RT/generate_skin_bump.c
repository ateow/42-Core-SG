/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_skin_bump.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 03:16:56 by kali              #+#    #+#             */
/*   Updated: 2024/01/27 03:23:50 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	get_xpm_img_data(t_params *p, t_skin *skin, char *path)
{
	skin->img_ptr = mlx_xpm_file_to_image(p->vars.mlx,
			path, &skin->width, &skin->height);
	skin->data = (int *)mlx_get_data_addr(skin->img_ptr, &skin->bpp,
			&skin->size, &skin->endian);
}

void	generate_texture_moon(t_params *p)
{
	int	fd;
	int	fd2;

	fd = open("./texture_maps/moon.xpm", O_RDONLY);
	if (fd == -1)
	{
		put_error("./texture_maps/moon.xpm error");
		p->f->has_moon = 0;
		p->f->has_moon_bump = 0;
		return ;
	}
	close(fd);
	get_xpm_img_data(p, &(p->moon), "./texture_maps/moon.xpm");
	fd2 = open("./texture_maps/moon_normal_map.xpm", O_RDONLY);
	if (fd2 == -1)
	{
		put_error("./texture_maps/moon_normal_map.xpm error");
		p->f->has_moon_bump = 0;
		return ;
	}
	close(fd2);
	get_xpm_img_data(p, &(p->moon_bump), "./texture_maps/moon_normal_map.xpm");
}

void	generate_texture_earth(t_params *p)
{
	int	fd;
	int	fd2;

	fd = open("./texture_maps/earth.xpm", O_RDONLY);
	if (fd == -1)
	{
		put_error("./texture_maps/earth.xpm error");
		p->f->has_earth = 0;
		p->f->has_earth_bump = 0;
		return ;
	}
	close(fd);
	get_xpm_img_data(p, &(p->earth), "./texture_maps/earth.xpm");
	fd2 = open("./texture_maps/earth_normal_map.xpm", O_RDONLY);
	if (fd2 == -1)
	{
		put_error("./texture_maps/earth_normal_map.xpm error");
		p->f->has_earth_bump = 0;
		return ;
	}
	close(fd2);
	get_xpm_img_data(p, &(p->earth_bump),
		"./texture_maps/earth_normal_map.xpm");
}

void	generate_texture_sun(t_params *p)
{
	int	fd;
	int	fd2;

	fd = open("./texture_maps/sun.xpm", O_RDONLY);
	if (fd == -1)
	{
		put_error("./texture_maps/sun.xpm error");
		p->f->has_sun = 0;
		p->f->has_sun_bump = 0;
		return ;
	}
	close(fd);
	get_xpm_img_data(p, &(p->sun), "./texture_maps/sun.xpm");
	fd2 = open("./texture_maps/sun_normal_map.xpm", O_RDONLY);
	if (fd2 == -1)
	{
		put_error("./texture_maps/sun_normal_map.xpm error");
		p->f->has_sun_bump = 0;
		return ;
	}
	close(fd2);
	get_xpm_img_data(p, &(p->sun_bump), "./texture_maps/sun_normal_map.xpm");
}

void	generate_texture(t_params *p)
{
	if (p->f->has_moon == 1)
		generate_texture_moon(p);
	if (p->f->has_earth == 1)
		generate_texture_earth(p);
	if (p->f->has_sun == 1)
		generate_texture_sun(p);
}
