/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zoom.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoreira <fmoreira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 23:19:45 by fmoreira          #+#    #+#             */
/*   Updated: 2022/02/18 17:50:01 by fmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	ft_zoom_in(t_image *img)
{
	float	im_amp;
	float	re_amp;

	im_amp = img->fractal.max_im - img->fractal.min_im;
	re_amp = img->fractal.max_re - img->fractal.min_re;
	img->fractal.max_im -= 0.2 * im_amp;
	img->fractal.min_im += 0.2 * im_amp;
	img->fractal.max_re -= 0.2 * re_amp;
	img->fractal.min_re += 0.2 * re_amp;
	img->fractal.render = TRUE;
}

void	ft_zoom_out(t_image *img)
{
	float	im_amp;
	float	re_amp;

	im_amp = img->fractal.max_im - img->fractal.min_im;
	re_amp = img->fractal.max_re - img->fractal.min_re;
	img->fractal.max_im += 0.2 * im_amp;
	img->fractal.min_im -= 0.2 * im_amp;
	img->fractal.max_re += 0.2 * re_amp;
	img->fractal.min_re -= 0.2 * re_amp;
	img->fractal.render = TRUE;
}

void	ft_reset(t_image *img)
{
	img->fractal.max_re = 2.0;
	img->fractal.min_re = -2.0;
	img->fractal.max_im = 2.0;
	img->fractal.min_im = -2.0;
	img->fractal.render = TRUE;
}
