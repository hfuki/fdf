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

static void	drawline_map_x(t_app *a, t_st_en points, t_2dim obj, int **map)
{
	points.end.z = map[obj.y][obj.x + 1];
	points.end.x = (obj.x + 1 - obj.y) * SCALE + OFFSET_X;
	points.end.y = (obj.x + 1 + obj.y) * SCALE / ANGLE
		- points.end.z * HEIGHT_SCALE + OFFSET_Y;
	if (((points.start.z - points.end.z) == 0) && points.start.z == 0)
		draw_line(a, points, 0xFFFFFF, 0xFFFFFF);
	else if (((points.start.z - points.end.z) == 0) && points.start.z > 0)
		draw_line(a, points, COLOR, COLOR);
	else
		draw_line(a, points, COLOR, 0xFFFFFF);
}

static void	drawline_map_y(t_app *a, t_st_en points, t_2dim obj, int **map)
{
	points.end.z = map[obj.y + 1][obj.x];
	points.end.x = (obj.x - obj.y - 1) * SCALE + OFFSET_X;
	points.end.y = (obj.x + obj.y + 1) * SCALE / ANGLE
		- points.end.z * HEIGHT_SCALE + OFFSET_Y;
	if (((points.start.z - points.end.z) == 0) && points.start.z == 0)
		draw_line(a, points, 0xFFFFFF, 0xFFFFFF);
	else if (((points.start.z - points.end.z) == 0) && points.start.z > 0)
		draw_line(a, points, COLOR, COLOR);
	else
		draw_line(a, points, COLOR, 0xFFFFFF);
}

void	draw_map(t_app *a, int **map, int rows, int cols)
{
	t_2dim	obj;
	t_st_en	points;

	obj.y = 0;
	points.end.x = 0;
	points.end.y = 0;
	points.end.z = 0;
	while (obj.y < rows)
	{
		obj.x = 0;
		while (obj.x < cols)
		{
			points.start.z = map[obj.y][obj.x];
			points.start.x = (obj.x - obj.y) * SCALE + OFFSET_X;
			points.start.y = (obj.x + obj.y) * SCALE / ANGLE
				- points.start.z * HEIGHT_SCALE + OFFSET_Y;
			if (obj.x < cols - 1)
				drawline_map_x(a, points, obj, map);
			if (obj.y < rows - 1)
				drawline_map_y(a, points, obj, map);
			obj.x++;
		}
		obj.y++;
	}
}
