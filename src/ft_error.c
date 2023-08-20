/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbredykh <dbredykh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 10:57:48 by dbredykh          #+#    #+#             */
/*   Updated: 2023/08/20 18:53:43 by dbredykh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	mlx_err(t_fractal *f)
{
	free(f);
	exit (EXIT_FAILURE);
}

static void	fd_err(t_fractal *f)
{
	ft_putstr("Error: can't open file to open\n");
	mlx_err(f);
}

static void	img_err(t_fractal *f)
{
	mlx_terminate(f->mlx);
	mlx_err(f);
}

void	ft_error(int type, t_fractal *f)
{
	if (type == MLX_ERR)
		mlx_err(f);
	if (type == IMG_ERR)
		img_err(f);
	if (type == FD_ERR)
		fd_err(f);
}
