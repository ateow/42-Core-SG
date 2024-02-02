/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_objs_cylinder_control.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ateow <ateow@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 18:18:23 by ateow             #+#    #+#             */
/*   Updated: 2024/01/21 19:42:56 by ateow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	key_hook_cylinder_controls_pos(int keycode, void *a)
{
	t_cylinder	*o;

	o = a;
	if (keycode == 97)
		o->pos.x += 1;
	if (keycode == 122)
		o->pos.x -= 1;
	if (keycode == 115)
		o->pos.y += 1;
	if (keycode == 120)
		o->pos.y -= 1;
	if (keycode == 100)
		o->pos.z += 1;
	if (keycode == 99)
		o->pos.z -= 1;
}

void	key_hook_cylinder_controls_nor(int keycode, void *a)
{
	t_cylinder	*o;

	o = a;
	if (keycode == 102)
		o->i_nor.x += 1;
	if (keycode == 118)
		o->i_nor.x -= 1;
	if (keycode == 103)
		o->i_nor.y += 1;
	if (keycode == 98)
		o->i_nor.y -= 1;
	if (keycode == 104)
		o->i_nor.z += 1;
	if (keycode == 110)
		o->i_nor.z -= 1;
}

void	key_hook_cylinder_controls_dia(int keycode, void *a)
{
	t_cylinder	*o;

	o = a;
	if (keycode == 106)
		o->d += 1;
	if (keycode == 109)
		o->d -= 1;
}

void	key_hook_cylinder_controls_height(int keycode, void *a)
{
	t_cylinder	*o;

	o = a;
	if (keycode == 107)
		o->h += 1;
	if (keycode == 44)
		o->h -= 1;
}

void	key_hook_object_controls_cylinder(int keycode, t_params *p)
{
	t_cylinder	*o;

	o = p->f->objs->obj;
	key_hook_cylinder_controls_nor(keycode, o);
	key_hook_cylinder_controls_pos(keycode, o);
	key_hook_cylinder_controls_dia(keycode, o);
	key_hook_cylinder_controls_height(keycode, o);
	objects_menu(p);
	o->nor = normalize(o->i_nor);
	o->p1 = multiply_xyz(o->nor, -0.5 * o->h);
	o->p1 = add_xyz(o->p1, o->pos);
	o->p2 = multiply_xyz(o->nor, 0.5 * o->h);
	o->p2 = add_xyz(o->p2, o->pos);
	o->sqt_radius = o->d * o->d * 0.25;
}
