/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mandelbrot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoreira <fmoreira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 14:46:10 by fmoreira          #+#    #+#             */
/*   Updated: 2022/02/02 11:08:17 by fmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fracol.h"

t_complex	ft_init_complex(double re, double im)
{
	t_complex complex;

	complex.re = re;
	complex.im = im;
	return (complex)
}
/*
t_complex	max;
	t_complex	min;
	t_complex	factor;
	t_complex	c;
	t_complex	z;
	float		x;
	float		y;
	int			i; */

void ft_mandelbrot(t_data *data)
{
	t_complex	z;
	int			inte;
	/* Complex Plane				*/
	min = ft_init_complex(-2.0, -2.0);
	max.re = 2,0;
	max.im = min.im + (max.re - min.re) * HEIGHT / WIDTH;

	/* Relationship between compelx numbers and pixels*/
	factor.re = (max.re - min.re) / (WIDTH - 1);
	factor.im = (max.im - min.im) / (HEIGHT - 1);

	y = 0;
	while (y < W_HEIGHT)
	{
		c.im = max.im - y * factor.im;
		x = 0;
		while (x < W_WIDTH)
		{
			c.re = min.re + x * factor.re;
			z = init_complex(c.re, c.im);
			z.modulo = pow(z.re, 2.0) + pow(z.im, 2.0);
			i = 0;
			while (z.modulo <= 4 && i < MAX_ITER)
				{
					z = init_complex(
							pow(z.re, 2.0) - pow(z.im, 2.0) + c.re,
							2.0 * z.re * z.im + c.im);
						z.modulo = pow(z.re, 2.0) + pow(z.im, 2.0);
					i++;
				}
			// pixel 
			x++;
		}
		y++;
	}
}
