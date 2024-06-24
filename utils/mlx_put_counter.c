/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_put_counter.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngordobi <ngordobi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 12:08:15 by ngordobi          #+#    #+#             */
/*   Updated: 2024/06/24 12:43:40 by ngordobi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	put_counter(t_mlx *data)
{
	int	y;
	int	x;
	int	col;

	col = 0x00CAE4EB;
	y = 5;
	while (y < 20)
	{
		x = 5;
		while (x < 36)
		{
			mlx_pixel_put(data->mlx, data->win, x, y, 0x00005B99);
			x++;
		}
		y++;
	}
	if (data->moves < 10)
		mlx_string_put(data->mlx, data->win, 18, 17, col, ft_itoa(data->moves));
	else if (data->moves >= 10 && data->moves < 100)
		mlx_string_put(data->mlx, data->win, 15, 17, col, ft_itoa(data->moves));
	else if (data->moves >= 100 && data->moves < 1000)
		mlx_string_put(data->mlx, data->win, 12, 17, col, ft_itoa(data->moves));
	else
		mlx_string_put(data->mlx, data->win, 9, 17, col, ft_itoa(data->moves));
}
