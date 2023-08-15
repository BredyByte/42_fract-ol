/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbredykh <dbredykh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 10:59:52 by dbredykh          #+#    #+#             */
/*   Updated: 2023/08/15 16:32:55 by dbredykh         ###   ########.fr       */
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
# define SIZE 750

// error macros
# define MLX_ERR 1
# define IMG_ERR 2
# define FD_ERR 3

typedef struct s_rgba
{
	uint8_t		b;
	uint8_t		g;
	uint8_t		r;
	uint8_t		a;
}	t_rgba;

typedef struct s_palette
{
	uint8_t		count;
	int			cycle;
	int			colors[16];
}	t_palette;

typedef union u_color
{
	int			value;
	t_rgba		rgba;
}					t_color;

typedef struct s_fractal
{
	mlx_t		*mlx;
	mlx_image_t	*g_img;
	float		k;
	float		h;
	float		re;
	float		im;
	float		temp;
	double		zoom;
	float		c_re;
	float		c_im;
	char		*addr;
	int			y;
	int			i;
	int			x;
	int			endian;
	int			max_iter;
	t_palette	*palette;
	t_palette	*palettes;
	int			palette_index;
	int			smooth;
	int			type;
	int			palette_len;
}				t_fractal;

char		*ft_read_all(int fd);

void		ft_draw_fract(t_fractal *f);
void		ft_loop_hook(void *param);

// calc fract functions
void		ft_calc_mandelbrot(t_fractal *f);
void		ft_calc_julia(t_fractal *f);
void		ft_calc_ship(t_fractal *f);

void		ft_put_pixel(t_fractal *f);
void		ft_error(int type, t_fractal *f);

// fn_utils.c
void		terminate(t_fractal *f);
char		*ft_take_name(int f_type);
void		ft_usage(void);
int			ft_arg_checker(int num, const char *index);
int			ft_palletelen(t_fractal	*f);

void		ft_put_helper(t_fractal *f);

// ft_get_color.c
t_color		get_color_struct(t_fractal *f);

// ft_get_palletes.c
t_palette	*ft_get_palettes(void);

#endif
