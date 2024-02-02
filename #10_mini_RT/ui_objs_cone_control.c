/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_objs_cone_control.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ateow <ateow@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 18:53:46 by ateow             #+#    #+#             */
/*   Updated: 2024/01/21 19:46:44 by ateow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	key_hook_cone_controls_pos(int keycode, void *a)
{
	t_cone	*o;

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

void	key_hook_cone_controls_nor(int keycode, void *a)
{
	t_cone	*o;

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

void	key_hook_cone_controls_dia(int keycode, void *a)
{
	t_cone	*o;

	o = a;
	if (keycode == 106)
		o->d += 1;
	if (keycode == 109)
		o->d -= 1;
}

void	key_hook_cone_controls_height(int keycode, void *a)
{
	t_cone	*o;

	o = a;
	if (keycode == 107)
		o->h += 1;
	if (keycode == 44)
		o->h -= 1;
}

void	key_hook_object_controls_cone(int keycode, t_params *p)
{
	t_cone	*co;

	co = p->f->objs->obj;
	key_hook_cone_controls_nor(keycode, co);
	key_hook_cone_controls_pos(keycode, co);
	key_hook_cone_controls_dia(keycode, co);
	key_hook_cone_controls_height(keycode, co);
	objects_menu(p);
	co->nor = normalize(co->i_nor);
	co->rad_top = 0;
	co->rad_btt = co->d / 2.0;
	co->pt_top = multiply_xyz(co->nor, co->h);
	co->pt_top = add_xyz(co->pt_top, co->pos);
	co->pt_btt = multiply_xyz(co->nor, -co->h);
	co->pt_btt = add_xyz(co->pt_btt, co->pos);
	co->half_angle = atan((co->d / 2.0) / co->h);
	co->cos2 = cos(atan((co->d / 2.0) / co->h));
	co->cos2 *= co->cos2;
}
