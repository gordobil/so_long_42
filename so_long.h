/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngordobi <ngordobi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 13:50:10 by ngordobi          #+#    #+#             */
/*   Updated: 2024/06/21 14:10:56 by ngordobi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdarg.h>
# include "./mlx/mlx.h"
# define SQ 64
# define Q 81
# define W 87
# define A 65
# define S 83
# define D 68
# define ESC 27
# define L_ARROW 37
# define R_ARROW 39
# define U_ARROW 38
# define D_ARROW 40
# define SHIP_L "./sprites/ship_l.xpm"
# define SHIP_L_2 "./sprites/bonus/ship_l_2.xpm"
# define SHIP_R "./sprites/ship_r.xpm"
# define SHIP_R_2 "./sprites/bonus/ship_r_2.xpm"
# define SHIP_U "./sprites/ship_u.xpm"
# define SHIP_U_2 "./sprites/bonus/ship_l_2.xpm"
# define SHIP_D "./sprites/ship_d.xpm"
# define SHIP_D_2 "./sprites/bonus/ship_r_2.xpm"
# define WATER "./sprites/water.xpm"
# define CLIFF "./sprites/cliff.xpm"
# define BUOY "./sprites/buoy.xpm"
# define DOCK "./sprites/E.xpm"
# define DOCKED_R "./sprites/C.xpm"
# define DOCKED_L "./sprites/1.xpm"
# define PIRATE "./sprites/bonus/pirate.xpm"
# define PIRATE_2 "./sprites/bonus/pirate_2.xpm"

typedef struct s_mlx
{
	char		**map;
	int			y;
	int			x;
	int			coins;
	int			moves;
	int			animation;
	void		*mlx;
	void		*mlx_win;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	void		*ship_u;
	void		*ship_u_2;
	void		*ship_d;
	void		*ship_d_2;
	void		*ship_l;
	void		*ship_l_2;
	void		*ship_r;
	void		*ship_r_2;
	void		*water;
	void		*cliff;
	void		*buoy;
	void		*dock;
	void		*docked_r;
	void		*docked_l;
	void		*pirate;
	void		*pirate_2;
}				t_mlx;

//START
int			check_file(char *file);
int			meassure_map(char *file, char axis);
char		**load_map(char *file, int w, int h);

//CHECK
int			check_map(char **map);
int			borders(int y, int x, char **map);
int			characters_ret(int chars[4]);
int			start_coords(char **map, char axis);
int			find_exit(int y, int x, char **map);

//UTILS
void		ft_free_map(char **data);
void		ft_print_map(char **map);
void		ft_print_map_ascii(char **map);
int			start_coords(char **map, char axis);
int			count(char **map, char axis);
char		*ft_itoa(int n);

//MLX UTILS
int			close_window(t_mlx *data);
void		destroy_sprites(t_mlx *data);
t_mlx		*load_sprites(t_mlx *data);
int			pressed_key(t_mlx *data, int key_f);
void		put_water(t_mlx *data, int x, int y);
void		put_cliff(t_mlx *data, int x, int y);
void		put_buoy(t_mlx *data, int x, int y);
void		put_dock(t_mlx *data, int x, int y);
void		put_map(t_mlx *data);

//FT_PRINTF
int			ft_printf(const char *arg, ...);
int			ft_putchar(char c, int count);
int			ft_putstr(char *str, int count);
int			ft_putnbr(int n, int count);
int			ft_putunbr(unsigned int n, int count);
int			ft_puthex(unsigned long n, int count, char arg_format);
int			ft_putptr(unsigned long p, int count);

//BONUS
int			check_file_bonus(char *file);
int			meassure_map_bonus(char *file, char axis);
char		**load_map_bonus(char *file, int w, int h);
int			check_map_bonus(char **map);
int			find_exit_bonus(int y, int x, char **map);
int			pressed_key_bonus(t_mlx *data, int key);
void		put_map_bonus(t_mlx *data);

#endif
