#include "fdf.h"

static void	drawline_map_x(t_app *a, t_point start, t_point end, t_2dim obj, int map[5][5])
{
	end.z = map[obj.y][obj.x + 1];
	end.x = (obj.x + 1 - obj.y) * SCALE + OFFSET_X;
	end.y = (obj.x + 1 + obj.y) * SCALE / 2 - end.z * 5 + OFFSET_Y;
	draw_line(a, start, end, 0xFFFFFF);
}

static void	drawline_map_y(t_app *a, t_point start, t_point end, t_2dim obj, int map[5][5])
{
	end.z = map[obj.y + 1][obj.x];
	end.x = (obj.x - obj.y - 1) * SCALE + OFFSET_X;
	end.y = (obj.x + obj.y + 1) * SCALE / 2 - end.z * 5 + OFFSET_Y;
	draw_line(a, start, end, 0xFFFFFF);
}

void	draw_map(t_app *a, int map[5][5], int rows, int cols)
{
	t_2dim	obj;
	t_point	start;
	t_point	end;

	obj.y = 0;
	while (obj.y < rows)
	{
		obj.x = 0;
		while (obj.x < cols)
		{
			start.z = map[obj.y][obj.x];
			start.x = (obj.x - obj.y) * SCALE + OFFSET_X;
			start.y = (obj.x + obj.y) * SCALE / 2 - start.z * 5 + OFFSET_Y;
			if (obj.x < cols - 1)
				drawline_map_x(a, start, end, obj, map);
			if (obj.y < rows - 1)
				drawline_map_y(a, start, end, obj, map);
			obj.x++;
		}
		obj.y++;
	}
}
