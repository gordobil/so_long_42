/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngordobi <ngordobi@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 14:22:51 by ngordobi          #+#    #+#             */
/*   Updated: 2024/02/12 12:49:17 by ngordobi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_putnbr(int n, int count)
{
	if (n < 0)
	{
		if (n == -2147483648)
		{
			count = ft_putstr("-2147483648", count);
			return (count);
		}
		else
		{
			count = ft_putchar('-', count);
			n = n * -1;
		}
	}
	if (n >= 10)
	{
		count = ft_putnbr(n / 10, count);
		count = ft_putnbr(n % 10, count);
	}
	else
		count = ft_putchar(n + '0', count);
	return (count);
}
