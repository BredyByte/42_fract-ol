/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fn_fract_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbredykh <dbredykh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 20:51:00 by dbredykh          #+#    #+#             */
/*   Updated: 2023/08/20 18:26:28 by dbredykh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_palette	*ft_get_palettes(void)
{
	static t_palette	array[3];

	array[0]
		= (t_palette){5, 0, {0x0D1C33, 0x17373C, 0x2B6832, 0x4F9300, 0xA1D700}};
	array[1]
		= (t_palette){5, 0, {0x610B4B, 0x01A9DB, 0xF4FA58, 0xFE642E, 0xB40404}};
	array[2]
		= (t_palette){5, 0, {0x000000, 0x311B92, 0x512DA8, 0x6A1B9A, 0x4A148C}};
	return (array);
}

int	ft_palletelen(t_fractal	*f)
{
	int	i;

	i = 0;
	while (f->palettes[i].count)
		i++;
	return (i);
}

void	terminate(t_fractal *f)
{
	mlx_delete_image(f->mlx, f->g_img);
	mlx_terminate(f->mlx);
	free(f);
}

char	*ft_take_name(int f_type)
{
	if (f_type == 1)
		return ("Mandelbrot");
	else if (f_type == 2)
		return ("Julia");
	else if (f_type == 2)
		return ("Burning ship");
	else
		return ("Fractol");
}
