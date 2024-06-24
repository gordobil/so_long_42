/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_put_map_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngordobi <ngordobi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 13:24:45 by ngordobi          #+#    #+#             */
/*   Updated: 2024/06/24 12:26:03 by ngordobi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	put_pirates_dock(t_mlx *data, int y, int x)
{
	if (data->map[y][x] == 'D' && (data->animation % 2 != 0))
		mlx_put_image_to_window(data->mlx, data->win, data->ship_d,
			x * 64, y * 64);
	else if (data->map[y][x] == 'D' && (data->animation % 2 == 0))
		mlx_put_image_to_window(data->mlx, data->win, data->ship_d_2,
			x * 64, y * 64);
	else if (data->map[y][x] == 'B' && (data->animation % 2 != 0))
		mlx_put_image_to_window(data->mlx, data->win, data->pirate,
			x * 64, y * 64);
	else if (data->map[y][x] == 'B' && (data->animation % 2 == 0))
		mlx_put_image_to_window(data->mlx, data->win, data->pirate_2,
			x * 64, y * 64);
	else if (data->map[y][x] == 'X')
		mlx_put_image_to_window(data->mlx, data->win, data->docked_r,
			x * 64, y * 64);
	else if (data->map[y][x] == 'Y')
		mlx_put_image_to_window(data->mlx, data->win, data->docked_l,
			x * 64, y * 64);
}

void	put_ships_bonus(t_mlx *data, int y, int x)
{
	if (data->map[y][x] == 'P')
		mlx_put_image_to_window(data->mlx, data->win, data->ship_r,
			x * 64, y * 64);
	else if (data->map[y][x] == 'R' && data->animation % 2 != 0)
		mlx_put_image_to_window(data->mlx, data->win, data->ship_r,
			x * 64, y * 64);
	else if ((data->map[y][x] == 'P' || data->map[y][x] == 'R') &&
		(data->animation % 2 == 0))
		mlx_put_image_to_window(data->mlx, data->win, data->ship_r_2,
			x * 64, y * 64);
	else if (data->map[y][x] == 'L' && (data->animation % 2 != 0))
		mlx_put_image_to_window(data->mlx, data->win, data->ship_l,
			x * 64, y * 64);
	else if (data->map[y][x] == 'L' && (data->animation % 2 == 0))
		mlx_put_image_to_window(data->mlx, data->win, data->ship_l_2,
			x * 64, y * 64);
	else if (data->map[y][x] == 'U' && (data->animation % 2 != 0))
		mlx_put_image_to_window(data->mlx, data->win, data->ship_u,
			x * 64, y * 64);
	else if (data->map[y][x] == 'U' && (data->animation % 2 == 0))
		mlx_put_image_to_window(data->mlx, data->win, data->ship_u_2,
			x * 64, y * 64);
	else
		put_pirates_dock(data, y, x);
}

void	put_map_bonus(t_mlx *data)
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
				put_ships_bonus(data, y, x);
		}
	}
}
