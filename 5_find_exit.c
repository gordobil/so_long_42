/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5_check_map_aux.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngordobi <ngordobi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 14:41:47 by ngordobi          #+#    #+#             */
/*   Updated: 2024/06/19 13:43:49 by ngordobi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
