/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngordobi <ngordobi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 20:09:59 by ngordobi          #+#    #+#             */
/*   Updated: 2024/05/20 14:58:17 by ngordobi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	characters_aux(int chars[4], int letter)
{
	if (letter == 0)
	{
		if (chars[letter] == 0)
			return (1);
		else
		{
			ft_putstr("Error\nToo many characters in the map");
			return (-1);
		}
	}
	else if (letter == 1)
	{
		if (chars[letter] == 0)
			return (1);
		else
		{
			ft_putstr("Error\nToo many exits in the map");
			return (-1);
		}
	}
	return (0);
}

int	characters(int y, int x, char **map)
{
	int	i;
	int	chars[4];

	i = 0;
	while (i < 4)
		chars[i++] = 0;
	y = 1;
	while (map[y] != NULL)
	{
		x = 0;
		while (map[y][x++] != '\0')
		{
			if (map[y][x] == 'P')
				chars[0] = characters_aux(chars, 0);
			else if (map[y][x] == 'E')
				chars[1] = characters_aux(chars, 1);
			else if (map[y][x] == 'C')
				chars[2]++;
			else if (map[y][x] != '0' && map[y][x] != '1' && map[y][x] != 'P' &&
					map[y][x] != 'E' && map[y][x] != 'C' && map[y][x] != '\0')
				chars[3] = -1;
		}
		y++;
	}
	return (characters_ret(chars));
}

int	borders_aux(int y, int x, int axis, char **map)
{
	if (axis == 1)
	{
		while (map[y][x] != '\0')
		{
			if (map[y][x] != '1')
				break ;
			x++;
		}
		if (map[y][x] != '\0')
			return (-1);
	}
	else
	{
		if (map[y][x] != '1')
			return (-1);
		while (map[y][x + 1] != '\0')
			x++;
		if (map[y][x] != '1')
			return (-1);
	}
	return (0);
}

int	borders(int y, int x, char **map)
{
	while (map[y] != NULL)
	{
		x = 0;
		if (y == 0 || (map[y + 1] == NULL))
		{
			if (borders_aux(y, x, 1, map) != 0)
				break ;
		}
		else
		{
			if (borders_aux(y, x, 2, map) != 0)
				break ;
		}
		y++;
	}
	if (map[y] != NULL)
	{
		ft_putstr("Error\nError in map borders");
		return (-1);
	}
	return (0);
}

int	check_map(char **map)
{
	int	start_y;
	int	start_x;
	int	exit;

	if (borders(0, 0, map) != 0)
		return (-1);
	if (characters(1, 1, map) != 0)
		return (-1);
	start_y = start_coords(map, 'y');
	start_x = start_coords(map, 'x');
	if (start_y < 0 || start_x < 0)
		return (-1);
	exit = find_exit(start_y, start_x, map);
	if (exit == 1)
		ft_putstr("Error\nThere's no path to exit");
	else if (exit == 2)
		ft_putstr("Error\nCan't collect all coins");
	else if (exit == 3)
		ft_putstr("Error\nThere's no path to exit\nCan't collect all coins");
	if (exit != 0)
		return (-1);
	return (0);
}
