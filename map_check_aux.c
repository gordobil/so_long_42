/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_aux.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngordobi <ngordobi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 14:41:47 by ngordobi          #+#    #+#             */
/*   Updated: 2024/05/20 14:58:34 by ngordobi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	characters_ret(int chars[4])
{
	int	errors;

	errors = 0;
	if (chars[0] != 1)
	{
		ft_putstr("Error\nInvalid number of characters in the map.");
		errors = -1;
	}
	else if (chars[1] != 1)
	{
		ft_putstr("Error\nInvalid number of exits in the map.");
		errors = -1;
	}
	else if (chars[3] != 0)
	{
		ft_putstr("Error\nInvalid character found in the map.");
		errors = -1;
	}
	else if (chars[2] < 1)
	{
		ft_putstr("Error\nNo coins in the map.");
		errors = -1;
	}
	return (errors);
}

int	start_point(char **map, int axis)
{
	int	y;
	int	x;

	y = 0;
	while (map[y] != NULL)
	{
		x = 0;
		while (map[y][x] != '\0')
		{
			if (map[y][x] == 'P')
			{
				if (axis == 1)
					return (y);
				else if (axis == 2)
					return (x);
				else
					return (-1);
			}
			x++;
		}
		y++;
	}
	return (-1);
}

int	find_exit(int y, int x, char **map, int map_w, int map_h)
{
	if (map[y][x] == 'E')
		return (0);
	else if (map[y][x] != '1')
		map[y][x] = 'P';
	if ((x - 1 >= 0) && (map[y][x - 1] != '1') &&
		(map[y][x - 1] != 'P'))
	{
		if (find_exit(y, x - 1, map, map_w, map_h) == 0)
			return (0);
	}
	else if ((x + 1 < map_w) && (map[y][x + 1] != '1') &&
			(map[y][x + 1] != 'P'))
	{
		if (find_exit(y, x + 1, map, map_w, map_h) == 0)
			return (0);
	}
	else if ((y - 1 >= 0) && (map[y - 1][x] != '1') &&
			(map[y - 1][x] != 'P'))
	{
		if (find_exit(y - 1, x, map, map_w, map_h) == 0)
			return (0);
	}
	else if ((y + 1 < map_h) && (map[y + 1][x] != '1') &&
			(map[y + 1][x] != 'P'))
	{
		if (find_exit(y + 1, x, map, map_w, map_h) == 0)
			return (0);
	}
	return (1);
}
