/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   6_mlx.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngordobi <ngordobi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 14:17:42 by ngordobi          #+#    #+#             */
/*   Updated: 2024/06/11 15:51:51 by ngordobi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_mlx    *load_sprites(t_mlx *data)
{
    int     spr_w;
    int     spr_h;

    data->ship_u = mlx_xpm_file_to_image(data->mlx, SHIP_U, &spr_w, &spr_h);
    data->ship_d = mlx_xpm_file_to_image(data->mlx, SHIP_D, &spr_w, &spr_h);
    data->ship_l = mlx_xpm_file_to_image(data->mlx, SHIP_L, &spr_w, &spr_h);
    data->ship_r = mlx_xpm_file_to_image(data->mlx, SHIP_R, &spr_w, &spr_h);
    data->water = mlx_xpm_file_to_image(data->mlx, WATER, &spr_w, &spr_h);
    data->cliff = mlx_xpm_file_to_image(data->mlx, CLIFF, &spr_w, &spr_h);
    data->buoy = mlx_xpm_file_to_image(data->mlx, BUOY, &spr_w, &spr_h);
    data->dock = mlx_xpm_file_to_image(data->mlx, DOCK, &spr_w, &spr_h);
    data->docked = mlx_xpm_file_to_image(data->mlx, DOCKED, &spr_w, &spr_h);
    return (data);
}

void    window_init(t_mlx *data, int w, int h)
{
    int     spr_w;
    int     spr_h;

    data->mlx = mlx_init();
    data->mlx_win = mlx_new_window(data->mlx, w * SQ, h * SQ, "so_long");
    data = load_sprites(data);
}
