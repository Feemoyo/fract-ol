/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoreira <fmoreira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 07:18:03 by fmoreira          #+#    #+#             */
/*   Updated: 2022/01/17 07:31:54 by fmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	init_events(t_display *display, t_image *image)
{
	mlx_loop_hook(display->mlx_ptr, &loop_handler, image);
	mlx_hook(display->win_ptr, DestroyNotify, StructNotifyMask,
			&red_across_handler, image);
	mlx_hook(display->win_ptr, KeyPress, KeyPressMask, &keys_handler, image);
	mlx_hook(display->win_ptr, ButtonPress, ButtonPressMask,
			&button_handler, image);
	mlx_hook(display->win_ptr, MotionNotify, PointerMotionMask
			&pointer_handler, image);
}

static t_fractal	init_fractal(t_image *image, t_fractal fractal)
{
	fractal.max_re = 2;
	fractal.min_re = -2;
	fractal.max_im = 2;
	fractal.min_re = -2;
	fractal.max_iter = MAX_ITER;
	fractal.render = TRUE;
	fractal.display_ui = FALSE;
	fractal.image = image;
	image->fractal = fractal;
	return (fractal);
}

int	main(int argc, char **argv)
{
	t_display	*display;
	t_image		*image;
	t_fractal	fractal;

	fractal = check_args(argc, argv);
	display = init_display(argv[1]);
	image = init_image(display);
	fractal = init_fractal(image, fractal);
	init_events(display, image);
	mlx_loop(display->mlx_ptr);
	free_n_destroy(image, display);
	ft_putstr_fd("Bye Bye...\nThanks :D\n");
	return (0);
}
