/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5_check_map_aux.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngordobi <ngordobi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 14:41:47 by ngordobi          #+#    #+#             */
/*   Updated: 2024/06/18 14:12:01 by ngordobi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	characters_ret(int chars[4])
{
	int	errors;

	errors = 0;
	if (chars[0] != 1)
	{
		ft_printf("Error\nInvalid number of players in the map\n");
		errors = -1;
	}
	if (chars[1] != 1)
	{
		ft_printf("Error\nInvalid number of exits in the map\n");
		errors = -1;
	}
	if (chars[2] < 1)
	{
		ft_printf("Error\nNo coins found in the map\n");
		errors = -1;
	}
	if (chars[3] != 0)
	{
		ft_printf("Error\nInvalid character found in the map\n");
		errors = -1;
	}
	return (errors);
}

int	start_coords(char **map, char axis)
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
				if (axis == 'y')
					return (y);
				else if (axis == 'x')
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

int	find_exit(int y, int x, char **map)
{
	static int	exit;

	if (map[y][x] == 'E')
		exit = 1;
	if (map[y][x] != '1')
		map[y][x] = 'X';
	if (exit == 1 && count(map, 'C') == 0)
		return (0);
	if ((x - 1 > 0) && map[y][x - 1] != '1' && map[y][x - 1] != 'X')
		if (find_exit(y, x - 1, map) == 0)
			return (0);
	if (x + 1 < count(map, 'w') && map[y][x + 1] != '1' && map[y][x + 1] != 'X')
		if (find_exit(y, x + 1, map) == 0)
			return (0);
	if ((y - 1 > 0) && map[y - 1][x] != '1' && map[y - 1][x] != 'X')
		if (find_exit(y - 1, x, map) == 0)
			return (0);
	if (y + 1 < count(map, 'h') && map[y + 1][x] != '1' && map[y + 1][x] != 'X')
		if (find_exit(y + 1, x, map) == 0)
			return (0);
	if (exit != 1 && count(map, 'C') != 0)
		return (3);
	else if (exit != 1)
		return (1);
	return (2);
}
