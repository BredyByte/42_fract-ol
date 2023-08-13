/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fn_calc_fract.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbredykh <dbredykh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 15:55:57 by dbredykh          #+#    #+#             */
/*   Updated: 2023/08/13 20:32:04 by dbredykh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_calc_mandelbrot(t_fractal *f)
{
	f->c_re = (f->x - SIZE / 2.0) * f->zoom / SIZE + f->k;
	f->c_im = (f->y - SIZE / 2.0) * f->zoom / SIZE + f->h;
	f->re = 0;
	f->im = 0;
	f->i = 0;
	while (f->re * f->re + f->im * f->im < (1 << 8) && f->i < f->max_iter)
	{
		f->temp = f->re * f->re - f->im * f->im + f->c_re;
		f->im =	f->re * f->im * 2 + f->c_im;
		if (f->re == f->temp && f->i == f->im)
		{
			f->i = f->max_iter;
			break ;
		}
		f->re = f->temp;
		f->i++;
	}
	ft_put_pixel(f);
}

void	ft_calc_julia(t_fractal *f)
{
	mlx_put_pixel(f->g_img, 0, 0, 0x00FF00FF);
}

void	ft_calc_ship(t_fractal *f)
{
	mlx_put_pixel(f->g_img, 0, 0, 0x0000FFFF);
}
