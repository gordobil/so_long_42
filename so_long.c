/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngordobi <ngordobi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 13:50:00 by ngordobi          #+#    #+#             */
/*   Updated: 2024/05/14 13:23:21 by ngordobi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "so_long.h"

void	print_map(char **map)
{
	int	i;

	i = 0;
	while (map[i][0] != '\0')
	{
		ft_putstr(map[i]);
		i++;
	}
	ft_putstr("");
}
t_map	so_long(char *file)
{
	t_map	info;

	info.width = map_meassure(file, 1);
	info.height = map_meassure(file, 2);
	if (info.width <= 0 || info.height <= 0)
		return (info);
	info.map = reserve_matrix(info.width, info.height, file);
	return (info);
}

int	main(int argc, char **argv)
{
	t_map	map_info;

	if (argc != 2 || check_file(argv[1]) == 1)
	{
		ft_putstr("Choose a valid map.");
		return (0);
	}
	map_info = so_long(argv[1]);
	print_map(map_info.map);
	return (0);
}
