/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_so_long.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngordobi <ngordobi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 13:50:00 by ngordobi          #+#    #+#             */
/*   Updated: 2024/06/10 14:24:36 by ngordobi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	my_mlx_pixel_put(t_mlx *data, int x, int y, int color)
{
	char	*dst;
	
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	window(char **map, int w, int h)
{
	void	*mlx;
	t_mlx	mlx_data;

	mlx = mlx_init();
	mlx_data.mlx_win = mlx_new_window(mlx, w * 400, h * 350, "so_long");
	mlx_data.img = mlx_new_image(mlx, 100, 60);
	mlx_data.addr = mlx_get_data_addr(mlx_data.img, &mlx_data.bits_per_pixel,
									&mlx_data.line_length, &mlx_data.endian);
	my_mlx_pixel_put(&mlx_data, 5, 5, 0x00FF0000);
	mlx_put_image_to_window(mlx, mlx_data.mlx_win, mlx_data.img, 5, 6);
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
