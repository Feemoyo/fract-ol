/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoreira <fmoreira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 21:11:11 by fmoreira          #+#    #+#             */
/*   Updated: 2021/12/10 23:05:14 by fmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	draw_julia(t_data *f)
{
	double swap;

	f->y = 0;
	while (f->y++ < HEIGHT)
	{
		f->x = 0;
		while (f->x++ < WIGHT)
		{
			f->i = 0;
			f->z_re = (f->x - WIGHT / 2) / (0.25 * WIGHT * f->zoom) + f->moveX;
			f->z_im = (f->x - HEIGHT / 2) / (0.25 * HEIGHT * f->zoom) + f->moveY;
			while (f->i++ < f->max_interation && (pow(f->z_re, 2.0) + pow(f->z_im, 2.0) <= 4))
			{
				swap = pow(f->z_re, 2.0) - pow(f->z_im, 2.0) + f->c_re;
				f->z_im = 2 * f->z_re * f->z_im + f->c_im;
				f->z_re = swap;
			}
			if (pow(f->z_re, 2.0) + pow(f->z_im, 2.0) > 4)
				color(f);
		}
	}
}

void	julia(t_data *f)
{
	mlx_clear_window(f->mlx_ptr, f->win_ptr);
	draw_julia(f);
	mlx_put_image_to_window(f->mlx_ptr, f->win_ptr, f->img_ptr->img, 0, 0);
}