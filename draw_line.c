#include "fdf.h"
#include <stdlib.h>
#include <stdio.h>

static void	put_pixel(t_app *a, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= WIN_W || y < 0 || y >= WIN_H)
		return ;
	dst = a->addr + (y * a->line_len + x * (a->bpp / 8));
	*(unsigned int *)dst = color;
}

static void	trend_line(t_point start, t_point end, int *px, int *py)
{
	if (start.x < end.x)
		*px = 1;
	else
		*px = -1;
	if (start.y < end.y)
		*py = 1;
	else
		*py = -1;
	return ;
}

void	draw_line(t_app *a, t_point start, t_point end, int color)
{
	t_2dim	dif;
	t_2dim	step;
	int	err;
	int	err2;

	dif.x = abs(start.x - end.x);
	dif.y = abs(start.y - end.y);
	trend_line(start, end, &step.x, &step.y);
	err = dif.x - dif.y;
	while (start.x != end.x || start.y != end.y)
	{
		put_pixel(a, start.x, start.y, color);
		err2 = err * 2;
		if (err2 > -dif.y)
		{
			err -= dif.y;
			start.x += step.x;
		}
		if (err2 < dif.x)
		{
			err += dif.x;
			start.y += step.y;
		}
	}
	put_pixel(a, start.x, start.y, color);
}
