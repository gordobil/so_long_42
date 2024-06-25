/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   6_mlx_move_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngordobi <ngordobi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 14:17:42 by ngordobi          #+#    #+#             */
/*   Updated: 2024/06/24 14:45:10 by ngordobi         ###   ########.fr       */
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

int	move_to_e_b_bonus(t_mlx *data, int move_y, int move_x)
{
	if (data->map[data->y + move_y][data->x + move_x] == 'E')
	{
		if (move_x < 0 || move_y < 0)
			data->map[data->y + move_y][data->x + move_x] = 'X';
		else if (move_x > 0 || move_y > 0)
			data->map[data->y + move_y][data->x + move_x] = 'Y';
	}
	data->map[data->y][data->x] = '0';
	ft_printf("You moved %d time(s).\n", ++data->moves);
	if (data->coins == 0 && (data->map[data->y + move_y][data->x + move_x]
		== 'X' || data->map[data->y + move_y][data->x + move_x] == 'Y'))
	{
		close_window_bonus(data, 1);
		return (0);
	}
	else if (data->map[data->y + move_y][data->x + move_x] == 'B')
	{
		close_window_bonus(data, -1);
		return (0);
	}
	data->y += move_y;
	data->x += move_x;
	return (2);
}

int	move_to_c_0_bonus(t_mlx *data, int move_y, int move_x)
{
	int	ret;

	ret = 0;
	if (data->map[data->y + move_y][data->x + move_x] == 'C')
		ret = 1;
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
	ft_printf("You moved %d time(s).\n", ++data->moves);
	return (ret);
}

int	move_player_bonus(t_mlx *data, int move_y, int move_x)
{
	int	ret;

	ret = 0;
	data->animation++;
	if (data->map[data->y + move_y][data->x + move_x] == '0' ||
		data->map[data->y + move_y][data->x + move_x] == 'C')
		ret = move_to_c_0_bonus(data, move_y, move_x);
	else if (data->map[data->y + move_y][data->x + move_x] == 'E' ||
			data->map[data->y + move_y][data->x + move_x] == 'B')
		ret = move_to_e_b_bonus(data, move_y, move_x);
	else
		dont_move_bonus(data, move_y, move_x);
	return (ret);
}

int	handle_input_bonus(int keysym, t_mlx *data)
{
	int	ret;

	ret == 0;
	if (keysym == Q || keysym == ESC)
		ret = close_window_bonus(data, 0);
	else if (keysym == A || keysym == L_ARROW)
		ret = move_player_bonus(data, 0, -1);
	else if (keysym == D || keysym == R_ARROW)
		ret = move_player_bonus(data, 0, 1);
	else if (keysym == W || keysym == U_ARROW)
		ret = move_player_bonus(data, -1, 0);
	else if (keysym == S || keysym == D_ARROW)
		ret = move_player_bonus(data, 1, 0);
	put_map_bonus(data);
	put_messages(data, ret);
	return (0);
}
