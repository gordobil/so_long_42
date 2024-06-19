/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_characters_ret.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngordobi <ngordobi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 13:41:15 by ngordobi          #+#    #+#             */
/*   Updated: 2024/06/19 13:41:42 by ngordobi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	characters_ret(int chars[4])
{
	int	errors;

	errors = 0;
	if (chars[0] != 1)
	{
		ft_printf("Error\nInvalid number of players in the map\n");
		errors = -1;
	}
	if (chars[1] != 1)
	{
		ft_printf("Error\nInvalid number of exits in the map\n");
		errors = -1;
	}
	if (chars[2] < 1)
	{
		ft_printf("Error\nNo coins found in the map\n");
		errors = -1;
	}
	if (chars[3] != 0)
	{
		ft_printf("Error\nInvalid character found in the map\n");
		errors = -1;
	}
	return (errors);
}