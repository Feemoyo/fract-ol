/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoreira <fmoreira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 07:18:03 by fmoreira          #+#    #+#             */
/*   Updated: 2022/02/18 17:44:44 by fmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	ft_init_events(t_display *display, t_image *image)
{
	mlx_loop_hook(display->mlx_ptr, &ft_loop_handler, image);
	mlx_hook(display->win_ptr, DestroyNotify, StructureNotifyMask,
			&ft_red_cross_handler, image);
	mlx_hook(display->win_ptr, KeyPress, KeyPressMask, &ft_keys_handler, image);
	mlx_hook(display->win_ptr, ButtonPress, ButtonPressMask,
			&ft_button_handler, image);
	//mlx_hook(display->win_ptr, MotionNotify, PointerMotionMask,
	//		&ft_pointer_handler, image);
}

static t_fractal	ft_init_fractal(t_image *image, t_fractal fractal)
{
	fractal.max_re = 2.0;
	fractal.min_re = -2.0;
	fractal.max_im = 2.0;
	fractal.min_im = -2.0;
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

	fractal = ft_check_args(argc, argv);
	display = ft_init_display(argv[1]);
	image = ft_init_image(display);
	fractal = ft_init_fractal(image, fractal);
	ft_init_events(display, image);
	mlx_loop(display->mlx_ptr);
	ft_free_n_destroy(image, display);
	ft_putstr_fd("Bye Bye...\nThanks :D\n", 1);
	return (0);
}
