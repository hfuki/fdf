/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfuki <hfuki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 17:18:39 by hfuki             #+#    #+#             */
/*   Updated: 2025/09/28 17:18:39 by hfuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "get_next_line_bonus.h"
#include "libft/libft.h"
#include <unistd.h>
#include <fcntl.h>

static int	*parse_line(char *line, int *cols)
{
	char	**splited;
	int		*row;
	int		i;

	splited = ft_split(line, ' ');
	if (!splited)
		return (NULL);
	(*cols) = 0;
	while (splited[*cols])
		(*cols)++;
	row = malloc(sizeof(int) * (*cols));
	if (!row)
		return (NULL);
	i = 0;
	while (i < *cols)
	{
		row[i] = ft_atoi(splited[i]);
		free(splited[i]);
		i++;
	}
	free(splited);
	return (row);
}

static int	**extend_map(int **map, int *rows, int *row)
{
	int	**new_map;
	int	i;

	new_map = malloc(sizeof(int *) * ((*rows) + 1));
	if (!new_map)
		return (NULL);
	i = 0;
	while (i < *rows)
	{
		new_map[i] = map[i];
		i++;
	}
	new_map[i] = row;
	free(map);
	return (new_map);
}

int	**read_map(char *filename, int *rows, int *cols)
{
	int		fd;
	char	*line;
	int		**map;
	int		tmp_cols;
	int		*row;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (NULL);
	*rows = 0;
	map = NULL;
	line = get_next_line(fd);
	while (line)
	{
		row = parse_line(line, &tmp_cols);
		if (*rows == 0)
			*cols = tmp_cols;
		map = extend_map(map, rows, row);
		(*rows)++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	return (map);
}
