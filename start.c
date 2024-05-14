/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngordobi <ngordobi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 10:56:14 by ngordobi          #+#    #+#             */
/*   Updated: 2024/05/14 13:34:50 by ngordobi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "so_long.h"

int	meassure_return(int axis, int width, int height)
{
	if (height == width)
	{
		ft_putstr("Map must be rectangular");
		return (0);
	}
	if (axis == 1)
	{
		if (width < 3)
		{
			ft_putstr("Map width too small.");
			return (0);
		}
		return (width);
	}
	else if (axis == 2)
	{
		if (height < 3)
		{
			ft_putstr("Map height too small.");
			return (0);
		}
		return (height);
	}
	return (0);
}

int	meassure_check(int fd)
{
	char	c;
	int		temp_width;
	int		rd_file;

	temp_width = 0;
	rd_file = 1;
	while (c != '\n' && rd_file > 0)
	{
		rd_file = read(fd, &c, 1);
		temp_width++;
	}
	temp_width--;
	if (c == '\0')
		return (-1);
	return (temp_width);
}

int	first_line(int height, int width, int temp_width)
{
	if (height == 0)
			width = temp_width;
	return (width);
}

int	map_meassure(char *file, int axis)
{
	int		fd;
	int		width;
	int		temp_width;
	int		height;

	fd = open(file, O_RDONLY);
	temp_width = 1;
	width = 0;
	height = 0;
	while (temp_width > 0)
	{
		temp_width = meassure_check(fd);
		if (temp_width == -1)
			break ;
		width = first_line(height, width, temp_width);
		if (temp_width != width)
		{
			ft_putstr("Map width error.");
			return (0);
		}
		height++;
	}
	close (fd);
	return (meassure_return(axis, width, height));
}

int	check_file(char *file)
{
	int	i;
	int	fd;

	i = 0;
	while (file[i + 1] != '\0')
		i++;
	if (file[i - 3] != '.' || file[i - 2] != 'b'
		|| file[i - 1] != 'e' || file[i] != 'r')
		return (1);
	fd = open(file, O_RDONLY);
	if (fd <= 0)
	{
		ft_putstr("Error opening file.");
		close (fd);
		return (1);
	}
	close (fd);
	return (0);
}

/*unsigned int	map_size(char *file)
{
    int		fd;
	int		size;
	int		rd_file;
	char	c;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr("Error opening file.");
		return (0);
	}
	size = 0;
	rd_file = 1;
	while (rd_file > 0)
	{
		rd_file = read(fd, &c, 1);
		size++;
	}
	size--;
	close (fd);
	return (size);
}*/
