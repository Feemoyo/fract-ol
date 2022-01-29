/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_events_01.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoreira <fmoreira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 11:49:50 by fmoreira          #+#    #+#             */
/*   Updated: 2022/01/29 13:01:20 by fmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	loop_handler(t_image *image)
{
	int	xrange[2];
	int	yrange[2];

	xrange[0] = 0;
	xrange[1] = WIDTH;
	yrange[0] = 0;
	yrange[1] = HEIGHT;
	if (image->fractal.render == TRUE)
	{
		image->fractal.draw_ft(image->fractal, xrange, yrange);
		mlx_put_image_to_window(image->display->mlx_ptr,
				image->display->win_ptr, image->image_ptr, 0, 0);
		mlx_string_put(image->display->mlx_ptr, image->display->win_ptr,
				15, 20, 0xffffff, "H for help");
		image->fractal.display_ui == FALSE;
	}
	else if (image->fractal.display_ui == TRUE)
		draw_ui(image);
	return (0);
}

void	reset_ui(t_image *image)
{
	int	xrange[2];
	int	yrange[2];

	if	(image->fractol.display_ui == TRUE)
	{
		xrange[0] = WIDTH / 3 + 29;
		xrange[1] = WIDTH / 3 + 230;
		yrange[0] = HEIGHT / 3 + -1;
		yrange[1] = HEIGHT / 3 + 101;
		image->fractal.draw_ft(image->fractal, xrange, yrange);
		mlx_put_image_to_window(image->display->mlx_ptr,
				image->display->win_ptr, image->image_ptr, 0, 0);
		mlx_string_put(image->display->mlx_ptr, image->display->win_ptr,
				15, 20, 0x00ffffff, "H for help");
		image->fractal.display_ui = FALSE;
	}
	else
		image->fractal.display_ui = TRUE;
}

int	keys_handler(int key_sym, t_image *image)
{
	if (key_sym == XK_Escape)
		red_cross_handler(image);
	else if (key_sym == XK_r)
		reset(image);
	else if (key_sym == XK_h)
		reset_ui(image);
	else if (key_sym == XK_w)
		zoom_in(image);
	else if (key_sym == XK_q)
		zoom_out(image);
	else if (key_sym == XL_KP_add && image->fractal.max_iter < 100)
	{
		image->fractal.max_iter +=4;
		image->fractal.render = TRUE;
	}
	else if (key_sym == XK_KP_Subtract && image->fractal.max_iter >= 10)
	{
		image->fractal.max_iter -= 4;
		image->fractal.render = TRUE;
	}
	return (0);
}

int	pointer_handler(int x, int y, t_image *image)
{
	if (image->fractal.draw_ft == &draw_julia
			&& x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		image->fractal.param.re = xrange
				* ((image->fractal.max_re - image->fractal.min_re)
					/ (WIDTH)) + image->fractal.min_re;
		image->fractal.param.im = (-1 * y)
				* ((image->fractal.max_im - image->fractal.min_im)
					/ (HEIGHT)) + image->fractal.max_im;
		image->fractal.render = TRUE;
	}
	return (0);
}

int	button_handler(int button, int x, int y, t_image *image)
{
	(void)x;
	(void)y;
	if (button == 5)
		zoom_out(image);
	else if (button == 4)
		zoom_in(image);
	return (0);
}
