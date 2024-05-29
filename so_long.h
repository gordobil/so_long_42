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

//START
int			check_file(char *file);
int			map_meassure(char *file, int axis);
char		**map_load(char *file, int w, int h);
int			map_check(char **map, int map_w, int map_h);
int			characters_ret(int chars[4]);
int			start_point(char **map, int axis);
int			find_exit(int y, int x, char **map, int map_w, int map_h);

//UTILS
void		ft_putstr(char	*str);
void		ft_print_map(char **map);

#endif
