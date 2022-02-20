/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_colouring_02.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoreira <fmoreira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 07:54:04 by fmoreira          #+#    #+#             */
/*   Updated: 2022/02/18 15:02:18 by fmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	ft_color_grayscale(int n, int max_iter)
{
	int	x;

	x = -255 * ((float)n / (float)max_iter) + 255;
	return (x *0x010000 + x * 0x000100 + x);
}

int	ft_color_multi(int n, int max_iter)
{
	int	r;
	int	g;
	int	b;
	float	x;

	r = 0;
	g = 0;
	b = 0;
	x = (float)n / (float)max_iter;
	if (x >= 0 && x <= 0.5)
	{
		r = -510 * x - 255;
		g = 510 * x;
	}
	else if (x > 0.5)
	{
		g = -510 * x + 510;
		b = 510 * x - 255;
	}
	return (r * 0x010000 + g * 0x000100 + b);
}
