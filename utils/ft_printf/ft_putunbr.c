/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngordobi <ngordobi@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 14:22:51 by ngordobi          #+#    #+#             */
/*   Updated: 2024/02/12 12:50:02 by ngordobi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	ft_putunbr(unsigned int n, int count)
{
	if (n >= 10)
	{
		count = ft_putunbr(n / 10, count);
		count = ft_putunbr(n % 10, count);
	}
	else
		count = ft_putchar(n + '0', count);
	return (count);
}
