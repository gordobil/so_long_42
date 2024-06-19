/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngordobi <ngordobi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 13:57:01 by ngordobi          #+#    #+#             */
/*   Updated: 2024/06/19 11:05:06 by ngordobi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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
	ft_printf("\n");
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
		ft_printf("%s\n", map[y]);
		y++;
	}
	y = 0;
	while (y < x && y >= 0)
	{
		write (1, "~", 1);
		y++;
	}
	ft_printf("\n");
}

void	ft_print_map_ascii(char **map)
{
	int	x;
	int	y;

	ft_printf("MAP IN ASCII:\n");
	y = 0;
	while (map[y] != NULL)
	{
		x = 0;
		ft_printf("|");
		while (map[y][x] != '\0')
		{
			ft_printf ("%d ", map[y][x]);
			x++;
		}
		ft_printf ("/%d|\n", map[y][x]);
		y++;
	}
	ft_printf("\n");
}
