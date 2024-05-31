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

int	meassure_return(int axis, int w, int h)
{
	if (axis == 1)
	{
		if (w < 3)
		{
			ft_putstr("Error\nMap width is too small.");
			return (0);
		}
		return (w);
	}
	else if (axis == 2)
	{
		if (h < 3)
		{
			ft_putstr("Error\nMap height is too small.");
			return (0);
		}
		return (h);
	}
	return (0);
}

int	meassure_check(int fd)
{
	char	c;
	int		rd;
	int		temp_w;

	rd = 1;
	temp_w = 0;
	while (rd > 0)
	{
		rd = read(fd, &c, 1);
		if (c == '\n' || c == '\0' || c == '\r')
			break ;
		temp_w++;
	}
	rd = read(fd, &c, 1);
	if (rd == 0)
		return (-1);
	return (temp_w);
}

int	map_meassure(char *file, int axis)
{
	int	fd;
	int	w;
	int	h;
	int	temp_w;

	fd = open(file, O_RDONLY);
	w = 0;
	h = 0;
	temp_w = 1;
	while (temp_w > 0)
	{
		temp_w = meassure_check(fd);
		if (h == 0)
			w = temp_w;
		if (temp_w > 0 && temp_w == w)
			h++;
		else if (temp_w == -1)
		{
			h++;
			break ;
		}
	}
	return (meassure_return(axis, w, h));
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
