/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbredykh <dbredykh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 13:35:04 by dbredykh          #+#    #+#             */
/*   Updated: 2023/08/13 18:18:19 by dbredykh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

#include "fractol.h"

void	ft_fract_typify(t_fractal *f)
{
	if (f->type == 1)
		ft_calc_mandelbrot(f);
	else if (f->type == 2)
		ft_calc_julia(f);
	else if (f->type == 3)
		ft_calc_ship(f);
}

void	ft_draw_fract(t_fractal *f)
{
	f->y = 0;
	while (f->y < SIZE)
	{
		f->x = 0;
		while (f->x < SIZE)
		{
			ft_fract_typify(f);
			f->x++;
		}
		f->y++;
	}
}

void	fract_init(int f_type)
{
	t_fractal	*f;

	f = malloc(sizeof(t_fractal));
	if (!f)
		exit (EXIT_FAILURE);
	ft_fract_data_init(f, f_type);
	f->mlx = mlx_init(SIZE, SIZE, ft_take_name(f_type), false);
	if (!f->mlx)
		ft_errors(MLX_ERR, f);
	f->g_img = mlx_new_image(f->mlx, SIZE, SIZE);
	if (!f->g_img)
		ft_errors(IMG_ERR, f);
	ft_draw_fract(f);
	mlx_image_to_window(f->mlx, f->g_img, 0, 0);
	mlx_loop_hook(f->mlx, &ft_loop_hook, f);
	mlx_loop(f->mlx);
}

int	main(int argv, char **argc)
{
	int			f_type;

	f_type = ft_arg_checker(argv, argc[1]);
	if (!f_type)
		ft_helper();
	else
		fract_init(f_type);
	return (0);
}
