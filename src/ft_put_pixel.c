/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_pixel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbredykh <dbredykh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 16:41:55 by dbredykh          #+#    #+#             */
/*   Updated: 2023/08/18 13:37:24 by dbredykh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	get_rgba(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

void	ft_put_pixel(t_fractal *f)
{
	t_color	col_struct;
	int		color;

	if (f->i >= f->max_iter)
		mlx_put_pixel(f->g_img, f->x, f->y, 0x000000FF);
	else
	{
		col_struct = get_color_struct(f);
		color = get_rgba(col_struct.rgba.r,
				col_struct.rgba.g,
				col_struct.rgba.b, col_struct.rgba.a);
		mlx_put_pixel(f->g_img, f->x, f->y, color);
	}
}
