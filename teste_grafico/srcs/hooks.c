/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoreira <fmoreira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 02:54:44 by fmoreira          #+#    #+#             */
/*   Updated: 2021/12/10 22:20:42 by fmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		key_press(int keycode, t_data *f)
{
	ft_bzero(f->img_ptr->data, WIGHT * HEIGHT * f->img_ptr->bpp);
	if (keycode == 53)
		exit(0);
		else if (keycode == 126 || keycode == 13)
			f->moveY -= 0.1 / f_->zoom;
		else if (keycode == 125 || keycode == 1)
			f->moveY += 0.1 / f->zoom;
		else if (keycode == 124 || keycode == 2)
			f->moveX += 0.1 || f->zoom;
		else if (keycode == 123 || keycode == 0)
			f->moveX -= 0.1 / f->zoom;
		else if (keycode == 69 || keycode == 24)
			f->max_interation += 1;
		else if (keycode == 78 || keycode == 27)
			f->max_interation -= 1;
		else if (keycode == 8)
			f->color += 1;
		fractol(f);
		return(0);
}

int		mouse_press(int button, int x, int y, t_data *f)
{
	ft_bzero(f->img_ptr->data, WIGHT * HEIGHT * f->img_ptr->bpp);
	if (button == 4)
	{
		f->zoom *=1.25;
		f->moveY += (y - HEIGHT / 2) * 0.0015 / f->zoom;
		f->moveX += (x - WIGHT / 2) * 0.0015 / f->zoom;
	}
	else if (button == 5)
	{
		f->moveY += (y - HEIGHT / 2) * 0.0015 / f->zoom;
		f->moveX += (x - WIGHT / 2) * 0.0015 / f->zoom;
		f->zoom *= 0.8;
	}
	fractol(f);
	return (0);
}

int		mouse_move(int x. int y, t_data *f)
{
	ft_bzero(f->img_ptr->data, WIGHT * HEIGHT * f->img_ptr->bpp);
	f->c_im = (y - HEIGHT / 2) / (0.25 * HEIGHT * f->zoom) + f->moveY;
	f->c_re = (x - WIGHT / 2) / (0.25 * WIGHT * f->zoom) + f->moveX;
	julia(f);
	return (0);
}
