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
	if (chars[0] != 1)
	{
		ft_putstr("Error\nInvalid number of characters in the map.");
		return (-1);
	}
	else if (chars[1] != 1)
	{
		ft_putstr("Error\nInvalid number of exits in the map.");
		return (-1);
	}
	else if (chars[3] != 0)
	{
		ft_putstr("Error\nInvalid character found in the map.");
		return (-1);
	}
	else if (chars[2] < 1)
	{
		ft_putstr("Error\nNo coins in the map.");
		return (-1);
	}
	return (0);
}

int	find_exit(int y, int x)
{
	if (g_map.map_dup[y][x] == 'E')
		return (0);
	else if (g_map.map_dup[y][x] != '1')
		g_map.map_dup[y][x] = 'P';
	if ((x - 1 >= 0) && (g_map.map_dup[y][x - 1] != '1') &&
		(g_map.map_dup[y][x - 1] != 'P'))
	{
		if (find_exit(y, x - 1) == 0)
			return (0);
	}
	else if ((x + 1 < g_map.width) && (g_map.map_dup[y][x + 1] != '1') &&
			(g_map.map_dup[y][x + 1] != 'P'))
	{
		if (find_exit(y, x + 1) == 0)
			return (0);
	}
	else if ((y - 1 >= 0) && (g_map.map_dup[y - 1][x] != '1') &&
			(g_map.map_dup[y - 1][x] != 'P'))
	{
		if (find_exit(y - 1, x) == 0)
			return (0);
	}
	else if ((y + 1 < g_map.height) && (g_map.map_dup[y + 1][x] != '1') &&
			(g_map.map_dup[y + 1][x] != 'P'))
	{
		if (find_exit(y + 1, x) == 0)
			return (0);
	}
	return (1);
}
