/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fn_usage_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbredykh <dbredykh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 12:48:48 by dbredykh          #+#    #+#             */
/*   Updated: 2023/08/18 16:31:35 by dbredykh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_usage(void)
{
	int	fd;

	fd = open("assets/to_read_files/usage.h", 0);
	if (fd < 0)
		exit(EXIT_FAILURE);
	ft_printf("%s\n", ft_read_all(fd));
	close(fd);
	exit(EXIT_FAILURE);
}

void	ft_indata_checke(int num, const char **index, t_indata *int_data)
{
	if (num != 2)
	{
		if (int_data->f_type == 2)
		{
			int_data->f_type = ft_atoi(index[1]);
			int_data->j_c_im = ft_atof(index[2]);
			int_data->j_c_re = ft_atof(index[3]);
		}
		else
			ft_usage();
	}
	if (int_data->f_type >= 1 && int_data->f_type <= 3)
		init();
	else
		ft_usage();
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
