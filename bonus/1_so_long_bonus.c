/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_so_long_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngordobi <ngordobi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 13:50:00 by ngordobi          #+#    #+#             */
/*   Updated: 2024/06/19 14:48:33 by ngordobi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	window_bonus(char *file, int w, int h)
{
	t_mlx	data;

	data.map = load_map_bonus(file, w, h);
	data.y = start_coords(data.map, 'y');
	data.x = start_coords(data.map, 'x');
	data.coins = count(data.map, 'C');
	data.moves = 0;
	data.animation = 0;
	data.mlx = mlx_init();
	data.mlx_win = mlx_new_window(data.mlx, w * SQ, h * SQ, "so_long_bonus");
	put_map_bonus(&data);
	pressed_key_bonus(&data, W);
	mlx_hook(&data.mlx_win, 2, 1L << 0, pressed_key_bonus, &data);
	mlx_hook(data.mlx_win, 17, 1, close_window, &data);
	mlx_loop(data.mlx);
}

void	so_long_bonus(char *file)
{
	char	**map;
	int		map_width;
	int		map_height;

	map_width = meassure_map_bonus(file, 'w');
	map_height = meassure_map_bonus(file, 'h');
	if (map_width <= 0 || map_height <= 0)
		return ;
	map = load_map_bonus(file, map_width, map_height);
	if (check_map_bonus(map) != 0)
	{
		ft_free_map(map);
		return ;
	}
	map_height = count(map, 'h');
	window_bonus(file, map_width, map_height);
}

int	main(int argc, char **argv)
{
	if (argc != 2 || check_file_bonus(argv[1]) != 0)
	{
		ft_printf("Error\nInvalid map\n");
		return (0);
	}
	so_long_bonus(argv[1]);
	return (0);
}
