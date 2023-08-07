/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fn_help_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbredykh <dbredykh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 14:44:05 by dbredykh          #+#    #+#             */
/*   Updated: 2023/08/06 15:55:24 by dbredykh         ###   ########.fr       */
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
		return (frac_index);
	else
		return (0);
}
