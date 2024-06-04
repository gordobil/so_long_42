/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngordobi <ngordobi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 13:43:22 by ngordobi          #+#    #+#             */
/*   Updated: 2024/06/04 12:39:29 by ngordobi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count(char **map, char axis)
{
	int	y;
	int	x;
	int	c;

	y = 0;
	c = 0;
	while (map[y] != NULL)
	{
		x = 0;
		while (map[y][x] != '\0')
		{
			if (map[y][x] == 'C')
				c++;
			x++;
		}
		y++;
	}
	if (axis == 'h')
		return (y);
	else if (axis == 'w')
		return (x);
	else if (axis == 'C')
		return (c);
	else
		return (0);
}