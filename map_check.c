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
			ft_putstr("Error\nToo many characters in the map.");
			return (-1);
		}
	}
	else if (letter == 1)
	{
		if (chars[letter] == 0)
			return (1);
		else
		{
			ft_putstr("Error\nToo many exits in the map.");
			return (-1);
		}
	}
	return (0);
}

int	characters(char **map)
{
	int	x;
	int	y;
	int	*chars;

	chars = chars_to_zero(4);
	y = 1;
	while (map[y] != NULL)
	{
		x = 1;
		while (map[y][x] != '\0')
		{
			if (map[y][x] == 'P')
				chars[0] = characters_aux(chars, 0);
			else if (map[y][x] == 'E')
				chars[1] = characters_aux(chars, 1);
			else if (map[y][x] == 'C')
				chars[2]++;
			else if (map[y][x] != '0' || map[y][x] != '1')
				chars[3] = -1;
			x++;
		}
		y++;
	}
	return (characters_ret(chars));
}

int	borders_aux(char **map, int y, int x, int axis)
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
		if(map[y][x] != '1')
			return (-1);
		while (map[y][x + 1] != '\0')
			x++;
		if(map[y][x] != '1')
			return (-1);
	}
	return (0);
}

int	borders(char **map)
{
	int	y;
	int	x;
	
	y = 0;
	while (map[y] != NULL)
	{
		x = 0;
		if (y == 0 || (map[y + 1] == NULL))
		{
			if (borders_aux(map, y, x, 1) != 0)
				break ;
		}
		else
		{
			if (borders_aux(map, y, x, 2) != 0)
				break ;
		}
		y++;
	}
	if (map[y] != NULL)
	{
		ft_putstr("Error: map borders.");
		return (-1);
	}
	return (0);
}

int	map_check(char **map)
{
	int	errors;

	errors = borders(map);
	if (errors != 0)
		return(-1);
	errors = characters(map);
	if (errors != 0)
		return(-1);
	return (0);
}