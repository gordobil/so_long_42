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
	char	**map;
	int		map_width;
	int		map_height;

	map_width = map_meassure(file, 'w');
	if (map_width <= 0)
		return ;
	map_height = map_meassure(file, 'h');
	if (map_height <= 0)
		return ;
	map = map_load(file, map_width, map_height);
	ft_putstr("START:");
	ft_print_map(map);
	ft_putstr("");
	map_height = count(map, 'h');
	if (map_check(map, map_width) != 0)
		return ;
	ft_putstr("");
	ft_putstr("");
	ft_putstr("END:");
	ft_print_map(map);
}

int	main(int argc, char **argv)
{
	if (argc != 2 || check_file(argv[1]) != 0)
	{
		ft_putstr("Error\nInvalid map.");
		return (0);
	}
	so_long(argv[1]);
	return (0);
}
