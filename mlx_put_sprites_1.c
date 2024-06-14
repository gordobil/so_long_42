/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_put_sprites_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngordobi <ngordobi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 14:50:55 by ngordobi          #+#    #+#             */
/*   Updated: 2024/06/14 12:18:28 by ngordobi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    put_ship_u(t_mlx *data, int x, int y)
{
    data->addr = mlx_get_data_addr(data->ship_u, &data->bits_per_pixel,
	 								&data->line_length, &data->endian);
    mlx_put_image_to_window(data->mlx, data->mlx_win, data->ship_u, x, y);
}

void    put_ship_d(t_mlx *data, int x, int y)
{
    data->addr = mlx_get_data_addr(data->ship_d, &data->bits_per_pixel,
	 								&data->line_length, &data->endian);
    mlx_put_image_to_window(data->mlx, data->mlx_win, data->ship_d, x, y);
}

void    put_ship_l(t_mlx *data, int x, int y)
{
    data->addr = mlx_get_data_addr(data->ship_l, &data->bits_per_pixel,
	 								&data->line_length, &data->endian);
    mlx_put_image_to_window(data->mlx, data->mlx_win, data->ship_l, x, y);
}

void    put_ship_r(t_mlx *data, int x, int y)
{
    data->addr = mlx_get_data_addr(data->ship_r, &data->bits_per_pixel,
	 								&data->line_length, &data->endian);
    mlx_put_image_to_window(data->mlx, data->mlx_win, data->ship_r, x, y);
}

void    put_water(t_mlx *data, int x, int y)
{
    data->addr = mlx_get_data_addr(data->water, &data->bits_per_pixel,
	 								&data->line_length, &data->endian);
    mlx_put_image_to_window(data->mlx, data->mlx_win, data->water, x, y);
}