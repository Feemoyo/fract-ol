#include <stdio.h>
#include "./minilibx/mlx.h"
#include <stdlib.h>

# define WIN_WIDTH 500
# define WIN_HEIGHT 500

# define IMG_WIDTH 500
# define IMG_HEIGHT 500

# define MAX 80

typedef struct	s_img
{
	void		*img_ptr;
	int			*data;
	//You don't need to understand the 3 values below.
	//After declaration, it will be automatically initialized when passed to mlx_get_data_addr function.
	int			size_l;
	int			bpp;
	int			endian;
}				t_img;

typedef struct	s_mlx
{
	void		*mlx_ptr;
	void		*win;
}				t_mlx;

int	main(void)
{
	t_mlx	*mlx;
	t_img	img;

	mlx = malloc(sizeof(t_mlx) * 1);
	mlx->mlx_ptr = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "A simple example");
	img.img_ptr = mlx_new_image(mlx->mlx_ptr, IMG_WIDTH, IMG_HEIGHT);
	img.data = (int *)mlx_get_data_addr(img.img_ptr, &img.bpp, &img.size_l, &img.endian);

	//The reason why I cast to (int *): If I let this as void * type, whenever I refer to the array values, I need to multiply them by 4.
	//Check out keuhdall's github linked in my README for more information.
	double x_new;
	double c_re;
	double c_im;
	double x;
	double y;
	int iteration;
	int        row;
	int        col;
//	int        max;

	col = 0;
	while (col < IMG_HEIGHT)
	{
		row = 0;
		while (row < IMG_WIDTH) // 0 ; 250
		{
			c_re = (row - IMG_WIDTH / 2.0) * 4.0 / IMG_WIDTH; // -2 ; 0
			c_im = (col - IMG_HEIGHT / 2.0) * 4.0 / IMG_HEIGHT; // -2; 0
			x = 0;
			y = 0;
			iteration = 0;
			while (x * x + y * y <= 4 && iteration < MAX) { // 0 <= 4 && 0 < 50
				x_new = x * x - y * y + c_re; // 0
				y = 2 * x * y + c_im; // 0
				x = x_new; // 0
				iteration++; // 1
			}
			if (iteration < MAX)
				img.data[col * IMG_WIDTH + row] = 0xFFF + iteration * 30.05;
			else
				img.data[col * IMG_WIDTH + row] = 0x000000;
			row++;
		}
		col++;
	}

	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win, img.img_ptr, 0, 0);
	mlx_loop(mlx->mlx_ptr);
	return (0);
}
