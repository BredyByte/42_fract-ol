/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fn_usage_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbredykh <dbredykh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 12:48:48 by dbredykh          #+#    #+#             */
/*   Updated: 2023/08/15 15:55:59 by dbredykh         ###   ########.fr       */
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
	exit(1);
}

int	ft_arg_checker(int num, const char *index)
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
	cont = 8;
	while (str && cont++)
	{
		mlx_put_string(f->mlx, str, 20, cont * 20);
		free(str);
		str = get_next_line(fd);
	}
	close (fd);
}
