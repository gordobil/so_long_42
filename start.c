/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngordobi <ngordobi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 10:56:14 by ngordobi          #+#    #+#             */
/*   Updated: 2024/05/20 14:08:21 by ngordobi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	meassure_return(int axis)
{
	if (axis == 1)
	{
		if (g_map.width < 3)
		{
			ft_putstr("Error\nMap width is too small.");
			return (0);
		}
		return (g_map.width);
	}
	else if (axis == 2)
	{
		if (g_map.height < 3)
		{
			ft_putstr("Error\nMap height is too small.");
			return (0);
		}
		return (g_map.height);
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
	read(fd, &c, 1);
	if (c != '\n')
		temp_width++;
	while (c != '\n' && rd_file > 0)
	{
		rd_file = read(fd, &c, 1);
		temp_width++;
	}
	if (temp_width > 2)
		return (--temp_width);
	return (0);
}

int	first_line(int temp_width)
{
	if (g_map.height == 0)
		g_map.width = temp_width;
	return (g_map.width);
}

int	map_meassure(char *file, int axis)
{
	int		fd;
	int		temp_width;

	fd = open(file, O_RDONLY);
	temp_width = 1;
	g_map.width = 0;
	g_map.height = 0;
	while (temp_width > 0)
	{
		temp_width = meassure_check(fd);
		if (temp_width == 0)
			break ;
		g_map.width = first_line(temp_width);
		if (temp_width != g_map.width)
		{
			ft_putstr("Error\nMap must be rectanguar.");
			return (0);
		}
		g_map.height++;
	}
	close (fd);
	return (meassure_return(axis));
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
		ft_putstr("Error\nError opening file.");
		close (fd);
		return (1);
	}
	close (fd);
	return (0);
}
