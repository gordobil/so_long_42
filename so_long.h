/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngordobi <ngordobi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 13:50:10 by ngordobi          #+#    #+#             */
/*   Updated: 2024/06/14 14:29:57 by ngordobi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include "./mlx/mlx.h"
# define SQ 64
# define Q 12
# define W 13
# define A 0
# define S 1
# define D 2
# define ESC 0x35
# define L_ARROW 123
# define R_ARROW 124
# define U_ARROW 126
# define D_ARROW 125
# define SHIP_L "./sprites/ship_l.xpm"
# define SHIP_R "./sprites/ship_r.xpm"
# define SHIP_U "./sprites/ship_u.xpm"
# define SHIP_D "./sprites/ship_d.xpm"
# define WATER "./sprites/water.xpm"
# define CLIFF "./sprites/cliff.xpm"
# define BUOY "./sprites/buoy.xpm"
# define DOCK "./sprites/E.xpm"
# define DOCKED "./sprites/E.xpm"

typedef struct  s_mlx
{
	char		**map;
	int			y;
	int			x;
	int			coins;
	int			moves;
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
void    	ft_free_map(char **data);
void		ft_print_map(char **map);
void		ft_print_map_ascii(char **map);
int			count(char **map, char axis);

//MLX
void		window_init(t_mlx *data, int w, int h);
void    	close_window(t_mlx *data);
void    	put_ship_u(t_mlx *data, int x, int y);
void    	put_ship_d(t_mlx *data, int x, int y);
void    	put_ship_l(t_mlx *data, int x, int y);
void    	put_ship_r(t_mlx *data, int x, int y);
void    	put_water(t_mlx *data, int x, int y);
void    	put_cliff(t_mlx *data, int x, int y);
void    	put_buoy(t_mlx *data, int x, int y);
void		put_dock(t_mlx *data, int x, int y);
void    	put_docked(t_mlx *data, int x, int y);
void		put_map(char **map, t_mlx data);
void    	move_player(t_mlx *data, int move_y, int move_x);

#endif
