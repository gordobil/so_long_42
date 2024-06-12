/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_put_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngordobi <ngordobi@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 13:24:45 by ngordobi          #+#    #+#             */
/*   Updated: 2024/06/12 13:24:45 by ngordobi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_first_column(char **map, t_mlx data, int y)
{
	if (map[y][0] == '0')
		put_water(&data, 1, (y + 1) * 64);
	else if (map[y][0] == '1')
		put_cliff(&data, 1, (y + 1) * 64);
	else if (map[y][0] == 'P')
		put_ship_r(&data, 1, (y + 1) * 64);
	else if (map[y][0] == 'C')
		put_buoy(&data, 1, (y + 1) * 64);
	else if (map[y][0] == 'E')
		put_dock(&data, 1, (y + 1) * 64);
	else
		return ;
}

void	put_first_row(char **map, t_mlx data)
{
	int	x;

	x = 0;
	while (map[0][x] != '\0')
	{
		if (map[0][x] == '0')
			put_water(&data, (x + 1) * 64, 1);
		else if (map[0][x] == '1')
			put_cliff(&data, (x + 1) * 64, 1);
		else if (map[0][x] == 'P')
			put_ship_r(&data, (x + 1) * 64, 1);
		else if (map[0][x] == 'C')
			put_buoy(&data, (x + 1) * 64, 1);
		else if (map[0][x] == 'E')
			put_dock(&data, (x + 1) * 64, 1);
		else
			return ;
		x++;
	}
}

void	put_map(char **map, t_mlx data)
{
	int	y;
	int	x;

	put_first_row(map, data);
	y = 0;
	while (map[y] != NULL)
	{
		x = 0;
		put_first_column(map, data, y);
		while (map[y][x] != '\0')
		{
			printf("x:%d ", x);
			if (map[y][x] == '0')
				put_water(&data, (x + 1) * 64, (y + 1) * 64);
			else if (map[y][x] == '1')
				put_cliff(&data, (x + 1) * 64, (y + 1) * 64);
			else if (map[y][x] == 'P')
				put_ship_r(&data, (x + 1) * 64, (y + 1) * 64);
			else if (map[y][x] == 'C')
				put_buoy(&data, (x + 1) * 64, (y + 1) * 64);
			else if (map[y][x] == 'E')
				put_dock(&data, (x + 1) * 64, (y + 1) * 64);
			else
				return ;
			x++;
		}
		y++;
		printf ("\ny:%d ", y);
	}
}