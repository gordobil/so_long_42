/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_put_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngordobi <ngordobi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 13:24:45 by ngordobi          #+#    #+#             */
/*   Updated: 2024/06/14 12:59:44 by ngordobi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_map(char **map, t_mlx data)
{
	int	y;
	int	x;

	y = 0;
	while (map[y] != NULL)
	{
		x = 0;
		put_cliff(&data, 1, y * 64);
		while (map[y][x] != '\0')
		{
			if (map[y][x] == '0')
				put_water(&data, x * 64, y * 64);
			else if (map[y][x] == '1')
				put_cliff(&data, x * 64, y * 64);
			else if (map[y][x] == 'P')
				put_ship_r(&data, x * 64, y * 64);
			else if (map[y][x] == 'C')
				put_buoy(&data, x * 64, y * 64);
			else if (map[y][x] == 'E')
				put_dock(&data, x * 64, y * 64);
			x++;
		}
		y++;
	}
}
