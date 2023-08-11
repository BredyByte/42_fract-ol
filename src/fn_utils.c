/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fn_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbredykh <dbredykh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 16:00:14 by dbredykh          #+#    #+#             */
/*   Updated: 2023/08/11 20:46:05 by dbredykh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_fract_data_init(t_fractal *f, int f_type)
{
	f->max_iter = 60;
	f->type = f_type;
	f->k = -0.5;
	f->h = 0;
	f->zoom = 3.0;
}

void	ft_terminate(t_fractal *f)
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

void	ft_helper(void)
{
	int	fd;

	fd = open("assets/to_read_files/helper.h", 0);
	if (fd < 0)
	{
		ft_putstr("Error: can't open helper.h\n");
		exit(1);
	}
	ft_printf("%s\n", ft_read_all(fd));
	exit(1);
}

int	ft_checker(int num, const char *index)
{
	int	frac_index;

	if (num != 2)
		return (0);
	frac_index = ft_atoi(index);
	if (frac_index >= 1 && frac_index <= 3)
		return (frac_index);
	else
		return (0);
}
