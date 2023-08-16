/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fn_calc_fract.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbredykh <dbredykh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 15:55:57 by dbredykh          #+#    #+#             */
/*   Updated: 2023/08/16 16:12:10 by dbredykh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_calc_mandelbrot(t_fractal *f)
{
	float	temp;

	f->c_re = (f->x - SIZE / 2.0) * f->zoom / SIZE + f->k;
	f->c_im = (f->y - SIZE / 2.0) * f->zoom / SIZE + f->h;
	f->z_re = 0;
	f->z_im = 0;
	f->i = 0;
	while (f->z_re * f->z_re + f->z_im * f->z_im < (1 << 8)
		&& f->i < f->max_iter)
	{
		temp = f->z_re * f->z_re - f->z_im * f->z_im + f->c_re;
		f->z_im = f->z_re * f->z_im * 2 + f->c_im;
		if (f->z_re == temp && f->i == f->z_im)
		{
			f->i = f->max_iter;
			break ;
		}
		f->z_re = temp;
		f->i++;
	}
	ft_put_pixel(f);
}

void	ft_calc_julia(t_fractal *f)
{
	float	temp;

	f->z_re = (f->x - SIZE / 2.0) * f->zoom / SIZE + f->k;
	f->z_im = (f->y - SIZE / 2.0) * f->zoom / SIZE + f->h;
	f->i = 0;
	while (f->z_re * f->z_re + f->z_im * f->z_im < (1 << 8)
		&& f->i < f->max_iter)
	{
		temp = f->z_re * f->z_re - f->z_im * f->z_im + f->c_re;
		f->z_im = 2.0 * f->z_re * f->z_im + f->c_im;
		if (f->z_re == temp && f->z_im == f->z_im)
		{
			f->i = f->max_iter;
			break ;
		}
		f->z_re = temp;
		f->i++;
	}
	ft_put_pixel(f);
}

void	ft_calc_ship(t_fractal *f)
{
	float	temp;

	f->c_re = (f->x - SIZE / 2.0) * f->zoom / SIZE + f->k;
	f->c_im = (f->y - SIZE / 2.0) * f->zoom / SIZE + f->h;
	f->z_re = 0;
	f->z_im = 0;
	f->i = 0;
	while (f->z_re * f->z_re + f->z_im * f->z_im < (1 << 8)
		&& f->i < f->max_iter)
	{
		f->z_re = fabs(f->z_re);
		f->z_im = fabs(f->z_im);
		temp = f->z_re * f->z_re - f->z_im * f->z_im + f->c_re;
		f->z_im = 2.0 * f->z_re * f->z_im + f->c_im;
		if (f->z_re == temp && f->z_im == f->z_im)
		{
			f->i = f->max_iter;
			break ;
		}
		f->z_re = temp;
		f->i++;
	}
	ft_put_pixel(f);
}
