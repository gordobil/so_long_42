/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_put_sprites.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngordobi <ngordobi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 14:50:55 by ngordobi          #+#    #+#             */
/*   Updated: 2024/06/18 14:50:59 by ngordobi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_water(t_mlx *data, int x, int y)
{
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->water, x, y);
}

void	put_cliff(t_mlx *data, int x, int y)
{
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->cliff, x, y);
}

void	put_buoy(t_mlx *data, int x, int y)
{
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->buoy, x, y);
}

void	put_dock(t_mlx *data, int x, int y)
{
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->dock, x, y);
}
