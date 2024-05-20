/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_load.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngordobi <ngordobi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 20:15:22 by ngordobi          #+#    #+#             */
/*   Updated: 2024/05/20 13:55:40 by ngordobi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**load(char **map, int fd, int width)
{
	int		y;
	int		x;
	int		rd_file;
	char	c;

	y = 0;
	x = 0;
	rd_file = 1;
	while (rd_file > 0)
	{
		rd_file = read (fd, &c, 1);
		if (c == '\n' || c == '\0' || x == width)
		{
			map[y][x] = '\0';
			y++;
			x = 0;
		}
		else
		{
			map[y][x] = c;
			x++;
		}
	}
	close(fd);
	return (map);
}

char	**map_load(int width, int height, char *file)
{
	char	**map;
	int		fd;
	int		i;

	map = malloc((height + 1) * sizeof(char *));
	if (!map)
		return (0);
	i = 0;
	while (i < height)
	{
		map[i] = malloc((width + 1) * sizeof(char));
		if (!map[i])
			return (0);
		i++;
	}
	map[i] = malloc(1);
	map[i] = NULL;
	fd = open(file, O_RDONLY);
	return(load(map, fd, width));
}