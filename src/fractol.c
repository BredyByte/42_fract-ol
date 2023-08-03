/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbredykh <dbredykh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 13:35:04 by dbredykh          #+#    #+#             */
/*   Updated: 2023/08/03 16:52:34 by dbredykh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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
}

int	ft_checker(int num, const char *index)
{
	int	frac_index;

	if (num != 2)
		return (0);
	frac_index = ft_atoi(index);
	if (frac_index >= 1 && frac_index <= 3)
		return (1);
	else
		return (0);
}

int	main(int argv, char **argc)
{
	if (!ft_checker(argv, argc[1]))
		ft_helper();
	else
		ft_putstr("Success!");
	return (0);
}
