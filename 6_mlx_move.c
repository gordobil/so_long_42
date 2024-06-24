/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   6_mlx_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngordobi <ngordobi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 14:17:42 by ngordobi          #+#    #+#             */
/*   Updated: 2024/06/24 14:54:03 by ngordobi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	dont_move(t_mlx *data, int move_y, int move_x)
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

void	move_to_e(t_mlx *data, int move_y, int move_x)
{
	if (move_x < 0 || move_y < 0)
		data->map[data->y + move_y][data->x + move_x] = 'Y';
	else if (move_x > 0 || move_y > 0)
		data->map[data->y + move_y][data->x + move_x] = 'X';
	data->map[data->y][data->x] = '0';
	ft_printf ("You moved %d time(s).\n", ++data->moves);
	if (data->coins == 0)
	{
		close_window (data, 1);
		return ;
	}
	else
		ft_printf("Collect all the buoys (%d) and bring them to the island.\n",
				data->coins);
	data->y += move_y;
	data->x += move_x;
}

void	move_to_c_0(t_mlx *data, int move_y, int move_x)
{
	if (data->map[data->y + move_y][data->x + move_x] == 'C')
		ft_printf ("There are/is %d buoy(s) left.\n", --data->coins);
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
}

void	move_player(t_mlx *data, int move_y, int move_x)
{
	if (data->map[data->y + move_y][data->x + move_x] == '0' ||
		data->map[data->y + move_y][data->x + move_x] == 'C')
		move_to_c_0(data, move_y, move_x);
	else if (data->map[data->y + move_y][data->x + move_x] == 'E')
		move_to_e(data, move_y, move_x);
	else
		dont_move(data, move_y, move_x);
}

int	handle_input(int keysym, t_mlx *data)
{
	if (keysym == Q || keysym == ESC)
		close_window(data, 0);
	else if (keysym == A || keysym == L_ARROW)
		move_player(data, 0, -1);
	else if (keysym == D || keysym == R_ARROW)
		move_player(data, 0, 1);
	else if (keysym == W || keysym == U_ARROW)
		move_player(data, -1, 0);
	else if (keysym == S || keysym == D_ARROW)
		move_player(data, 1, 0);
	put_map(data);
	return (0);
}
