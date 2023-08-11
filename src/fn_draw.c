/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fn_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbredykh <dbredykh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 16:41:55 by dbredykh          #+#    #+#             */
/*   Updated: 2023/08/11 20:45:05 by dbredykh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_palette	*get_palettes(void)
{
	static t_palette	array[5];

	array[0] =
		(t_palette){5, 0, {0x7F1637, 0x047878, 0xFFB733, 0xF57336, 0xC22121}};
	array[1] =
		(t_palette){5, 0, {0x0D1C33, 0x17373C, 0x2B6832, 0x4F9300, 0xA1D700}};
	array[2] =
		(t_palette){5, 0, {0x002F2F, 0x046380, 0xEFECCA, 0xA7A37E, 0xE6E2AF}};
	array[3] =
		(t_palette){7, 10, {0xFF0000, 0xFFFF00, 0x00FF00, 0x00FFFF,
			0x0000FF, 0xFF00FF, 0xFF0000}};
	array[4] = (t_palette){0, 0, {0}};
	return (array);
}

int		ft_lerpi(int first, int second, double p)
{
	if (first == second)
		return (first);
	return ((int)((double)first + (second - first) * p));
}

t_color		clerp(t_color c1, t_color c2, double p)
{
	t_color c;

	if (c1.value == c2.value)
		return (c1);
	c.rgba.r = (char)ft_lerpi((int)c1.rgba.r, (int)c2.rgba.r, p);
	c.rgba.g = (char)ft_lerpi((int)c1.rgba.g, (int)c2.rgba.g, p);
	c.rgba.b = (char)ft_lerpi((int)c1.rgba.b, (int)c2.rgba.b, p);
	c.rgba.a = (char)0x00;
	return (c);
}

t_color		linear_color(double i, int max, t_palette *p)
{
	double		index;
	double		adjust;
	int			c;

	if (p->cycle)
		index = fmod(i, p->cycle - 1) / (p->cycle - 1);
	else
		index = i / max;
	c = p->count - 1;
	adjust = fmod(index, 1.0f / c) * c;
	return (clerp((t_color)(p->colors[(int)(index * c) + 1]),
		(t_color)(p->colors[(int)(index * c)]),
		(int)(adjust + 1) - adjust));
}

t_color	smooth_color(t_fractal *f)
{
	double i;
	double zn;
	double nu;

	zn = log(f->re * f->re + f->im * f->im) / 2.0f;
	nu = log(zn / log(2)) / log(2);
	i = f->i + 1 - nu;
	if (i < 0)
		i = 0;
	return (linear_color(f->i, f->max_iter, f->palette));
}

int			get_color(t_fractal *f)
{
	if (f->i >= f->max_iter)
		return (0x000000);
	if (f->smooth)
		return (smooth_color(f).value);
	return (linear_color((double)f->i, f->max_iter, f->palette).value);
}

void	ft_put_pixel(t_fractal *f)
{
	t_palette 	*palettes;
	int 	color;

	palettes = get_palettes();
	f->smooth = true; // Настройте это значение по своему усмотрению
	f->palette = &palettes[2]; // Вы можете выбрать другую палитру по вашему желанию

	color = get_color(f);

	mlx_put_pixel(f->g_img, f->x, f->y, color);
}
