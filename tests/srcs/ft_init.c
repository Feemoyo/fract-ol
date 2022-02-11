/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoreira <fmoreira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 11:04:05 by fmoreira          #+#    #+#             */
/*   Updated: 2022/02/03 09:55:05 by fmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_init(int argc, char **argv, t_data *data)
{
	if (!ft_strcmp(data->title, "mandelbrot"))
		data->fractal = 0; //# define MANDELBROT 0
	else if (!ft_strcmp(data->title, "julia"))
	{
		if (argc != 4)
		{
			ft_putstr_fd("!!! Julia low arguments !!!", 1);
			data->k = ft_init_complex(0.285, 0.01);
		}
		else
			data->k = ft_init_complex(ft_atof(argv[2]), ft_atof(argv[3]));
		data->fractal = 1; //# define JULIA 1
	}
	else
	{
		ft_putstr_fd("!!! Missing Arguments !!!", 1);
		ft_clear_memory(data);
	}
	ft_init_mlx(data);
	ft_set_defaults(data);
	ft_render(data);
}

t_complex	ft_init_complex(double re, double im)
{
	t_complex	complex;

	complex.re = re;
	complex.im = im;
	return (complex);
}

void	ft_init_mlx(t_data *data)
{
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
	{
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
	}
	ft_create_window(data);
	ft_create_image(data);
}

void	ft_init_pointers(t_data *data)
{
	data->mlx_ptr = NULL;
	data->win_ptr = NULL;
	//data->img.img_ptr = NULL; "mlx_ptr"
	//data->img.addr = NULL; "win_ptr"
	data->x = 0;
	data->y = 0;
}



