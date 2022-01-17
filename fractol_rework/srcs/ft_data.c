/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_data.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoreira <fmoreira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 08:18:07 by fmoreira          #+#    #+#             */
/*   Updated: 2022/01/17 08:45:34 by fmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_error(const char *ft_name)
{
	ft_putstr_fd("Error: ", 2);
	perror(ft_name);
	exit(EIXT_FAILURE);
}

void	free_n_destroy(t_image *image, t_display *display)
{
	if (image && image->image_ptr)
		mlx_destroy_image(image->display->mlx_ptr, image->image_ptr);
	if (image)
	{
		free(image);
		image = NULL;
	}
	if (display && display->win_ptr)
	{
		mlx_destroy_window(display->mlx_ptr, display->win_ptr);
		display->win_ptr = NULL;
	}
	if (display && display->mlx_ptr)
	{
		mlx_destroy_display(display->mlx_ptr);
		free(display->mlx_ptr);
		display->mlx_ptr = NULL;
	}
	if (display)
	{
		free(display);
		display = NULL;
	}
}

t_image	*init_image(t_display *display)
{
	t_image *image;

	image = malloc(sizeof(t_image));
	if (image == NULL)
	{
		free(display);
		ft_error("malloc (init_image)");
	}
	if (image == NULL || display == NULL)
	{
		free_n_destroy(image, display);
		ft_error("init_image (init_image)");
	}
	image->display = display;
	image->image_ptr = mlx_new_image(display->mlx_ptr, WIDTH, HEIGHT);
	image->addr = mlx_get_data_addr(image->image_ptr,
				&image->bpp, &image->size_line, &image->endian);
	if (image == NULL || image->image_ptr == NULL || image->addr == NULL)
	{
		free_n_destroy(image, display);
		ft_error("mlx_new_image (init_image)");
	}
	return (image);
}

t_display	*init_display(char *win_name)
{
	t_display	*display;

	display = malloc(sizeof(t_display));
	if (display == NULL)
		ft_error("malloc (init_display)");
	display->mlx_ptr = mlx_init();
	if (display->mlx_ptr == NULL)
	{
		free(display);
		ft_error("mlx_init (init_display)");
	}
	display->win_ptr = mlx_new_window(display->mlx_ptr,
				WIDTH, HEIGHT, win_name);
	if (display->win_ptr == NULL)
	{
		free_n_destroy(NULL, display);
		ft_error("mlx_new_window (init_display)")
	}
	return (display);
}
