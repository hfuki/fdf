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

static void	drawline_map_x(t_app *a, t_point start, t_point end, t_2dim obj, int** map)
{
	end.z = map[obj.y][obj.x + 1];
	end.x = (obj.x + 1 - obj.y) * SCALE + OFFSET_X;
	end.y = (obj.x + 1 + obj.y) * SCALE / ANGLE - end.z * HEIGHT_SCALE + OFFSET_Y;
	draw_line(a, start, end, 0xFFFFFF);
}

static void	drawline_map_y(t_app *a, t_point start, t_point end, t_2dim obj, int **map)
{
	end.z = map[obj.y + 1][obj.x];
	end.x = (obj.x - obj.y - 1) * SCALE + OFFSET_X;
	end.y = (obj.x + obj.y + 1) * SCALE / ANGLE - end.z * HEIGHT_SCALE + OFFSET_Y;
	draw_line(a, start, end, 0xFFFFFF);
}

void	draw_map(t_app *a, int **map, int rows, int cols)
{
	t_2dim	obj;
	t_point	start;
	t_point	end;

	obj.y = 0;
	end.x = 0;
	end.y = 0;
	end.z = 0;
	while (obj.y < rows)
	{
		obj.x = 0;
		while (obj.x < cols)
		{
			start.z = map[obj.y][obj.x];
			start.x = (obj.x - obj.y) * SCALE + OFFSET_X;
			start.y = (obj.x + obj.y) * SCALE / ANGLE - start.z * HEIGHT_SCALE + OFFSET_Y;
			if (obj.x < cols - 1)
				drawline_map_x(a, start, end, obj, map);
			if (obj.y < rows - 1)
				drawline_map_y(a, start, end, obj, map);
			obj.x++;
		}
		obj.y++;
	}
}
