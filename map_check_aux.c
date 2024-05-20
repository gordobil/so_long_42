/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_aux.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngordobi <ngordobi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 14:41:47 by ngordobi          #+#    #+#             */
/*   Updated: 2024/05/20 14:58:34 by ngordobi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	*chars_to_zero(int size)
{
	int	i;
	int	chars[size];

	i = 0;
	while (i < size)
	{
		chars[i] = 0;
		i++;
	}
	return (chars);
}

int	characters_ret(int chars[4])
{
	if (chars[0] != 1 || chars[1] != 1)
		return (-1);
	else if (chars[3] != 0)
	{
		ft_putstr("Error\nInvalid character found in the map.");
		return (-1);
	}
	else if (chars[2] < 1)
	{
		ft_putstr("Error\nNo coins in the map.");
		return (-1);
	}
	return (0);
}