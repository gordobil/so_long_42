/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngordobi <ngordobi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 11:07:18 by ngordobi          #+#    #+#             */
/*   Updated: 2024/06/19 11:05:20 by ngordobi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	format(va_list list, const char *arg, int count)
{
	if (*arg == 'c')
		count = ft_putchar(va_arg(list, int), count);
	else if (*arg == 's')
		count = ft_putstr(va_arg(list, char *), count);
	else if (*arg == 'p')
		count = ft_putptr(va_arg(list, unsigned long), count);
	else if (*arg == 'd' || *arg == 'i')
		count = ft_putnbr(va_arg(list, int), count);
	else if (*arg == 'u')
		count = ft_putunbr(va_arg(list, unsigned int), count);
	else if (*arg == 'x' || *arg == 'X')
		count = ft_puthex(va_arg(list, unsigned int), count, *arg);
	else if (*arg == '%')
		count = ft_putchar('%', count);
	return (count);
}

int	ft_printf(const char *first_arg, ...)
{
	va_list	list;
	int		count;

	va_start(list, first_arg);
	count = 0;
	while (*first_arg)
	{
		if (*first_arg != '%')
			count = ft_putchar(*first_arg, count);
		else
		{
			first_arg++;
			count = format(list, first_arg, count);
		}
		first_arg++;
	}
	va_end(list);
	return (count);
}
