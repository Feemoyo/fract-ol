/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mandelbrot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoreira <fmoreira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 04:42:26 by fmoreira          #+#    #+#             */
/*   Updated: 2022/02/18 17:29:32 by fmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static int	ft_mandelbrot(t_complex c, int max_iter)
{
	int			n;
	float		tmp;
	t_complex	z;

	n = 0;
	z.re = 0;
	z.im = 0;
	while (pow(z.re, 2) + pow(z.im, 2) < 4 && ++n < max_iter)
	{
		tmp = pow(z.re, 2) - pow(z.im, 2) + c.re;
		z.im = 2 * z.re * z.im + c.im;
		z.re = tmp;
	}
	if (n == max_iter)
		return (-1);
	else
		return (n);
}

void	ft_draw_mandelbrot(t_fractal para, int xrange[2], int yrange[2])
{
	t_complex	c;
	int			x;
	int			y;
	int			n;

	x = xrange[0] - 1;
	while (++x < WIDTH && x <= xrange[1])
	{
		y = yrange[0] - 1;
		while (++y < HEIGHT && y <= yrange[1])
		{
			c.re = x * ((para.max_re - para.min_re)
					/ (WIDTH)) + para.min_re;
			c.im = (-1 * y) * ((para.max_im - para.min_im)
					/ (HEIGHT)) + para.max_im;
			n = ft_mandelbrot(c, para.max_iter);
			if (n == -1)
				ft_draw_pixel(para.image, x, y, 0);
			else
				ft_draw_pixel(para.image, x, y,
					para.color_ft(n, para.max_iter));
		}
	}
}
