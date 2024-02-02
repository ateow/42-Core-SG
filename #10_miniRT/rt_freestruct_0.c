/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_freestruct_0.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cooi <cooi@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 14:17:30 by cooi              #+#    #+#             */
/*   Updated: 2024/01/14 15:15:51 by cooi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	free_lights(t_light *l)
{
	t_light	*tmp;

	while (l)
	{
		tmp = l;
		l = l->next;
		free (tmp);
	}
}

void	free_hittables(t_hittable *l)
{
	t_hittable	*tmp;

	while (l)
	{
		tmp = l;
		l = l->next;
		free (tmp->obj);
		free (tmp);
	}
}

void	free_rt(t_rt **f)
{
	if (f && *f)
	{
		free((*f)->a);
		free((*f)->c);
		free_lights((*f)->l);
		free_hittables((*f)->objs);
	}
	free (*f);
	*f = NULL;
}
