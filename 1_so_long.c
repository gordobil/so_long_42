/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_so_long.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngordobi <ngordobi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 13:50:00 by ngordobi          #+#    #+#             */
/*   Updated: 2024/06/04 14:12:44 by ngordobi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	window(char **map, int w, int h)
{
	void	*mlx;

	mlx = mlx_init();
	mlx_new_window(mlx, w * 16, h * 16, "so_long");
	mlx_loop(mlx);
	ft_print_map(map);
}

void	so_long(char *file)
{
	char	**map;
	int		map_width;
	int		map_height;

	map_width = meassure_map(file, 'w');
	map_height = meassure_map(file, 'h');
	if (map_width <= 0 || map_height <= 0)
		return ;
	map = load_map(file, map_width, map_height);
	if (check_map(map) != 0)
		return ;
	map_height = count(map, 'h');
	window(load_map(file, map_width, map_height), map_width, map_height);
}

int	main(int argc, char **argv)
{
	if (argc != 2 || check_file(argv[1]) != 0)
	{
		ft_putstr("Error\nInvalid map");
		return (0);
	}
	so_long(argv[1]);
	return (0);
}