/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngordobi <ngordobi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 13:31:05 by ngordobi          #+#    #+#             */
/*   Updated: 2024/06/17 14:42:59 by ngordobi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free_map(char **map)
{
	int	y;

	y = 0;
	while (map[y] != NULL)
	{
		free(map[y]);
		y++;
	}
	free(map);
	map = NULL;
}
