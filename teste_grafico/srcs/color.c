/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoreira <fmoreira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 02:08:38 by fmoreira          #+#    #+#             */
/*   Updated: 2021/12/10 23:06:50 by fmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	color(t_data *f)
{
	int		pixel;
	double	t;

	t = (double)f->i / f->max_interation;
	pixel = (f->y * f->img_ptr->size_l + 4 * f->x);
	f->color = f->color % 3;
	if (f->color == 0)
	{
		f->img_ptr->data[pixel + 0] = (int)(9 * (1 - t) * t * t * t * 255);
		f->img_ptr->data[pixel + 1] = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
		f->img_ptr->data[pixel + 2] = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
	}
	else if (f->color == 1)
	{
		f->img_ptr->data[pixel] = (int)(6 * (1 - t) * (1 - t) * (1 - t) * t * 255);
		f->img_ptr->data[pixel + 1] = (int)(9 * (1 - t) * t * t * t * 255);
	}
	else if (f->color == 2)
		f->img_ptr->data[pixel + 2] = (int)(10 * (1 - t) * t * t * t * 255);
}