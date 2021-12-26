/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoreira <fmoreira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 01:35:11 by fmoreira          #+#    #+#             */
/*   Updated: 2021/12/16 19:13:43 by fmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

t_img	*init_img(void *mlx)
{
	t_img *img;

	img = (t_img *)malloc(sizeof(t_img));
	if (img == NULL)
		printf("Error: malloc failed (init_img)");
	img->img = mlx_new_image(mlx, WIGHT, HEIGHT);
	if (img->img == NULL)
		printf("Error: img failed (init_img)");
	img->data = mlx_get_data_addr(img->img, &(img->bpp), &(img->size_l), &(img->end));
	img->bpp /= 8;
	return (img);
}

t_data	*init_data(char *s)
{
	t_data *f;

	f = (t_data *)malloc(sizeof(t_data));
	if (f == NULL)
		printf("Error: malloc failed (init_data)");
	f->name = s;
	f->max_interation = 50;
	f->zoom = 1;
	f->moveX = 0;
	f->moveY = 0;
	f->color = 0;
	f->mlx_ptr = mlx_init();
	if (f->mlx_ptr == NULL)
		printf("Error: mlx failed (init data)");
	f->win_ptr = mlx_new_window(f->mlx_ptr, WIGHT, HEIGHT, f->name);
	if (f->win_ptr == NULL)
		printf("Error: win failed (init_data)"); //problem here
	return (f);
}