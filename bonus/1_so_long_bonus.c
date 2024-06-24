/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_so_long_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngordobi <ngordobi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 13:50:00 by ngordobi          #+#    #+#             */
/*   Updated: 2024/06/24 14:53:59 by ngordobi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	window_bonus(char *file, int w, int h)
{
	t_mlx	game;

	game.map = load_map_bonus(file, w, h);
	game.y = start_coords(game.map, 'y');
	game.x = start_coords(game.map, 'x');
	game.coins = count(game.map, 'C');
	game.moves = 0;
	game.mlx = mlx_init();
    game.win = mlx_new_window(game.mlx, w * SQ, h * SQ, "so_long_bonus");
	put_map_bonus(&game);
	put_counter(&game);
	ft_printf("Collect all the buoys (%d) and bring them to the island.\n",
				game.coins);
	mlx_loop_hook(game.mlx, &no_event, &game);
	mlx_hook(game.win, 17, 1, close_window, &game);
    mlx_key_hook(game.win, &handle_input_bonus, &game);
    mlx_loop(game.mlx);
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
