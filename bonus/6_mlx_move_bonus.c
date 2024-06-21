/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   6_mlx_move_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngordobi <ngordobi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 14:17:42 by ngordobi          #+#    #+#             */
/*   Updated: 2024/06/21 12:04:03 by ngordobi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	dont_move_bonus(t_mlx *data, int move_y, int move_x)
{
	if (data->map[data->y][data->x] == 'X' ||
		data->map[data->y][data->x] == 'Y')
	{
		if (move_x < 0 || move_y < 0)
			data->map[data->y][data->x] = 'X';
		else if (move_x > 0 || move_y > 0)
			data->map[data->y][data->x] = 'Y';
	}
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
}

void	move_to_e_b_bonus(t_mlx *data, int move_y, int move_x)
{
	if (data->map[data->y + move_y][data->x + move_x] == 'E')
	{
		if (move_x < 0 || move_y < 0)
			data->map[data->y + move_y][data->x + move_x] = 'Y';
		else if (move_x > 0 || move_y > 0)
			data->map[data->y + move_y][data->x + move_x] = 'X';
	}
	data->map[data->y][data->x] = '0';
	ft_printf("You moved %d time(s).\n", ++data->moves);
	if (data->coins == 0 && (data->map[data->y + move_y][data->x + move_x]
		== 'X' || data->map[data->y + move_y][data->x + move_x] == 'Y'))
	{
		close_window(data);
		ft_printf("You won !!\n");
		return ;
	}
	data->y += move_y;
	data->x += move_x;
	put_map_bonus(data);
	if (data->map[data->y + move_y][data->x + move_x] == 'B')
	{
		ft_printf("You lost :(\n");
		close_window(data);
	}
}

void	move_to_c_0_bonus(t_mlx *data, int move_y, int move_x)
{
	if (data->map[data->y + move_y][data->x + move_x] == 'C')
		ft_printf("There are %d buoys left.\n", --data->coins);
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
	put_map_bonus(data);
	ft_printf("You moved %d time(s).\n", ++data->moves);
}

void	move_player_bonus(t_mlx *data, int move_y, int move_x)
{
	data->animation++;
	if (data->map[data->y + move_y][data->x + move_x] == '0' ||
		data->map[data->y + move_y][data->x + move_x] == 'C')
		move_to_c_0_bonus(data, move_y, move_x);
	else if (data->map[data->y + move_y][data->x + move_x] == 'E' ||
			data->map[data->y + move_y][data->x + move_x] == 'B')
		move_to_e_b_bonus(data, move_y, move_x);
	else
		dont_move_bonus(data, move_y, move_x);
	put_map_bonus(data);
}

int	pressed_key_bonus(t_mlx *data, int key)
{
	if (key == Q || key == ESC)
		close_window(data);
	else if (key == A || key == L_ARROW)
		move_player_bonus(data, 0, -1);
	else if (key == D || key == R_ARROW)
		move_player_bonus(data, 0, 1);
	else if (key == W || key == U_ARROW)
		move_player_bonus(data, -1, 0);
	else if (key == S || key == D_ARROW)
		move_player_bonus(data, 1, 0);
	return (key);
}
