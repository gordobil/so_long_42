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

t_map	so_long(char *file)
{
	t_map	info;

	info.width = map_meassure(file, 1);
	info.height = map_meassure(file, 2);
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
	printf ("w: %d\nh: %d\n", map_info.width, map_info.height);
	return (0);
}
