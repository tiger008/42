/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tperraut <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/11 16:10:05 by tperraut          #+#    #+#             */
/*   Updated: 2014/11/26 12:53:51 by tperraut         ###   ########.fr       */
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
	char	*result;
	int		neg;
	int		digit;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	neg = (n < 0) ? 1 : 0;
	n = (n < 0) ? -n : n;
	digit = ft_nbdigit(n);
	if (!(result = (char*)malloc(sizeof(char) * (digit + ((n < 0) ? 2 : 1)))))
		return (NULL);
	else
	{
		if (neg)
			result[0] = '-';
		result[digit] = '\0';
		while (digit--)
		{
			result[digit + neg] = (int)('0' + n % 10);
			n /= 10;
		}
	}
	return (result);
}
