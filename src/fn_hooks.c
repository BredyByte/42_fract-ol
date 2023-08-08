/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fn_hooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbredykh <dbredykh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 14:42:13 by dbredykh          #+#    #+#             */
/*   Updated: 2023/08/08 13:22:38 by dbredykh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_rerender(t_fractal *f)
{
	mlx_delete_image(f->mlx, f->g_img);
	mlx_new_image(f->mlx, SIZE, SIZE);
	ft_draw_fractal(f);
	mlx_image_to_window(f->mlx, f->g_img, 0, 0);
}

void	ft_iter_increase(t_fractal *f)
{
	f->max_iter *= 1.1;
	ft_rerender(f);
	ft_printf("increased: %d\n", f->max_iter);
}

void	ft_iter_decrease(t_fractal *f)
{
	(void) f;

	puts("iter decreased");
}

void	ft_hooks(mlx_key_data_t keydata, void *param)
{
	t_fractal	*f;

	f = param;
	if (keydata.key == MLX_KEY_ESCAPE)
		mlx_close_window(f->mlx);
	if (keydata.key == MLX_KEY_I && keydata.action == MLX_PRESS && keydata.modifier == MLX_CONTROL)
		ft_iter_increase(f);
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS && keydata.modifier == MLX_CONTROL)
		ft_iter_decrease(f);
}
