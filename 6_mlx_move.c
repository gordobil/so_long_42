/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   6_mlx_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngordobi <ngordobi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 14:17:42 by ngordobi          #+#    #+#             */
/*   Updated: 2024/06/17 14:42:16 by ngordobi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_to_e(t_mlx *data, int move_y, int move_x)
{
	if (move_x < 0)
		data->map[data->y + move_y][data->x + move_x] = 'Y';
	else
		data->map[data->y + move_y][data->x + move_x] = 'X';
	data->map[data->y][data->x] = '0';
	printf ("You moved %d time(s).\n", ++data->moves);
	if (data->coins == 0)
	{
		close_window (data);
		printf ("You won !!\n");
		return ;
	}
	data->y += move_y;
	data->x += move_x;
	put_map (data);
}

void	move_to_c_0(t_mlx *data, int move_y, int move_x)
{
	if (data->map[data->y + move_y][data->x + move_x] == 'C')
		printf ("There are %d buoys left.\n", --data->coins);
	if (data->map[data->y][data->x] == 'X' ||
		data->map[data->y][data->x] == 'Y')
		data->map[data->y][data->x] = 'E';
	else
		data->map[data->y][data->x] = '0';
	if (move_x > 0)
		data->map[data->y + move_y][data->x + move_x] = 'R';
	else if (move_x < 0)
		data->map[data->y + move_y][data->x + move_x] = 'L';
	else if (move_y < 0)
		data->map[data->y + move_y][data->x + move_x] = 'U';
	else if (move_y > 0)
		data->map[data->y + move_y][data->x + move_x] = 'D';
	data->y += move_y;
	data->x += move_x;
	put_map(data);
	printf("You moved %d time(s).\n", ++data->moves);
}

void	move_player(t_mlx *data, int move_y, int move_x)
{
	if (data->map[data->y + move_y][data->x + move_x] == '0' ||
		data->map[data->y + move_y][data->x + move_x] == 'C')
		move_to_c_0(data, move_y, move_x);
	else if (data->map[data->y + move_y][data->x + move_x] == 'E')
		move_to_e(data, move_y, move_x);
	else
	{
		if (move_x > 0)
			data->map[data->y][data->x] = 'R';
		else if (move_x < 0)
			data->map[data->y][data->x] = 'L';
		else if (move_y < 0)
			data->map[data->y][data->x] = 'U';
		else if (move_y > 0)
			data->map[data->y][data->x] = 'D';
	}
	put_map(data);
}

int	pressed_key(t_mlx *data, int key)
{
	if (key == Q || key == ESC)
		close_window(data);
	else if (key == A || key == L_ARROW)
		move_player(data, 0, -1);
	else if (key == D || key == R_ARROW)
		move_player(data, 0, 1);
	else if (key == W || key == U_ARROW)
		move_player(data, -1, 0);
	else if (key == S || key == D_ARROW)
		move_player(data, 1, 0);
	return (key);
}
