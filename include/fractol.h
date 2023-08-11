/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbredykh <dbredykh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 10:59:52 by dbredykh          #+#    #+#             */
/*   Updated: 2023/08/11 20:42:19 by dbredykh         ###   ########.fr       */
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

typedef struct		s_complex
{
	double		r;
	double		i;
}					t_complex;

typedef struct		s_rgba
{
	uint8_t		b;
	uint8_t		g;
	uint8_t		r;
	uint8_t		a;
}					t_rgba;

typedef struct		s_pixel
{
	t_complex	c;
	long		i;
}					t_pixel;

typedef struct		s_palette
{
	uint8_t		count;
	int			cycle;
	int			colors[16];
}					t_palette;

typedef union		u_color
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
	int 		smooth;
	int			type;

}				t_fractal;

char			*ft_read_all(int fd);

void			ft_draw_fract(t_fractal *f);
void			ft_hooks(void *param);

// calc fract functions
void			ft_calc_mandelbrot(t_fractal *f);
void			ft_calc_julia(t_fractal *f);
void			ft_calc_ship(t_fractal *f);

// fn_draw.c
/* void	hsv_to_rgb(float h, float s, float v, int *r, int *g, int *b); */
/* int		get_rgb(int r, int g, int b); */
void	ft_put_pixel(t_fractal *f);

// fn_errors.c
void			ft_errors(int type, t_fractal *f);

// fn_utils.c
void			ft_fract_data_init(t_fractal *f, int f_type);
void			ft_terminate(t_fractal *f);
char			*ft_take_name(int f_type);
void			ft_helper(void);
int				ft_checker(int num, const char *index);

#endif
