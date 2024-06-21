/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_so_long.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngordobi <ngordobi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 13:50:00 by ngordobi          #+#    #+#             */
/*   Updated: 2024/06/21 14:14:02 by ngordobi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	window(char *file, int w, int h)
{
	t_mlx	data;

	data.map = load_map(file, w, h);
	data.y = start_coords(data.map, 'y');
	data.x = start_coords(data.map, 'x');
	data.coins = count(data.map, 'C');
	data.moves = 0;
	data.mlx = mlx_init();
	data.mlx_win = mlx_new_window(data.mlx, w * SQ, h * SQ, "so_long");
	put_map(&data);
	mlx_key_hook(&data.mlx_win, pressed_key, &data);
	mlx_hook(data.mlx_win, 17, 1, close_window, &data);
	mlx_loop(data.mlx);
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
	{
		ft_free_map(map);
		return ;
	}
	map_height = count(map, 'h');
	window(file, map_width, map_height);
}

int	main(int argc, char **argv)
{
	if (argc != 2 || check_file(argv[1]) != 0)
	{
		ft_printf("Error\nInvalid map\n");
		return (0);
	}
	so_long(argv[1]);
	return (0);
}
