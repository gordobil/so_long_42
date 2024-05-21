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

void	so_long(char *file)
{
	map_meassure(file, 1);
	map_meassure(file, 2);
	if (g_map.width <= 0 || g_map.height <= 0)
		return ;
	map_load(file);
	map_dup_load(file);
	g_map.errors = map_check();
}

int	main(int argc, char **argv)
{
	if (argc != 2 || check_file(argv[1]) == 1)
	{
		ft_putstr("Error\nInvalid map.");
		return (0);
	}
	so_long(argv[1]);
	print_map(g_map.map);
	return (0);
}
