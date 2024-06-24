/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_borders.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngordobi <ngordobi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 13:26:36 by ngordobi          #+#    #+#             */
/*   Updated: 2024/06/19 13:26:53 by ngordobi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	borders_aux(int y, int x, int axis, char **map)
{
	if (axis == 1)
	{
		while (map[y][x] != '\0')
		{
			if (map[y][x] != '1')
				break ;
			x++;
		}
		if (map[y][x] != '\0')
			return (-1);
	}
	else
	{
		if (map[y][x] != '1')
			return (-1);
		while (map[y][x + 1] != '\0')
			x++;
		if (map[y][x] != '1')
			return (-1);
	}
	return (0);
}

int	borders(int y, int x, char **map)
{
	while (map[y] != NULL)
	{
		x = 0;
		if (y == 0 || (map[y + 1] == NULL))
		{
			if (borders_aux(y, x, 1, map) != 0)
				break ;
		}
		else
		{
			if (borders_aux(y, x, 2, map) != 0)
				break ;
		}
		y++;
	}
	if (map[y] != NULL)
	{
		ft_printf("Error\nError in map borders\n");
		return (-1);
	}
	return (0);
}
