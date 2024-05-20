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

t_map	so_long(char *file)
{
	t_map	info;

	info.width = map_meassure(file, 1);
	info.height = map_meassure(file, 2);
	if (info.width <= 0 || info.height <= 0)
		return (info);
	info.map = map_load(info.width, info.height, file);
	info.errors = map_check(info.map);
	return (info);
}

int	main(int argc, char **argv)
{
	t_map	map;

	if (argc != 2 || check_file(argv[1]) == 1)
	{
		ft_putstr("Error\nInvalid map.");
		return (0);
	}
	map = so_long(argv[1]);
	print_map(map.map);
	return (0);
}
