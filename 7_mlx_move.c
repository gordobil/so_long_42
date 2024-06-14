/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   7_mlx_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngordobi <ngordobi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 13:53:10 by ngordobi          #+#    #+#             */
/*   Updated: 2024/06/14 14:31:35 by ngordobi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    move_player(t_mlx *data, int move_y, int move_x)
{
    if (data->map[data->y + move_y][data->x + move_x] == '0' ||
        data->map[data->y + move_y][data->x + move_x] == 'C')
    {
        if (data->map[data->y + move_y][data->x + move_x] == 'C')
            data->coins--;
        data->map[data->y + move_y][data->x + move_x] = 'P';
        data->map[data->y][data->x] = '0';
        if (move_x > 0)
            put_ship_r(data, (data->x + move_x) * 64, (data->y + move_y) * 64);
        else if (move_x < 0)
            put_ship_l(data, (data->x + move_x) * 64, (data->y + move_y) * 64);
        else if (move_y < 0)
            put_ship_u(data, (data->x + move_x) * 64, (data->y + move_y) * 64);
        else if (move_y > 0)
            put_ship_d(data, (data->x + move_x) * 64, (data->y + move_y) * 64);
        put_water(data, data->x * 64, data->y *64);
        data->y += move_y;
        data->x += move_x;
        printf("MOVE %d\n", data->moves++);
    }
    else if (data->map[data->y + move_y][data->x + move_x] == 'E')
    {
        data->map[data->y + move_y][data->x + move_x] = 'X';
        data->map[data->y][data->x] = '0';
        put_docked(data, (data->x + move_x) * 64, (data->y + move_y) * 64);
        put_water(data, data->x * 64, data->y *64);
        printf("MOVE %d\n", data->moves++);
        if (data->coins == 0)
        {
            close_window(data);
            printf("YOU WON\n");
            return ;
        }
        data->y += move_y;
        data->x += move_x;
    }
    else if (data->map[data->y + move_y][data->x + move_x] == 'X')
    else
}
