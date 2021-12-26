/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoreira <fmoreira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 20:34:15 by fmoreira          #+#    #+#             */
/*   Updated: 2021/12/16 19:05:29 by fmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/fractol.h"

int	main(int argc, char **argv)
{
	t_data *f;

	if (argc != 2)
		printf("Error: ./fractol [fractal name] (main)");
	if (ft_strcmp(argv[1], "julia"))
		printf("Error: use [julia] (main)");
	f = init_data(argv[1]);
	f->img_ptr = init_img(f->mlx_ptr);
	printf("\nFaz Alguma Coisa Pelo Amor de Deus");
	if (!ft_strcmp(f->name, "julia"))
		mlx_hook(f->win_ptr, 6, 0, mouse_move, f);
	mlx_hook(f->win_ptr, 2, 0, key_press, f);
	mlx_hook(f->win_ptr, 4, 0, mouse_press, f);
	mlx_loop(f->mlx_ptr);
	return (0);
}
