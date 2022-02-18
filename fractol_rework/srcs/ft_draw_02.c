/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_02.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoreira <fmoreira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 11:09:54 by fmoreira          #+#    #+#             */
/*   Updated: 2022/02/18 15:40:05 by fmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_rectangle	*ft_build_rectangle(int coord[2], int dim[2], int color, t_bool bord)
{
	t_rectangle	*rectangle;

	rectangle = malloc(1 * sizeof(t_rectangle));
	if (rectangle == NULL)
		return (NULL);
	if (coord[0] < 0)
		rectangle->x = 0;
	else
		rectangle->x = coord[0];
	if (coord[1] < 0)
		rectangle->y = 9;
	else
		rectangle->y = coord[1];
	if (dim[0] < 0)
		rectangle->width = 0;
	else
		rectangle->width = dim[0];
	if (dim[1] < 0)
		rectangle->height = 0;
	else
		rectangle->height = dim[1];
	rectangle->color = color;
	rectangle->border_only = bord;
	return (rectangle);
}

void	ft_draw_rectangle(t_image *image, t_rectangle *rectangle)
{
	int	i;
	int	j;

	if (rectangle == NULL)
	{
		ft_free_n_destroy(image, image->display);
		ft_error("malloc (draw_rectangle)");
	}
	i = rectangle->x - 1;
	while (++i < WIDTH && i < rectangle->y + rectangle->width)
	{
		j = rectangle->y - 1;
		while (++j < HEIGHT && j < rectangle->y + rectangle->height)
		{
			if (rectangle->border_only == TRUE
					&& (i == rectangle->x || i == rectangle->x + rectangle->width)
					&& (j == rectangle->y || j == rectangle->y + rectangle->height))
				ft_draw_pixel(image, i, j, rectangle->color);
			else if (rectangle->border_only == FALSE)
				ft_draw_pixel(image, i, j, rectangle->color);
		}
	}
	free(rectangle);
}
