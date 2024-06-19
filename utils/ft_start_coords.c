/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_coords.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngordobi <ngordobi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 13:14:26 by ngordobi          #+#    #+#             */
/*   Updated: 2024/06/19 13:15:41 by ngordobi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	start_coords(char **map, char axis)
{
	int	y;
	int	x;

	y = 0;
	while (map[y] != NULL)
	{
		x = 0;
		while (map[y][x] != '\0')
		{
			if (map[y][x] == 'P')
			{
				if (axis == 'y')
					return (y);
				else if (axis == 'x')
					return (x);
				else
					return (-1);
			}
			x++;
		}
		y++;
	}
	return (-1);
}