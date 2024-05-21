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
	char			**map_dup;
	unsigned int	width;
	unsigned int	height;
	int				errors;
	unsigned int	start_p_y;
	unsigned int	start_p_x;
}					t_map;

t_map				g_map;

//START
int					check_file(char *file);
int					map_meassure(char *file, int axis);
void				map_load(char *file);
void				map_dup_load(char *file);
int					map_check();
int					characters_ret(int chars[4]);
int					*chars_to_zero(int size);

//UTILS
void				ft_putstr(char	*str);
void				print_map(char **map);

#endif
