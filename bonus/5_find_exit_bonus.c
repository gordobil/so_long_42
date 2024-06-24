/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5_find_exit_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngordobi <ngordobi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 14:41:47 by ngordobi          #+#    #+#             */
/*   Updated: 2024/06/24 14:48:26 by ngordobi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	find_exit_return(int exit, int coins)
{
	if (exit != 1 && coins != 0)
		return (3);
	else if (exit != 1)
		return (1);
	return (2);
}

char	put_x(char position)
{
	if (position != '1')
		return ('X');
	return (position);
}

int	check_e(char position, int exit)
{
	if ((position == 'E' && exit == 0) || exit == 1)
		return (1);
	return (0);
}

int	find_exit_bonus(int y, int x, char **map)
{
	static int	exit;

	exit = check_e(map[y][x], exit);
	map[y][x] = put_x(map[y][x]);
	if (exit == 1 && count(map, 'C') == 0)
		return (0);
	if ((x - 1 > 0) && map[y][x - 1] != '1' && map[y][x - 1] != 'X'
		&& map[y][x - 1] != 'B')
		if (find_exit_bonus(y, x - 1, map) == 0)
			return (0);
	if (x + 1 < count(map, 'w') && map[y][x + 1] != '1' && map[y][x + 1] != 'X'
		&& map[y][x + 1] != 'B')
		if (find_exit_bonus(y, x + 1, map) == 0)
			return (0);
	if ((y - 1 > 0) && map[y - 1][x] != '1' && map[y - 1][x] != 'X'
		&& map[y - 1][x] != 'B')
		if (find_exit_bonus(y - 1, x, map) == 0)
			return (0);
	if (y + 1 < count(map, 'h') && map[y + 1][x] != '1' && map[y + 1][x] != 'X'
		&& map[y + 1][x] != 'B')
		if (find_exit_bonus(y + 1, x, map) == 0)
			return (0);
	return (find_exit_return(exit, count(map, 'C')));
}
