#include "minilibx-linux/mlx.h"

void draw_y_line (void *mlx, void *win, int x1, int y1, int y2, int color);
void draw_x_line (void *mlx, void *win, int x1, int x2, int y1, int color);

int main()
{
	void *mlx = mlx_init();
	void *win = mlx_new_window(mlx, 640, 360, "Tutorial Window - Draw Line");

	//mlx_pixel_put(mlx, win, 640/2, 360/2, 0xFFFFFF);
	draw_y_line(mlx, win, 640/2, 360/2, (360 - (360/4)), 0xFFFFFF);
	draw_y_line(mlx, win, (640 - (640/4)), 360/2, (360 - (360/4)), 0xFFFFFF);
	draw_x_line(mlx, win, 640/2, (640 - (640/4)), (360 - (360/4)), 0xFFFF1F);
	draw_x_line(mlx, win, 640/2, (640 - (640/4)), (360 - (360/4)), 0xFFFF1F);
	mlx_loop(mlx);
}

void draw_y_line (void *mlx, void *win, int x1, int y1, int y2, int color)
{
	int yx;

	yx = y1;
	while (yx <= y2 )
	{
		mlx_pixel_put(mlx, win, x1, yx, color);
		yx++;
	}
}

void draw_x_line (void *mlx, void *win, int x1, int x2, int y1, int color)
{
	int xx;

	xx = x1;
	while (xx <= x2 )
	{
		mlx_pixel_put(mlx, win, xx, y1, color);
		xx++;
	}
}