/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_objs_plane_control.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ateow <ateow@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 18:07:28 by ateow             #+#    #+#             */
/*   Updated: 2024/01/21 19:46:55 by ateow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	key_hook_plane_controls_pos(int keycode, void *a)
{
	t_plane	*o;

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

void	key_hook_plane_controls_nor(int keycode, void *a)
{
	t_plane	*o;

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

void	key_hook_object_controls_plane(int keycode, t_params *p)
{
	t_plane	*o;

	o = p->f->objs->obj;
	key_hook_plane_controls_pos(keycode, o);
	key_hook_plane_controls_nor(keycode, o);
	objects_menu(p);
	o->nor = normalize(o->i_nor);
}