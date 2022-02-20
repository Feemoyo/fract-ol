/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_events_02.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoreira <fmoreira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 13:10:31 by fmoreira          #+#    #+#             */
/*   Updated: 2022/02/18 16:01:17 by fmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	ft_red_cross_handler(t_image *image)
{
	ft_free_n_destroy(image, image->display);
	ft_putstr_fd("Bye...\n", 1);
	exit(EXIT_SUCCESS);
	return (0);
}
