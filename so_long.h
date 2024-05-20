/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngordobi <ngordobi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 13:50:10 by ngordobi          #+#    #+#             */
/*   Updated: 2024/05/20 14:58:18 by ngordobi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

typedef struct s_map
{
	char			**map;
	unsigned int	width;
	unsigned int	height;
	int				errors;
}					t_map;

//START
int					check_file(char *file);
int					map_meassure(char *file, int axis);
char				**map_load(int width, int height, char *file);
int					map_check(char **map);
int					characters_ret(int chars[4]);
int					*chars_to_zero(int size);

//UTILS
void				ft_putstr(char	*str);
void				print_map(char **map);

#endif
