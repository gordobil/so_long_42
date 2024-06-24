/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_close_window.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngordobi <ngordobi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 14:27:51 by ngordobi          #+#    #+#             */
/*   Updated: 2024/06/24 14:44:37 by ngordobi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	close_window(t_mlx *data, int close)
{
	if (close == 0 || close == 320)
		ft_printf("You closed the game :(\n");
	else if (close == 1 || close == -1)
	{
		put_map(data);
		put_counter(data);
		if (close == 1)
			ft_printf ("You won !!\n");
		else
			ft_printf("You lost :(\n");
	}
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	ft_free_map(data->map);
	exit(EXIT_SUCCESS);
	return (0);
}

int	no_event(void *data)
{
    return (0);
}
