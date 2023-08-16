/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fn_loop_hook.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbredykh <dbredykh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 14:42:13 by dbredykh          #+#    #+#             */
/*   Updated: 2023/08/16 15:20:09 by dbredykh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	move(int key, t_fractal	*f)
{
	double	h;
	double	w;

	w = (f->limx * 2) * f->zoom;
	h = (f->limy * 2) * f->zoom;
	if (key == MLX_KEY_LEFT)
		f->k += w * 0.02;
	if (key == MLX_KEY_RIGHT)
		f->k -= w * 0.02;
	if (key == MLX_KEY_UP)
		f->h -= h * 0.02;
	if (key == MLX_KEY_DOWN)
		f->h += h * 0.02;
}

void	ft_key_hook(mlx_key_data_t keydata, void *param)
{
	t_fractal	*f;

	f = param;
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_RELEASE)
		f->smooth = !f->smooth;
	if (keydata.key == MLX_KEY_C && keydata.action == MLX_RELEASE)
		f->palette = &f->palettes[f->palette_index++ % f->palette_len];
}


void	ft_loop_hook(void *param)
{
	t_fractal	*f;

	f = param;
	if (mlx_is_key_down(f->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(f->mlx);
	if (mlx_is_key_down(f->mlx, MLX_KEY_I))
		f->max_iter = (f->max_iter * 1.1) + 1;
	if (mlx_is_key_down(f->mlx, MLX_KEY_D))
		f->max_iter /= 1.1;
	if (mlx_is_key_down(f->mlx, MLX_KEY_Z))
		f->zoom *= 1.1;
	if (mlx_is_key_down(f->mlx, MLX_KEY_X))
		f->zoom /= 1.1;
	if (mlx_is_key_down(f->mlx, MLX_KEY_DOWN))
		move(MLX_KEY_DOWN, f);
	if (mlx_is_key_down(f->mlx, MLX_KEY_UP))
		move(MLX_KEY_UP, f);
	if (mlx_is_key_down(f->mlx, MLX_KEY_RIGHT))
		move(MLX_KEY_RIGHT, f);
	if (mlx_is_key_down(f->mlx, MLX_KEY_LEFT))
		move(MLX_KEY_LEFT, f);
	mlx_key_hook(f->mlx, &ft_key_hook, f);
	ft_draw_fract(f);
}
