/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoreira <fmoreira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 05:11:21 by fmoreira          #+#    #+#             */
/*   Updated: 2022/02/18 17:47:39 by fmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	ft_usage(void)
{
	ft_putstr_fd("\nUsage: ./fractol <name of fractal set> <color mode>\n", 1);
	ft_putstr_fd("\n[(optional) real part of Julia's parameter]\n", 1);
	ft_putstr_fd("\n[(optional) imaginary part of Julia's parameter]\n", 1);
	ft_putstr_fd("List of sets:\n - Mandelbrot\n - Jullia\n\n", 1);
	ft_putstr_fd("List of color:\n - BnW or Grayscale: W/S\n - Red, Green ", 1);
	ft_putstr_fd("or Blue: R/G/B\n - Spectrum: P\n\n", 1);
	ft_putstr_fd("Real and imaginary parts shoulld be formated as floats.", 1);
	ft_putstr_fd(" If given, both real and imaginary part should be.", 1);
	ft_putstr_fd("Both should not be above +2.0 or -2.0", 1);
	ft_putstr_fd("\n\nExample:	./fractol Julia P 0.42 -0.42\n\n", 1);
	exit(42);
	}

	void	*ft_fract_sets(char *set, int argc)
	{
		if (!ft_strncmp(set, "Mandelbrot", ft_max(ft_strlen(set), 10)))
			return (&ft_draw_mandelbrot);
		else if (!ft_strncmp(set, "Julia", ft_max(ft_strlen(set), 5))
					&& argc == 5)
			return (&ft_draw_julia);
		else
		{
			ft_usage();
			return (NULL);
		}
	}

	void	*ft_color_sets(char color)
	{
		if (color == 'W' || color == 'w')
			return (&ft_color_bnw);
		else if (color == 'S' || color == 's')
			return (&ft_color_grayscale);
		else if (color == 'R' || color == 'r')
			return (&ft_color_r);
		else if (color == 'G' || color == 'g')
			return (&ft_color_g);
		else if (color == 'B' || color == 'b')
			return (&ft_color_b);
		else if (color == 'P' || color == 'p')
			return (&ft_color_multi);
		else
		{
			ft_usage();
			return(NULL);
		}
	}

t_fractal	ft_check_args(int argc, char **argv)
{
	t_fractal	fract;
	
	if (argc > 5 || argc < 3 || argc == 4)
		ft_usage();
	fract.draw_ft = ft_fract_sets(argv[1], argc);
	if (ft_strlen(argv[2]) > 1)
		ft_usage();
	fract.color_ft = ft_color_sets(argv[2][0]);
	fract.param.re = 0.0;
	fract.param.im = 0.0;
	if (argc == 5)
	{
		fract.param.re = ft_atof(argv[3]);
		fract.param.im = ft_atof(argv[4]);
		if (fract.param.re > 2 || fract.param.re < -2
				|| fract.param.im > 2 || fract.param.im < -2)
			ft_usage();
	}
	if (fract.param.re == 0 && fract.param.im == 0
			&& fract.draw_ft == &ft_draw_julia)
			ft_putstr_fd("\0 WARNING: default", 1);
	if (fract.draw_ft == &ft_draw_julia)
		ft_putstr_fd("Julia's parameter = OK \n", 1);
	return (fract);
}
