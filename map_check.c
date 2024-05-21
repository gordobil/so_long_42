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

int	characters_aux(int chars[4], int letter, int y, int x)
{
	if (letter == 0)
	{
		if (chars[letter] == 0)
		{
			g_map.start_p_y = y;
			g_map.start_p_x = x;
			return (1);
		}
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

int	characters()
{
	int	x;
	int	y;
	int	chars[4] = {0, 0, 0, 0};

//	chars_to_zero(&chars[0], &chars[1], &chars[2], &chars[3]);
	y = 1;
	while (map[y] != NULL)
	{
		x = 1;
		while (g_map.map[y][x] != '\0')
		{
			if (g_map.map[y][x] == 'P')
				chars[0] = characters_aux(chars, 0, y, x);
			else if (g_map.map[y][x] == 'E')
				chars[1] = characters_aux(chars, 1, y, x);
			else if (g_map.map[y][x] == 'C')
				chars[2]++;
			else if (g_map.map[y][x] != '0' || map[y][x] != '1')
				chars[3] = -1;
			x++;
		}
		y++;
	}
	return (characters_ret(chars));
}

int	borders_aux(int y, int x, int axis)
{
	if (axis == 1)
	{
		while (g_map.map[y][x] != '\0')
		{
			if (g_map.map[y][x] != '1')
				break ;
			x++;
		}
		if (g_map.map[y][x] != '\0')
			return (-1);
	}
	else
	{
		if(g_map.map[y][x] != '1')
			return (-1);
		while (g_map.map[y][x + 1] != '\0')
			x++;
		if(g_map.map[y][x] != '1')
			return (-1);
	}
	return (0);
}

int	borders()
{
	int	y;
	int	x;

	y = 0;
	while (g_map.map[y] != NULL)
	{
		x = 0;
		if (y == 0 || (g_map.map[y + 1] == NULL))
		{
			if (borders_aux(g_map.map, y, x, 1) != 0)
				break ;
		}
		else
		{
			if (borders_aux(g_map.map, y, x, 2) != 0)
				break ;
		}
		y++;
	}
	if (g_map.map[y] != NULL)
	{
		ft_putstr("Error\nError in map borders.");
		return (-1);
	}
	return (0);
}

int	map_check()
{
	int	errors;

	errors = borders();
	if (errors != 0)
		return(-1);
	errors = characters();
	if (errors != 0)
		return(-1);
	errors = find_exit(g_map.start_p_y, g_map.start_p_x);
	if (errors == 1)
	{
		ft_putstr("Error\nThere's no path to exit.");
		return (-1);
	}
	else if (errors != 0)
		return(-1);
	return (0);
}