/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_put_messages.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngordobi <ngordobi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 13:52:10 by ngordobi          #+#    #+#             */
/*   Updated: 2024/06/25 13:52:10 by ngordobi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	put_background(t_mlx *data, int x_start, int x_end)
{
	int	y;
	int	x;

	y = 5;
	while (y <= 20)
	{
		x = x_start;
		while (x <= x_end)
		{
			mlx_pixel_put(data->mlx, data->win, x, y, 0x00005B99);
			x++;
		}
		y++;
	}
}

void	put_counter(t_mlx *data)
{
	int	col;

	col = 0x00CAE4EB;
	put_background(data, 5, 36);
	if (data->moves < 10)
		mlx_string_put(data->mlx, data->win, 18, 17, col, ft_itoa(data->moves));
	else if (data->moves >= 10 && data->moves < 100)
		mlx_string_put(data->mlx, data->win, 15, 17, col, ft_itoa(data->moves));
	else if (data->moves >= 100 && data->moves < 1000)
		mlx_string_put(data->mlx, data->win, 12, 17, col, ft_itoa(data->moves));
	else
		mlx_string_put(data->mlx, data->win, 9, 17, col, ft_itoa(data->moves));
}

void	put_messages(t_mlx *data, int mark)
{
	int	col;

	put_counter(data);
	col = 0x00CAE4EB;
	if (mark == 1)
	{
		ft_printf("There are/is %d buoy(s) left.\n", --data->coins);
		put_background(data, 42, 140);
		mlx_string_put(data->mlx, data->win, 50, 17, col, "Buoys left: ");
		mlx_string_put(data->mlx, data->win, 121, 17, col,
			ft_itoa(data->coins));
	}
	else if (mark == 2)
	{
		ft_printf("Collect all the buoys (%d) and bring them to the island.",
			data->coins);
		put_background(data, 42, 360);
		mlx_string_put(data->mlx, data->win, 50, 17, col,
			"Collect all the buoys and bring them to the island.");
	}
}
