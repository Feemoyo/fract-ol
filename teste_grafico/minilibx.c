/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minilibx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoreira <fmoreira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 15:49:53 by fmoreira          #+#    #+#             */
/*   Updated: 2021/11/09 16:53:32 by fmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "mlx.h"

int main()
{
    void *mlx = mlk_init();
    void *win = mlx_new_window(mlx, 600, 300 "Drawing a pixel :D");

    mlx_pixel_put(mlx, win, 600/2, 300/2, 0xFFFFFF);

    mlx_loop(mlx);
}