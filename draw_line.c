/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfuki <hfuki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 17:17:40 by hfuki             #+#    #+#             */
/*   Updated: 2025/09/28 17:17:40 by hfuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	put_pixel(t_app *a, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= WIN_W || y < 0 || y >= WIN_H)
		return ;
	dst = a->addr + (y * a->line_len + x * (a->bpp / 8));
	*(unsigned int *)dst = color;
}

static void	trend_line(t_st_en points, int *px, int *py)
{
	if (points.start.x < points.end.x)
		*px = 1;
	else
		*px = -1;
	if (points.start.y < points.end.y)
		*py = 1;
	else
		*py = -1;
	return ;
}

static int	bresenham(int *err, t_2dim *dif, t_2dim *step, t_point *start)
{
	int	err2;

	err2 = *err * 2;
	if (err2 > -dif->y)
	{
		*err -= dif->y;
		start->x += step->x;
	}
	if (err2 < dif->x)
	{
		*err += dif->x;
		start->y += step->y;
	}
	return (err2);
}

void	draw_line(t_app *a, t_st_en points, int s_color, int e_color)
{
	t_2dim	dif;
	t_2dim	step;
	int		err;
	int		err2;
	int		color;

	dif.x = abs(points.start.x - points.end.x);
	dif.y = abs(points.start.y - points.end.y);
	trend_line(points, &step.x, &step.y);
	err = dif.x - dif.y;
	color = s_color;
	while (points.start.x != points.end.x || points.start.y != points.end.y)
	{
		put_pixel(a, points.start.x, points.start.y, color);
		if ((points.start.z - points.end.z) > 0)
			color -= (s_color - e_color) / dif.y;
		else if ((points.start.z - points.end.z) < 0)
			color += (s_color - e_color) / dif.x;
		err2 = bresenham(&err, &dif, &step, &points.start);
	}
	put_pixel(a, points.start.x, points.start.y, color);
}
