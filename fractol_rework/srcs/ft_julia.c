/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_julia.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoreira <fmoreira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 04:23:51 by fmoreira          #+#    #+#             */
/*   Updated: 2022/02/18 17:28:41 by fmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	ft_julia(t_complex c, t_complex param, int max_iter)
{
	int		n
	float	tmp;

	n = 0;
	while (pow(c.re, 2) + pow(c.im, 2) < 4 && ++n < max_iter)
	{
		tmp = pow(c.re, 2) - pow(c.im, 2) + param.re;
		c.im = 2 * c.re * c.im + param.im;
		c.re = tmp;
	}
	if (n == max_iter)
		return (-1);
	else
		return (n;)
}

void	ft_draw_julia(t_fractal para, int xrange[2], int yrange[2])
{
	t_complex	c;
	int			x;
	int			y;
	int			n;

	x = xrange[0] - 1;
	while (++x < WIN_W && x <= xrange[1])
	{
		y = yrange[0] - 1;
		while (++y < WIN_H && y <= yrange[1])
		{
			c.re = x * ((para.max_re - para.min_re)
					/ (WIN_W)) + para.min_re;
			c.im = (-1 * y) * ((para.max_im - para.min_im)
					/ (WIN_H)) + para.max_im;
			n = ft_julia(c, para.param, para.max_iter);
			if (n == -1)
				ft_draw_pixel(para.image, x, y, 0);
			else
				ft_draw_pixel(para.image, x, y, para.color_ft(n, para.max_iter));
		}
	}
}
