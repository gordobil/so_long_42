/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_put_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngordobi <ngordobi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 13:24:45 by ngordobi          #+#    #+#             */
/*   Updated: 2024/06/24 12:26:08 by ngordobi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	put_ships(t_mlx *data, int y, int x)
{
	if (data->map[y][x] == 'X')
		mlx_put_image_to_window(data->mlx, data->win, data->docked_r,
			x * 64, y * 64);
	else if (data->map[y][x] == 'Y')
		mlx_put_image_to_window(data->mlx, data->win, data->docked_l,
			x * 64, y * 64);
	else if (data->map[y][x] == 'P' || data->map[y][x] == 'R')
		mlx_put_image_to_window(data->mlx, data->win, data->ship_r,
			x * 64, y * 64);
	else if (data->map[y][x] == 'L')
		mlx_put_image_to_window(data->mlx, data->win, data->ship_l,
			x * 64, y * 64);
	else if (data->map[y][x] == 'U')
		mlx_put_image_to_window(data->mlx, data->win, data->ship_u,
			x * 64, y * 64);
	else if (data->map[y][x] == 'D')
		mlx_put_image_to_window(data->mlx, data->win, data->ship_d,
			x * 64, y * 64);
}

void	put_map(t_mlx *data)
{
	int	y;
	int	x;

	if (data->moves != 0)
		destroy_sprites(data);
	load_sprites(data);
	y = -1;
	while (data->map[++y] != NULL)
	{
		x = -1;
		put_cliff(data, 1, y * 64);
		while (data->map[y][++x] != '\0')
		{
			if (data->map[y][x] == '0')
				put_water(data, x * 64, y * 64);
			else if (data->map[y][x] == '1')
				put_cliff(data, x * 64, y * 64);
			else if (data->map[y][x] == 'C')
				put_buoy(data, x * 64, y * 64);
			else if (data->map[y][x] == 'E')
				put_dock(data, x * 64, y * 64);
			else
				put_ships(data, y, x);
		}
	}
}
