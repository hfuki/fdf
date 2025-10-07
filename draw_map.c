/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfuki <hfuki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 17:17:59 by hfuki             #+#    #+#             */
/*   Updated: 2025/09/28 17:17:59 by hfuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	init_points(t_point *point)
{
	point->x = 0;
	point->y = 0;
	point->z = 0;
	return ;
}

static int	scale_decide(int rows, int cols)
{
	int scale;

	if (rows >= cols)
	{
		scale = OFFSET_X / rows;
		return (scale);
	}
	else
	{
		scale = OFFSET_Y / cols;
		return (scale);
	}
}

static void	drawline_map_x(t_app *a, t_st_en points, t_2dim obj, int **map)
{
	int scale;

	scale = scale_decide(a->rows, a->cols);
	points.end.z = map[obj.y][obj.x + 1] * scale * HEIGHT_SCALE;
	points.end.x = (obj.x + 1 - obj.y) * scale * (sqrt(3) / 2) + OFFSET_X;
	points.end.y = (obj.x + 1 + obj.y) * scale * 0.5 - points.end.z + OFFSET_Y;
	if (((points.start.z - points.end.z) == 0) && points.start.z == 0)
		draw_line(a, points, 0xFFFFFF, 0xFFFFFF);
	else if (((points.start.z - points.end.z) == 0) && points.start.z > 0)
		draw_line(a, points, COLOR, COLOR);
	else
		draw_line(a, points, COLOR, 0xFFFFFF);
}

static void	drawline_map_y(t_app *a, t_st_en points, t_2dim obj, int **map)
{
	int	scale;

	scale = scale_decide(a->rows, a->cols);
	points.end.z = map[obj.y + 1][obj.x] * scale * HEIGHT_SCALE;
	points.end.x = (obj.x - obj.y - 1) * scale * (sqrt(3) / 2) + OFFSET_X;
	points.end.y = (obj.x + obj.y + 1) * scale * 0.5 - points.end.z + OFFSET_Y;
	if (((points.start.z - points.end.z) == 0) && points.start.z == 0)
		draw_line(a, points, 0xFFFFFF, 0xFFFFFF);
	else if (((points.start.z - points.end.z) == 0) && points.start.z > 0)
		draw_line(a, points, COLOR, COLOR);
	else
		draw_line(a, points, COLOR, 0xFFFFFF);
}

void	draw_map(t_app *a, int **map)
{
	t_2dim	obj;
	t_st_en	points;
	double	scale;

	obj.y = 0;
	init_points(&points.end);
	scale = scale_decide(a->rows, a->cols);
	while (obj.y < a->rows)
	{
		obj.x = 0;
		while (obj.x < a->cols)
		{
			points.start.z = map[obj.y][obj.x] * scale * HEIGHT_SCALE;
			points.start.x = (obj.x - obj.y) * scale * (sqrt(3) / 2) + OFFSET_X;
			points.start.y = (obj.x + obj.y) * scale * 0.5 - points.start.z + OFFSET_Y;
			if (obj.x < a->cols - 1)
				drawline_map_x(a, points, obj, map);
			if (obj.y < a->rows - 1)
				drawline_map_y(a, points, obj, map);
			obj.x++;
		}
		obj.y++;
	}
}
