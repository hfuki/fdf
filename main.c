/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfuki <hfuki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 17:18:22 by hfuki             #+#    #+#             */
/*   Updated: 2025/09/28 17:18:22 by hfuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	free_all(int **arr, int rows)
{
	int	i;

	i = 0;
	while (i < rows)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	return ;
}

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
	map = read_map(argv[1], &rows, &cols);
	draw_map(&a, map, rows, cols);
	free_all(map, rows);
	mlx_put_image_to_window(a.mlx, a.win, a.img, 0, 0);
	mlx_key_hook(a.win, key_hook, &a);
	mlx_hook(a.win, 17, 0, close_hook, &a);
	mlx_loop(a.mlx);
	return (0);
}
