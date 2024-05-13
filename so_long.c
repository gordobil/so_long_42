/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngordobi <ngordobi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 13:50:00 by ngordobi          #+#    #+#             */
/*   Updated: 2024/05/13 14:32:51 by ngordobi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	scan_map(char *file)
{
    int		fd;
	int		size;
	int		rd_file;
	char	c;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr("Error opening file.");
		return (0);
	}
	size = 0;
	rd_file = 1;
	while (rd_file > 0)
	{
		rd_file = read(fd, &c, 1);
		size++;
	}
	size--;
	close (fd);
	return (size);
}

int	file_check(char *file)
{
	int	i;

	i = 0;
	while (file[i + 1] != '\0')
		i++;
	if (file[i - 3] != '.' || file[i - 2] != 'b'
		|| file[i - 1] != 'e' || file[i] != 'r')
		return (1);
}

int	main(int argc, char **argv)
{
	char	*map;

	if (argc != 2 || file_check(argv[1]) == 1)
	{
		ft_putstr("Choose a valid map.");
		return (0);
	}
	t_map -> map_size = scan_map(argv[1]);
	return (0);
}
