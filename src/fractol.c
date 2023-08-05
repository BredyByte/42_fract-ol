/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbredykh <dbredykh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 13:35:04 by dbredykh          #+#    #+#             */
/*   Updated: 2023/08/05 20:39:26 by dbredykh         ###   ########.fr       */
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

void	ft_test(mlx_key_data_t keydata, void *param)
{
	if (keydata.key == MLX_KEY_ESCAPE)
		mlx_close_window(param);
}

int	ft_init(void)
{
	mlx_t		*mlx;
	mlx_image_t	*g_img;

	mlx = mlx_init(SIZE, SIZE, "Fractol", false);
	g_img = mlx_new_image(mlx, 750, 750);
	if (!mlx)
		return (EXIT_FAILURE);
	memset(g_img->pixels, 255, g_img->width * g_img->height * sizeof(int));
	mlx_image_to_window(mlx, g_img, 0, 0);
	mlx_key_hook(mlx, &ft_test, mlx);
	mlx_loop(mlx);
	mlx_delete_image(mlx, g_img);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}

int	main(int argv, char **argc)
{
	if (!ft_checker(argv, argc[1]))
		ft_helper();
	else
		return (ft_init());
	return (0);
}
