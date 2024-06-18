/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngordobi <ngordobi@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 14:22:51 by ngordobi          #+#    #+#             */
/*   Updated: 2024/02/12 12:50:46 by ngordobi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_puthex(unsigned long n, int count, char arg_format)
{
	if (n >= 16)
	{
		count = ft_puthex(n / 16, count, arg_format);
		count = ft_puthex(n % 16, count, arg_format);
	}
	else
	{
		if (n <= 9)
			count = ft_putchar(n + '0', count);
		else
		{
			if (arg_format == 'X')
				count = ft_putchar(n - 10 + 'A', count);
			else if (arg_format == 'x')
				count = ft_putchar(n - 10 + 'a', count);
		}
	}
	return (count);
}
