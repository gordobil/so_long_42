/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_destroy_sprites.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngordobi <ngordobi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 13:34:44 by ngordobi          #+#    #+#             */
/*   Updated: 2024/06/21 13:38:51 by ngordobi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	destroy_sprites(t_mlx *data)
{
	mlx_destroy_image(data->mlx, data->ship_u);
	mlx_destroy_image(data->mlx, data->ship_u_2);
	mlx_destroy_image(data->mlx, data->ship_d);
	mlx_destroy_image(data->mlx, data->ship_d_2);
	mlx_destroy_image(data->mlx, data->ship_l);
	mlx_destroy_image(data->mlx, data->ship_l_2);
	mlx_destroy_image(data->mlx, data->ship_r);
	mlx_destroy_image(data->mlx, data->ship_r_2);
	mlx_destroy_image(data->mlx, data->water);
	mlx_destroy_image(data->mlx, data->cliff);
	mlx_destroy_image(data->mlx, data->buoy);
	mlx_destroy_image(data->mlx, data->dock);
	mlx_destroy_image(data->mlx, data->docked_r);
	mlx_destroy_image(data->mlx, data->docked_l);
	mlx_destroy_image(data->mlx, data->pirate);
	mlx_destroy_image(data->mlx, data->pirate_2);
}
