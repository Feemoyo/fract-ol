/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoreira <fmoreira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 06:47:28 by fmoreira          #+#    #+#             */
/*   Updated: 2022/01/17 07:00:52 by fmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft.h"
# include "mlx.h"
# include <stdop.h>
# include <stdint.h>
# include <fcntl.h>
# include <math.h>
# include <X11/keysym.h
# include <X11/X.h>
# include <X11/Xlib.h>

# define WIDTH 800
# define HEIGHT 600

# define TRUE 1
# define FALSE 0

# define MAX_ITER 15

typedef int8_t t_bool;

typedef struct s_complex
{
	float	re;
	float	im;
}	t_complex;

typedef struct s_fractal
{
	float	max_re;
	float	max_im;
	float	min_re;
	float	min_im;
	int		max_iter;
	t_complex	param;
	t_bool	render;
	t_bool	display_ui;
	void	*image;
	void	(*draw_ft)(struct s_fractal, int *, int *);
	int		(*color_ft)(int, int);
}	t_fractal;

typedef struct s_display
{
	void	*mlx_ptr;
	void	*win_ptr;
}	t_display;

typedef struct s_image
{
	t_display	*display;
	t_fractal	fractal;
	void	*image_ptr;
	char	*addr;
	int		bpp;
	int		size_line;
	int		endian;
}	t_image;

typedef struct s_circle
{
	int	x_c;
	int	y_c;
	double	r;
	int	color;
	t_bool	border_only;
}	t_circle;

typedef struct s_rectangle
{
	int	x;
	int	y;
	int	width;
	int	height;
	int	color;
	t_bool	border_only;
}	t_rectangle;


