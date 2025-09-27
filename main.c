#include "fdf.h"
#include <stdlib.h>
#include <unistd.h>

static int	key_hook(int keycode, void *param)
{
	t_app	*a;

	a = (t_app *)param;
	if (keycode == KEY_ESC)
	{
		if (a->win != NULL)
			mlx_destroy_window(a->mlx, a->win);
		exit(0);
	}
	return (0);
}

static int	close_hook(t_app *a)
{
	if (a->win != NULL)
		mlx_destroy_window(a->mlx, a->win);
	exit(0);
	return (0);
}

int	main(int argc, char **argv)
{
	t_app	a;
	int		**map;
	int		rows;
	int		cols;

	if (argc != 2)
		return (1);
	a.mlx = mlx_init();
	if (a.mlx == NULL)
		return (1);
	a.win = mlx_new_window(a.mlx, WIN_W, WIN_H, "fdf step1");
	if (a.mlx == NULL)
		return (1);
	a.img = mlx_new_image(a.mlx, WIN_W, WIN_H);
	a.addr = mlx_get_data_addr(a.img, &a.bpp, &a.line_len, &a.endian);
	draw_map(&a, map, 5, 5);
	mlx_put_image_to_window(a.mlx, a.win, a.img, 0, 0);
	mlx_key_hook(a.win, key_hook, &a);
	mlx_hook(a.win, 17, 0, close_hook, &a);
	mlx_loop(a.mlx);
	return (0);
}
