/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fn_loop_hook.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbredykh <dbredykh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 14:42:13 by dbredykh          #+#    #+#             */
/*   Updated: 2023/08/18 13:01:57 by dbredykh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	move(int key, t_fractal	*f)
{
	double	h;
	double	w;

	w = (f->limx * 2.0) * f->zoom;
	h = (f->limy * 2.0) * f->zoom;
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

void	my_scrollhook(double xdelta, double ydelta, void *param)
{
	t_fractal	*f;
	int32_t		mouse_x;
	int32_t		mouse_y;
	double		movex;
	double		movey;

	f = (t_fractal *)param;
	(void)xdelta;
	mlx_get_mouse_pos(f->mlx, &mouse_x, &mouse_y);
	mouse_x -= 350;
	if (mouse_x < 0 || mouse_x >= SIZE || mouse_y < 0 || mouse_y >= SIZE)
		return ;
	movex = (mouse_x - SIZE / 2.0) * f->zoom / SIZE;
	movey = (mouse_y - SIZE / 2.0) * f->zoom / SIZE;
	if (ydelta > 0)
		f->zoom *= 1.1;
	else if (ydelta < 0)
		f->zoom /= 1.1;
	f->k += movex - (mouse_x - SIZE / 2.0) * f->zoom / SIZE;
	f->h += movey - (mouse_y - SIZE / 2.0) * f->zoom / SIZE;
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
	mlx_scroll_hook(f->mlx, &my_scrollhook, f);
	mlx_key_hook(f->mlx, &ft_key_hook, f);
	ft_draw_fract(f);
}
