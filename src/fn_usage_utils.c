/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fn_usage_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbredykh <dbredykh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 12:48:48 by dbredykh          #+#    #+#             */
/*   Updated: 2023/08/20 19:53:04 by dbredykh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_usage(t_fractal *f)
{
	int		fd;
	char	*res;

	fd = open("assets/to_read_files/usage.h", 0);
	if (fd < 0)
	{
		free(f);
		exit(EXIT_FAILURE);
	}
	res = ft_read_all(fd);
	ft_printf("%s\n", res);
	close(fd);
	free(f);
	free(res);
	exit(EXIT_FAILURE);
}

void	ft_indata_checke(int num, char **index, t_fractal *f)
{
	if (num == 2)
	{
		f->f_type = ft_atoi(index[1]);
		if (f->f_type == 1 || f->f_type == 2 || f->f_type == 3)
		{
			init(f);
			return ;
		}
	}
	else if (num == 4 && ft_atoi(index[1]) == 2)
	{
		f->f_type = 2;
		f->c_re = ft_atof(index[2]);
		f->c_im = ft_atof(index[3]);
		init(f);
		return ;
	}
	ft_usage(f);
}

void	ft_put_helper(t_fractal *f)
{
	char	*str;
	int		cont;
	int		fd;

	fd = open("assets/to_read_files/helper.h", 0);
	if (fd < 0)
		ft_error(FD_ERR, f);
	cont = 0;
	while (cont++ <= 12)
	{
		str = get_next_line(fd);
		free(str);
	}
	str = get_next_line(fd);
	cont = 1;
	while (str && cont++)
	{
		mlx_put_string(f->mlx, str, 20, cont * 20);
		free(str);
		str = get_next_line(fd);
	}
	close (fd);
}
