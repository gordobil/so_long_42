/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   6_mlx.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngordobi <ngordobi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 14:17:42 by ngordobi          #+#    #+#             */
/*   Updated: 2024/06/14 14:31:21 by ngordobi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    pressed_key(t_mlx *data, int key)
{
    if (key == Q || key == ESC)
        close_window(data);
    else if (key == A || key == L_ARROW)
        move_player(data, 0, -1);
    else if (key == D || key == R_ARROW)
        move_player(data, 0, 1);
    else if (key == W || key == U_ARROW)
        move_player(data, 1, 0);
    else if (key == S || key == D_ARROW)
        move_player(data, 1, 0);
}

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

	data->y = start_coords(data->map, 'y');
	data->x = start_coords(data->map, 'x');
    data->coins = count(data->map, 'C');
    data->moves = 0;
    data->mlx = mlx_init();
    data->mlx_win = mlx_new_window(data->mlx, w * SQ, h * SQ, "so_long");
	mlx_hook(data->mlx_win, 17, 1, close_window, data);
	mlx_hook(data->mlx_win, 2, 1, pressed_key, data);
    data = load_sprites(data);
}
