/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fn_calc_fractals.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbredykh <dbredykh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 15:55:57 by dbredykh          #+#    #+#             */
/*   Updated: 2023/08/07 20:12:17 by dbredykh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	rgb(int r, int g, int b)
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
	i = h * 6;
	f = h * 6 - i;
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

void	put_pixel(t_fractal *f)
{
/* 	int	r, g, b; */

	if (f->i == f->max_iter)
		mlx_put_pixel(f->g_img, f->x, f->y, 0x000000FF);
	else
	{
		/* hsv_to_rgb((f->i % 256) / 255.0 * 360, 100, (f->i < f->max_iter) * 100, &r, &g, &b); */
		mlx_put_pixel(f->g_img, f->x, f->y, 0xFF0000FF);
	}
}

void	iterate_mandelbrot(t_fractal *f)
{
	f->c_re = (f->x - SIZE / 2.0) * f->zoom / SIZE + f->k;
	f->c_im = (f->y - SIZE / 2.0) * f->zoom / SIZE + f->h;
	f->re = 0;
	f->im = 0;
	f->i = 0;
	while (f->i < f->max_iter && (f->re * f->re + f->im * f->im) <= 4.0)
	{
		f->temp = f->re * f->re - f->im * f->im + f->c_re;
		f->im = 2 * f->re * f->im + f->c_im;
		f->re = f->temp;
		f->i++;
	}
}

void	ft_calc_mandelbrot(t_fractal *f)
{
	while (f->x < SIZE)
	{
		f->y = 0;
		while (f->y < SIZE)
		{
			iterate_mandelbrot(f);
			put_pixel(f);
			f->y++;
		}
		f->x++;
	}
}

void	ft_calc_julia(t_fractal *f)
{
	mlx_set_window_title(f->mlx, "Julia");
	mlx_put_pixel(f->g_img, 0, 0, 0x00FF00FF);
}

void	ft_calc_ship(t_fractal *f)
{
	mlx_set_window_title(f->mlx, "Burningship");
	mlx_put_pixel(f->g_img, 0, 0, 0x0000FFFF);
}
