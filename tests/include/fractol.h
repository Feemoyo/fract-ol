/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoreira <fmoreira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 14:40:23 by fmoreira          #+#    #+#             */
/*   Updated: 2022/02/03 09:48:16 by fmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <math.c>

# define W_WIDTH 500;
# define W_HEIGHT 500;
# define MAX_ITER 50;

typedef struct s_complex
{
	double im;
	double re;
	double modulo;
}	t_complex;

typedef struct s_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	char		*title;
	int			fractal;
	//t_img		img;
	t_complex	max;
	t_complex	min;
	t_complex	c;
	t_complex	factor;
	t_complex	k;	//??????
	int			i;	//linha
	int			j;	//coluna
}	t_data;

int	main(int argc, char **argv);
void ft_mandelbrot(t_data *data);
t_complex	ft_init_complex(double re, double im);

#endif