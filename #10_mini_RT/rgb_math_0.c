/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb_math_0.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cooi <cooi@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 10:34:18 by cooi              #+#    #+#             */
/*   Updated: 2024/01/14 11:49:00 by cooi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	lerp(int low, int high, float t)
{
	return (((1 - t) * low) + (t * high));
}

int	scale_rgb(int rgb, float x)
{
	int	r;
	int	g;
	int	b;

	r = get_r(rgb) * x;
	g = get_g(rgb) * x;
	b = get_b(rgb) * x;
	if (r > 255)
		r = 255;
	if (g > 255)
		g = 255;
	if (b > 255)
		b = 255;
	return (create_argb(255, r, g, b));
}

int	mul_rgb(int rgb, int rgb2)
{
	int	r;
	int	g;
	int	b;

	r = get_r(rgb) * get_r(rgb2) / 255;
	g = get_g(rgb) * get_g(rgb2) / 255;
	b = get_b(rgb) * get_b(rgb2) / 255;
	if (r > 255)
		r = 255;
	if (g > 255)
		g = 255;
	if (b > 255)
		b = 255;
	return (create_argb(255, r, g, b));
}

int	add_rgb(int rgb, int rgb2)
{
	int	r;
	int	g;
	int	b;

	r = get_r(rgb) + get_r(rgb2);
	g = get_g(rgb) + get_g(rgb2);
	b = get_b(rgb) + get_b(rgb2);
	if (r > 255)
		r = 255;
	if (g > 255)
		g = 255;
	if (b > 255)
		b = 255;
	return (create_argb(255, r, g, b));
}
