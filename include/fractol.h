/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbredykh <dbredykh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 10:59:52 by dbredykh          #+#    #+#             */
/*   Updated: 2023/08/08 13:08:16 by dbredykh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../assets/MLX42/include/MLX42/MLX42.h"
# include "../assets/libft/include/libft.h"
# include <math.h>
# include <memory.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# define SIZE 1100

// error macros
# define MLX_ERR 1
# define IMG_ERR 2

typedef struct s_fractal
{
	mlx_t		*mlx;
	mlx_image_t	*g_img;
	float		k;
	float		h;
	float		re;
	float		im;
	float		temp;
	float		zoom;
	float		c_re;
	float		c_im;
	char		*addr;
	int			y;
	int			i;
	int			x;
	int			endian;
	int			max_iter;
	int			type;
}				t_fractal;

char			*ft_read_all(int fd);
void			ft_draw_fractal(t_fractal *f);
void			ft_hooks(mlx_key_data_t keydata, void *param);
void			ft_helper(void);
int				ft_checker(int num, const char *index);
void			ft_calc_mandelbrot(t_fractal *f);
void			ft_calc_julia(t_fractal *f);
void			ft_calc_ship(t_fractal *f);
void			ft_errors(int type, t_fractal *f);

#endif
