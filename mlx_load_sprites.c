/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_load_sprites.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngordobi <ngordobi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 11:45:27 by ngordobi          #+#    #+#             */
/*   Updated: 2024/06/18 14:50:42 by ngordobi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_mlx	*load_sprites(t_mlx *data)
{
	int	spr_w;
	int	spr_h;

	data->ship_u = mlx_xpm_file_to_image(data->mlx, SHIP_U, &spr_w, &spr_h);
	data->ship_d = mlx_xpm_file_to_image(data->mlx, SHIP_D, &spr_w, &spr_h);
	data->ship_l = mlx_xpm_file_to_image(data->mlx, SHIP_L, &spr_w, &spr_h);
	data->ship_r = mlx_xpm_file_to_image(data->mlx, SHIP_R, &spr_w, &spr_h);
	data->water = mlx_xpm_file_to_image(data->mlx, WATER, &spr_w, &spr_h);
	data->cliff = mlx_xpm_file_to_image(data->mlx, CLIFF, &spr_w, &spr_h);
	data->buoy = mlx_xpm_file_to_image(data->mlx, BUOY, &spr_w, &spr_h);
	data->dock = mlx_xpm_file_to_image(data->mlx, DOCK, &spr_w, &spr_h);
	data->docked_r = mlx_xpm_file_to_image(data->mlx, DOCKED_R, &spr_w, &spr_h);
	data->docked_l = mlx_xpm_file_to_image(data->mlx, DOCKED_L, &spr_w, &spr_h);
	return (data);
}
