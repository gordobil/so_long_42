/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_load.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngordobi <ngordobi@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 20:15:22 by ngordobi          #+#    #+#             */
/*   Updated: 2024/05/14 20:15:22 by ngordobi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "so_long.h"

char	**load_map(char **map, int fd)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	j = 0;
	while (fd > 0)
	{
		read(fd, &c, 1);
		if (c == '\n')
		{
			map[i][j] = '\0';
			i++;
		}
		else
		{
			map[i][j] = c;
			j++;
		}
	}
	return (map);
}

char	**reserve_matrix(int width, int height, char *file)
{
	char	**map;
	int		fd;
	int		i;

	i = 0;
	map = malloc((height + 1) * sizeof(char *));
	while (i < height - 1)
	{
		map[i] = malloc((width + 1) * sizeof(char));
		i++;
	}
	map[i] = malloc(1);
	map[i] = NULL;
	fd = open(file, O_RDONLY);
	return(load_map(map, fd));
}