/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_load_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngordobi <ngordobi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 20:15:22 by ngordobi          #+#    #+#             */
/*   Updated: 2024/06/04 13:56:05 by ngordobi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**load(int fd, char **map, int w, int y)
{
	int		rd_file;
	int		x;
	char	c;

	rd_file = 1;
	x = 0;
	while (rd_file > 0)
	{
		rd_file = read (fd, &c, 1);
		if (rd_file < 1)
			break ;
		if (x == w || c == '\n' || c == '\0' || c == '\r')
		{
			map[y++][x] = '\0';
			read (fd, &c, 1);
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

char	**load_map(char *file, int w, int h)
{
	char	**map;
	int		fd;
	int		i;

	map = malloc((h + 1) * sizeof(char *));
	if (!map)
		return (0);
	i = 0;
	while (i < h)
	{
		map[i] = malloc((w + 1) * sizeof(char));
		if (!map[i])
			return (0);
		i++;
	}
	map[i] = malloc(1);
	map[i] = NULL;
	fd = open(file, O_RDONLY);
	map = load(fd, map, w, 0);
	if (map[i - 1][0] == '\0')
	{
		free (map[i]);
		map[i - 1] = NULL;
	}
	return (map);
}
