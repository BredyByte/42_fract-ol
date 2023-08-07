#ifndef FRACTOL_H
# define FRACTOL_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <memory.h>
#include <math.h>
#include "../assets/MLX42/include/MLX42/MLX42.h"
#include "../assets/libft/include/libft.h"
#define SIZE 900

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
}	t_fractal;

char	*ft_read_all(int fd);
void	ft_hooks(mlx_key_data_t keydata, void *param);
void	ft_helper(void);
int		ft_checker(int num, const char *index);
void	ft_calc_mandelbrot(t_fractal *f);
void	ft_calc_julia(t_fractal *f);
void	ft_calc_ship(t_fractal *f);

# endif
