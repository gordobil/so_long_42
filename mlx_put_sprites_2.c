/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_put_sprites_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngordobi <ngordobi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 14:50:55 by ngordobi          #+#    #+#             */
/*   Updated: 2024/06/11 15:51:36 by ngordobi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    put_cliff(t_mlx *data, int x, int y)
{
    data->addr = mlx_get_data_addr(data->cliff, &data->bits_per_pixel,
	 								&data->line_length, &data->endian);
    mlx_put_image_to_window(data->mlx, data->mlx_win, data->cliff, x, y);
}

void    put_buoy(t_mlx *data, int x, int y)
{
    data->addr = mlx_get_data_addr(data->buoy, &data->bits_per_pixel,
	 								&data->line_length, &data->endian);
    mlx_put_image_to_window(data->mlx, data->mlx_win, data->buoy, x, y);
}

void    put_dock(t_mlx *data, int x, int y)
{
    data->addr = mlx_get_data_addr(data->dock, &data->bits_per_pixel,
	 								&data->line_length, &data->endian);
    mlx_put_image_to_window(data->mlx, data->mlx_win, data->dock, x, y);
}

void    put_docked(t_mlx *data, int x, int y)
{
    data->addr = mlx_get_data_addr(data->docked, &data->bits_per_pixel,
	 								&data->line_length, &data->endian);
    mlx_put_image_to_window(data->mlx, data->mlx_win, data->docked, x, y);
}