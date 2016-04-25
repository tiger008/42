/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tperraut <tperraut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/11 16:10:05 by tperraut          #+#    #+#             */
/*   Updated: 2016/04/25 01:45:07 by tperraut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"

static int	ft_nbdigit(int n)
{
	int	digit;

	digit = 1;
	while (n > 9)
	{
		n = n / 10;
		++digit;
	}
	return (digit);
}

char		*ft_itoa(int n)
{
	char	*str;
	int		neg;
	int		digit;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	neg = (n < 0) ? 1 : 0;
	n = (n < 0) ? -n : n;
	digit = ft_nbdigit(n);
	if (!(str = (char*)malloc(sizeof(char) * (digit + ((n < 0) ? 2 : 1)))))
		return (NULL);
	else
	{
		if (neg)
			str[0] = '-';
		str[digit] = '\0';
		while (digit--)
		{
			str[digit + neg] = (int)('0' + n % 10);
			n /= 10;
		}
	}
	return (str);
}
