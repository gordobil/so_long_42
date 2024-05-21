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

void	load_dup(int fd)
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
		if (c == '\n' || c == '\0' || x == g_map.width)
		{
			g_map.map_dup[y][x] = '\0';
			y++;
			x = 0;
		}
		else
		{
			g_map.map_dup[y][x] = c;
			x++;
		}
	}
	close(fd);
}

void	map_dup_load(char *file)
{
	int		fd;
	int		i;

	g_map.map_dup = malloc((g_map.height + 1) * sizeof(char *));
	if (!g_map.map_dup)
		return (0);
	i = 0;
	while (i < g_map.height)
	{
		g_map.map_dup[i] = malloc((g_map.width + 1) * sizeof(char));
		if (!g_map.map_dup[i])
			return (0);
		i++;
	}
	g_map.map_dup[i] = malloc(1);
	g_map.map_dup[i] = NULL;
	fd = open(file, O_RDONLY);
	load(g_map.map_dup, fd, width);
}