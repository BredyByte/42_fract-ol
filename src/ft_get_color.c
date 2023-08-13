/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbredykh <dbredykh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 15:13:55 by dbredykh          #+#    #+#             */
/*   Updated: 2023/08/13 21:03:30 by dbredykh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	ft_lerpi(int first, int second, double p)
{
	if (first == second)
		return (first);
	return ((int)((double)first + (second - first) * p));
}

static t_color	clerp(t_color c1, t_color c2, double p)
{
	t_color	c;

	if (c1.value == c2.value)
		return (c1);
	c.rgba.r = (char)ft_lerpi((int)c1.rgba.r, (int)c2.rgba.r, p);
	c.rgba.g = (char)ft_lerpi((int)c1.rgba.g, (int)c2.rgba.g, p);
	c.rgba.b = (char)ft_lerpi((int)c1.rgba.b, (int)c2.rgba.b, p);
	c.rgba.a = (char)0xFF;
	return (c);
}

static t_color	linear_color(double i, int max, t_palette *p)
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

static t_color	smooth_color(t_fractal *f)
{
	double	i;
	double	zn;
	double	nu;

	zn = log(f->re * f->re + f->im * f->im) / 2.0f;
	nu = log(zn / log(2)) / log(2);
	i = f->i + 1 - nu;
	if (i < 0)
		i = 0;
	return (linear_color(i, f->max_iter, f->palette));
}
t_color get_color_struct(t_fractal *f)
{
    if (f->smooth)
        return smooth_color(f);
    return linear_color((double)f->i, f->max_iter, f->palette);
}

