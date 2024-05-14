/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngordobi <ngordobi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 13:50:10 by ngordobi          #+#    #+#             */
/*   Updated: 2024/05/14 12:19:25 by ngordobi         ###   ########.fr       */
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
	unsigned int	x;
	unsigned int	y;
}					t_map;

//START
int					check_file(char *file);
int					map_meassure(char *file, int axis);
char				**reserve_matrix(int width, int height, char *file);

//UTILS
void				ft_putstr(char	*str);

#endif
