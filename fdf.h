/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfuki <hfuki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 16:12:01 by hfuki             #+#    #+#             */
/*   Updated: 2025/09/30 16:12:01 by hfuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include "get_next_line_bonus.h"
# include "libft/libft.h"
# include <fcntl.h>
# include <math.h>

# define WIN_W 1000
# define WIN_H 1000
# define KEY_ESC 65307
# define OFFSET_X 500
# define OFFSET_Y 250
# define SCALE 166.666
# define HEIGHT_SCALE 0.5
# define COLOR 0xFF0000

typedef struct s_app
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	int		cols;
	int		rows;
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

typedef struct s_st_en
{
	t_point	start;
	t_point	end;
}	t_st_en;

void	draw_line(t_app *a, t_st_en points, int s_color, int e_color);
void	draw_map(t_app *a, int **map);
int		**read_map(char *filename, int *rows, int *cols);

#endif
