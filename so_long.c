/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngordobi <ngordobi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 13:50:00 by ngordobi          #+#    #+#             */
/*   Updated: 2024/05/20 14:08:28 by ngordobi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	so_long(char *file, t_map *g_map)
{
	map_meassure(file, 1, &g_map);
	map_meassure(file, 2, &g_map);
	if (g_map->width <= 0 || g_map->height <= 0)
		return ;
	g_map->map = map_load(file, &g_map);
	g_map->map_dup = map_load(file, &g_map);
	g_map->errors = map_check(0, &g_map);
}

int	main(int argc, char **argv)
{
	t_map	g_map;

	if (argc != 2 || check_file(argv[1]) != 0)
	{
		ft_putstr("Error\nInvalid map.");
		return (0);
	}
	so_long(argv[1], &g_map);
	ft_print_map(g_map.map);
	return (0);
}
