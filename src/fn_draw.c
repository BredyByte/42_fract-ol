/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fn_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbredykh <dbredykh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 16:41:55 by dbredykh          #+#    #+#             */
/*   Updated: 2023/08/11 18:54:48 by dbredykh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	get_rgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

void	hsv_to_rgb(float h, float s, float v, int *r, int *g, int *b)
{
	float f, p, q, t;
	int i;

	h /= 360.0;
	v *= 255.0;
	s /= 100.0;
	i = h * 4;
	f = h * 4 - i;
	p = v * (1 - s);
	q = v * (1 - f * s);
	t = v * (1 - (1 - f) * s);
	i = i % 6;
	if (i == 0)
		*r = v, *g = t, *b = p;
	else if (i == 1)
		*r = q, *g = v, *b = p;
	else if (i == 2)
		*r = p, *g = v, *b = t;
	else if (i == 3)
		*r = p, *g = q, *b = v;
	else if (i == 4)
		*r = t, *g = p, *b = v;
	else
		*r = v, *g = p, *b = q;
	*r = *r > 255 ? 255 : *r < 0 ? 0 : *r;
	*g = *g > 255 ? 255 : *g < 0 ? 0 : *g;
	*b = *b > 255 ? 255 : *b < 0 ? 0 : *b;
}

void	ft_put_pixel(t_fractal *f, int iteration)
{
	int r, g, b;
	double nu;

	if (iteration == f->max_iter)
		mlx_put_pixel(f->g_img, f->x, f->y, 0x000000FF);
	else
	{
		nu = iteration + 1 - log(log2(f->re * f->re + f->im * f->im));
		hsv_to_rgb((iteration % 256) / 255.0 * 360, 100, (iteration < f->max_iter) * 100, &r, &g, &b);
		mlx_put_pixel(f->g_img, f->x, f->y, get_rgb(r, g, b));
	}
}
