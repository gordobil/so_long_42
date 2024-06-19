/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_put_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngordobi <ngordobi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 13:24:45 by ngordobi          #+#    #+#             */
/*   Updated: 2024/06/19 11:07:06 by ngordobi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	put_var(t_mlx *data, int y, int x)
{
	if (data->map[y][x] == 'X')
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->docked_r,
			x * 64, y * 64);
	else if (data->map[y][x] == 'Y')
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->docked_l,
			x * 64, y * 64);
	else if (data->map[y][x] == 'P' || data->map[y][x] == 'R')
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->ship_r,
			x * 64, y * 64);
	else if (data->map[y][x] == 'L')
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->ship_l,
			x * 64, y * 64);
	else if (data->map[y][x] == 'U')
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->ship_u,
			x * 64, y * 64);
	else if (data->map[y][x] == 'D')
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->ship_d,
			x * 64, y * 64);
}

void	put_map(t_mlx *data)
{
	int	y;
	int	x;

	load_sprites(data);
	y = 0;
	while (data->map[y] != NULL)
	{
		x = 0;
		put_cliff(data, 1, y * 64);
		while (data->map[y][x] != '\0')
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
				put_var(data, y, x);
			x++;
		}
		y++;
	}
}
