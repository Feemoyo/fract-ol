/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoreira <fmoreira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 06:47:28 by fmoreira          #+#    #+#             */
/*   Updated: 2022/02/18 17:50:10 by fmoreira         ###   ########.fr       */
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

//	ft_couloring_01.c
int	ft_get_pixel_color(int x, int y, t_image *image);
int	ft_color_bnw(int n, int max_iter);
int	ft_color_r(int n, int max_iter);
int	ft_color_g(int n, int max_iter);
int	ft_color_g(int n, int max_iter);
//	ft_couloring_02.c
int	ft_color_b(int n, int max_iter);
int	ft_color_grayscale(int n, int max_iter);
int	ft_color_multi(int n, int max_iter);
//	ft_data.c
void	ft_error(const char *ft_name);
void	ft_free_n_destroy(t_image *image, t_display *display);
t_image	*ft_init_image(t_display *display);
t_display	*ft_init_display(char *win_name);
//	ft_draw_01.c
void	ft_draw_pixel(t_image *image, int x, int y, int color);
int	ft_clear_window(t_image *image, int color);
void	ft_draw_ui(t_image *image);
t_circle	*ft_build_circle(int coord[2], double r, int, t_bool bord);
void	ft_draw_circle(t_image image, t_circle *circle);
//	ft_draw_02.c
t_rectangle	*ft_build_rectangle(int coord[2], int dim[2], int color, t_bool bord);
void	ft_draw_rectangle(t_image	*image, t_rectangle *rectangle);
//	ft_events_01.c
int	ft_loop_handler(t_image *image);
int	ft_keys_handler(int key_sym, t_image *image);
int	ft_pointer_handler(int x, int y, t_image *image);
int	ft_botton_handler(int button, int x, int y, t_image *image);
void	ft_reset_ui(t_image *image);
//	ft_events_02.c
int	ft_red_cross_handler(t_image *image);
//	ft_julia.c
static int	ft_julia(t_complex c, t_complex param, int max_iter);
void	ft_draw_julia(t_fractal para, int xrange[2], int yrange[2]);
//	ft_mandelbrot.c
static int	ft_mamdelbrot(t_complex c, int max_iter);
void	ft_draw_mandelbrot(t_fractal para, int xrange[2], int yrange[2]);
//	ft_parsing.c
static void	ft_usage(void);
void	*ft_fract_sets(char *set);
void	*ft_color_sets(char color);
t_fractal	ft_check_args(int argc, char **argv);
//	ft_utils.c
float	ft_complex_magnitude(t_complex z);
float	ft_atof(char *str);
t_bool	ft_c_in_charset(char c, char *charset);
t_bool	ft_is_charset(const char *str, char *charset);
int	ft_max(int a, int b);
//	ft_zoom.c
void	ft_zoom_in(t_image *img);
void	ft_zoom_out(t_image *img);
void	ft_reset(t_image *img)
