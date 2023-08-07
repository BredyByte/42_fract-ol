/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbredykh <dbredykh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 13:35:04 by dbredykh          #+#    #+#             */
/*   Updated: 2023/08/07 20:05:53 by dbredykh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_fract_data_init(t_fractal *f, int f_type)
{
	f->max_iter = 100;
	f->x = 0;
	f->y = 0;
	f->type = f_type;
	f->k = 0;
	f->h = 0;
	f->zoom = 1.0;
}

void	ft_draw_fractal(t_fractal *f)
{
	if (f->type == 1)
	{
		mlx_set_window_title(f->mlx, "Mandelbrot");
		ft_calc_mandelbrot(f);
	}
	else if (f->type == 2)
	{
		mlx_set_window_title(f->mlx, "Julia");
		ft_calc_julia(f);
	}
	else if (f->type == 3)
	{
		mlx_set_window_title(f->mlx, "Burning ship");
		ft_calc_ship(f);
	}

}

int	main(int argv, char **argc)
{
	int			f_type;
	t_fractal	*f;

	f_type = ft_checker(argv, argc[1]);
	if (!f_type)
		ft_helper();
	f = malloc(sizeof(t_fractal));
	if (!f)
		exit (EXIT_FAILURE);
	ft_fract_data_init(f, f_type);
	f->mlx = mlx_init(SIZE, SIZE, "Fractol", false);
	if (!f->mlx)
	{
		free(f);
		exit (EXIT_FAILURE);
	}
	f->g_img = mlx_new_image(f->mlx, 750, 750);
	if (!f->g_img)
	{
		mlx_terminate(f->mlx);
		free(f);
		exit (EXIT_FAILURE);
	}
	ft_draw_fractal(f);
	mlx_image_to_window(f->mlx, f->g_img, 0, 0);
	mlx_key_hook(f->mlx, &ft_hooks, f->mlx);
	mlx_loop(f->mlx);
	mlx_delete_image(f->mlx, f->g_img);
	mlx_terminate(f->mlx);
	free(f);
	return (0);
}
