/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_check_map_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngordobi <ngordobi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 20:09:59 by ngordobi          #+#    #+#             */
/*   Updated: 2024/06/21 12:22:40 by ngordobi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	characters_aux_bonus(int chars[4], int letter)
{
	if (letter == 0)
	{
		if (chars[letter] == 0)
			return (1);
		else
		{
			ft_printf("Error\nToo many characters in the map\n");
			return (-1);
		}
	}
	else if (letter == 1)
	{
		if (chars[letter] == 0)
			return (1);
		else
		{
			ft_printf("Error\nToo many exits in the map\n");
			return (-1);
		}
	}
	return (0);
}

int	characters_bonus(int y, int x, char **map)
{
	int	i;
	int	chars[4];

	i = 0;
	while (i < 4)
		chars[i++] = 0;
	y = -1;
	while (map[++y] != NULL)
	{
		x = -1;
		while (map[y][++x] != '\0')
		{
			if (map[y][x] == 'P')
				chars[0] = characters_aux_bonus(chars, 0);
			else if (map[y][x] == 'E')
				chars[1] = characters_aux_bonus(chars, 1);
			else if (map[y][x] == 'C')
				chars[2]++;
			else if (map[y][x] != '0' && map[y][x] != '1' && map[y][x] != 'P' &&
					map[y][x] != 'E' && map[y][x] != 'C' && map[y][x] != 'B' &&
					map[y][x] != '\0')
			chars[3] = -1;
		}
	}
	return (characters_ret(chars));
}

int	check_map_bonus(char **map)
{
	int	start_y;
	int	start_x;
	int	exit;

	if (borders(0, 0, map) != 0)
		return (-1);
	ft_printf("1\n");
	if (characters_bonus(1, 1, map) != 0)
		return (-1);
	ft_printf("1\n");
	start_y = start_coords(map, 'y');
	start_x = start_coords(map, 'x');
	if (start_y < 0 || start_x < 0)
		return (-1);
	exit = find_exit_bonus(start_y, start_x, map);
	if (exit == 1)
		ft_printf("Error\nThere's no path to exit\n");
	else if (exit == 2)
		ft_printf("Error\nCan't collect all coins\n");
	else if (exit == 3)
		ft_printf("Error\nThere's no path to exit\nCan't collect all coins\n");
	if (exit != 0)
		return (-1);
	return (0);
}
