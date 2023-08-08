/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fn_errors_controller.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbredykh <dbredykh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 10:57:48 by dbredykh          #+#    #+#             */
/*   Updated: 2023/08/08 10:59:19 by dbredykh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	ft_mlx_err(t_fractal *f)
{
	free(f);
	exit (EXIT_FAILURE);
}

static void	ft_img_err(t_fractal *f)
{
	mlx_terminate(f->mlx);
	ft_mlx_err(f);
}

void	ft_errors(int type, t_fractal *f)
{
	if (type == MLX_ERR)
		ft_mlx_err(f);
	if (type == MLX_ERR)
		ft_img_err(f);
}
