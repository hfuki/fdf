#ifndef FDF_H
# define FDF_H

# include <mlx.h>

# define WIN_W 1000
# define WIN_H 1000
# define KEY_ESC 65307
# define OFFSET_X 400
# define OFFSET_Y 300
# define SCALE 20
# define HEIGHT_SCALE 7
# define ANGLE 1.15

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
void	draw_map(t_app *a, int **map, int rows, int cols);
int		**read_map(char *filename, int *rows, int *cols);

#endif
