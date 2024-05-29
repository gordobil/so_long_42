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
	{
		if (rd_file > 0)
			return (--temp_width);
		return (temp_width);
	}
	return (0);
}

int	first_line(int temp_width, int w, int h)
{
	if (h == 0)
		w = temp_width;
	return (w);
}

int	map_meassure(char *file, int axis)
{
	int	fd;
	int	temp_width;
	int	w;
	int	h;

	fd = open(file, O_RDONLY);
	temp_width = 1;
	w = 0;
	h = 0;
	while (temp_width > 0)
	{
		temp_width = meassure_check(fd);
		if (temp_width == 0)
			break ;
		w = first_line(temp_width, w, h);
		if (temp_width != w)
		{
			ft_putstr("Error\nMap must be rectanguar.");
			return (0);
		}
		h++;
	}
	close (fd);
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
