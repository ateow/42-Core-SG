/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_objs_sphere_control.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ateow <ateow@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 18:02:45 by ateow             #+#    #+#             */
/*   Updated: 2024/01/21 19:38:12 by ateow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	key_hook_sphere_controls_dia(int keycode, void *a)
{
	t_sphere	*o;

	o = a;
	if (keycode == 106)
		o->d += 1;
	if (keycode == 109)
		o->d -= 1;
}

void	key_hook_sphere_controls_pos(int keycode, void *a)
{
	t_sphere	*o;

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

void	key_hook_object_controls_sphere(int keycode, t_params *p)
{
	t_sphere	*o;

	o = p->f->objs->obj;
	key_hook_sphere_controls_pos(keycode, o);
	key_hook_sphere_controls_dia(keycode, o);
	objects_menu(p);
}
