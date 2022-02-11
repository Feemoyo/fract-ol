/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoreira <fmoreira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 10:44:06 by fmoreira          #+#    #+#             */
/*   Updated: 2022/02/02 11:08:12 by fmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc < 2)
	{
		ft_putstr_fd("\n!!! Missing Arguments !!!\n");
		exit(1); //#define MLX_ERROR 1
	}
	else
	{
		data.title = (argv[1]);
		ft_init_pointers(&data);
		ft_init(argc, arvg, &data);
	}
}
