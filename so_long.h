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

/* typedef struct s_map
{
	char			**map;
	char			**map_dup;
	int				width;
	int				height;
	int				errors;
	int				start_p_y;
	int				start_p_x;
}					t_map;
t_map				g_map; */

char	**g_map;
char	**g_map_dup;
int		g_width;
int		g_height;
int		g_start_y;
int		g_start_x;

//START
int		check_file(char *file);
int		map_meassure(char *file, int axis);
char	**map_load(char *file);
int		map_check(int errors);
int		characters_ret(int chars[4]);
int		find_exit(int y, int x);

//UTILS
void	ft_putstr(char	*str);
void	ft_print_map(char **map);

#endif
