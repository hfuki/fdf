#ifndef FDF_H
# define FDF_H

# include "minilibx/mlx.h"

# define WIN_W 800
# define WIN_H 600
# define KEY_ESC 65307
# define OFFSET_X 200
# define OFFSET_Y 100
# define SCALE 20

typedef struct s_app
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_app;

typedef struct s_point
{
	int	x;
	int	y;
	int	z;
}	t_point;

typedef struct s_2dim
{
	int	x;
	int	y;
}	t_2dim;

void	draw_line(t_app *a, t_point start, t_point end, int color);
void	draw_map(t_app *a, int map[5][5], int rows, int cols);

#endif
