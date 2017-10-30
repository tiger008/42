/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoabase.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tperraut <tperraut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/11 16:10:05 by tperraut          #+#    #+#             */
/*   Updated: 2016/05/17 18:07:29 by tperraut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libftprintf.h"

static int	nbdigit(int n, int base)
{
	int	digit;

	digit = 1;
	while (n >= base)
	{
		n = n / base;
		++digit;
	}
	return (digit);
}

char		*ft_itoabase(int n, int base)
{
	const char *a_max_alpha_16[] = A_MAX_ALPHA_16;
	const char *alpha_16 = ALPHA_16;
	char	*str;
	int		neg;
	int		digit;

	if (base < 2 || base > 16)
		return (NULL);
	if (n == -2147483648)
		return (ft_strdup(a_max_alpha_16[base - 2]));
	neg = (n < 0) ? 1 : 0;
	n = (n < 0) ? -n : n;
	digit = nbdigit(n, base);
	if (!(str = (char*)malloc(sizeof(char) * (digit + ((neg) ? 2 : 1)))))
		return (NULL);
	str[digit] = '\0';
	if (neg)
		str[0] = '-';
	while (digit--)
	{
		str[digit + neg] = alpha_16[n % base];
		n /= base;
	}
	return (str);
}
