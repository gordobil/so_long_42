/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngordobi <ngordobi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 13:57:01 by ngordobi          #+#    #+#             */
/*   Updated: 2024/05/20 13:57:17 by ngordobi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_title(int x, int m)
{
	while (x > m)
	{
		write (1, "~", 1);
		x--;
	}
	write (1, "MAP", 3);
	while (x > 0)
	{
		write (1, "~", 1);
		x--;
	}
	ft_putstr("");
}
void	ft_print_map(char **map)
{
	int	x;
	int	y;

	x = 0;
	while (map[0][x] != '\0')
		x++;
	print_title(x - 3, (x - 3) / 2);
	y = 0;
	while (map[y] != NULL)
	{
		ft_putstr(map[y]);
		y++;
	}
	y = 0;
	while (y < x && y >= 0)
	{
		write (1, "~", 1);
		y++;
	}
	ft_putstr("");
}