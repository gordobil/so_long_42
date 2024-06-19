/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngordobi <ngordobi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 19:57:26 by ngordobi          #+#    #+#             */
/*   Updated: 2024/06/19 12:54:41 by ngordobi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	nlen(long n)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		n = n * -1;
		i++;
	}
	if (n == 0)
		i = 1;
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ret(int len, long nb, char *s)
{
	if (nb == 0)
		s[0] = '0';
	else if (nb == 42)
	{
		s[0] = '4';
		s[1] = '2';
	}
	else
	{
		while (len >= 0)
		{
			if (s[len] == '-')
				break ;
			s[len] = (nb % 10) + '0';
			len--;
			nb = nb / 10;
		}
	}
	return (s);
}

char	*ft_itoa(int n)
{
	char	*s;
	int		len;
	long	nb;

	len = nlen(n);
	s = malloc((len + 1) * sizeof(char));
	nb = n;
	if (s == NULL)
		return (NULL);
	if (nb < 0)
	{
		s[0] = '-';
		nb = nb * -1;
	}
	s[len] = '\0';
	len--;
	return (ret(len, nb, s));
}