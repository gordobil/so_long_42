/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngordobi <ngordobi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 13:50:10 by ngordobi          #+#    #+#             */
/*   Updated: 2024/06/11 15:52:22 by ngordobi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include "./mlx/mlx.h"
# define SQ 128
# define SHIP_U "./sprites/ship_u.xpm"
# define SHIP_D "./sprites/ship_d.xpm"
# define SHIP_L "./sprites/ship_l.xpm"
# define SHIP_R "./sprites/ship_r.xpm"
# define WATER "./sprites/water.xpm"
# define CLIFF "./sprites/wall.xpm"
# define BUOY "./sprites/buoy.xpm"
# define DOCK "./sprites/dock.xpm"
# define DOCKED "./sprites/docked.xpm"

typedef struct  s_mlx
{
	void		*mlx;
	void		*mlx_win;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	void		*ship_u;
	void		*ship_d;
	void		*ship_l;
	void		*ship_r;
	void		*water;
	void		*cliff;
	void		*buoy;
	void		*dock;
	void		*docked;
}               t_mlx;

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

//MLX
void		window_init(t_mlx *data, int w, int h);
void    	put_ship_u(t_mlx *data, int x, int y);
void    	put_ship_d(t_mlx *data, int x, int y);
void    	put_ship_l(t_mlx *data, int x, int y);
void    	put_ship_r(t_mlx *data, int x, int y);
void    	put_water(t_mlx *data, int x, int y);
void    	put_cliff(t_mlx *data, int x, int y);
void    	put_buoy(t_mlx *data, int x, int y);
void		put_dock(t_mlx *data, int x, int y);
void    	put_docked(t_mlx *data, int x, int y);

#endif
