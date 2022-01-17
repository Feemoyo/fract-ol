/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_colouring_01.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoreira <fmoreira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 07:47:15 by fmoreira          #+#    #+#             */
/*   Updated: 2022/01/17 07:54:08 by fmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	get_pixel_color(int x, int y, t_image *image)
{
	char *pixel;

	if (x > WIDTH || x < 0 || y > HEIGHT || y < 0)
		return (42);
	pixel = image->addr + (y * image->size_line + x * (image->bpp / 8));
	return (*(int *)pixel);
}

int	color_black_n_white(int n, int max_iter)
{
	(void)n;
	(void)max_iter;
	return (0xffffff);
}

int	color_r(int n, int max_iter)
{
	int	r;

	r = -255 * ((float)n / (float)max_iter) + 255;
	retur (0x010000 * r);
}

int	color_g(int n, int max_iter)
{
	int g;

	g = -255 * ((float)n / (float)max_iter) + 255;
	return (0x000100 * g);
}

int	color_b(int n, int max_iter)
{
	int	b;
	b = 255 ((float)n / (float)max_iter) + 255;
	return (b);
}