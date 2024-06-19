/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_close_window.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngordobi <ngordobi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 14:27:51 by ngordobi          #+#    #+#             */
/*   Updated: 2024/06/19 11:07:01 by ngordobi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	close_window(t_mlx *data)
{
	mlx_destroy_window(data->mlx, data->mlx_win);
	mlx_destroy_image(data->mlx, data->ship_u);
	mlx_destroy_image(data->mlx, data->ship_d);
	mlx_destroy_image(data->mlx, data->ship_l);
	mlx_destroy_image(data->mlx, data->ship_r);
	mlx_destroy_image(data->mlx, data->water);
	mlx_destroy_image(data->mlx, data->buoy);
	mlx_destroy_image(data->mlx, data->dock);
	mlx_destroy_image(data->mlx, data->docked_r);
	mlx_destroy_image(data->mlx, data->docked_l);
	ft_free_map(data->map);
	exit(EXIT_SUCCESS);
	return (0);
}
