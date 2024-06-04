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
int			meassure_map(char *file, char axis);
char		**load_map(char *file, int w, int h);

//CHECK
int			check_map(char **map);
int			characters_ret(int chars[4]);
int			start_coords(char **map, char axis);
int			find_exit(int y, int x, char **map);

//UTILS
void		ft_putstr(char	*str);
void		ft_print_map(char **map);
void		ft_print_map_ascii(char **map);
int			count(char **map, char axis);

#endif
