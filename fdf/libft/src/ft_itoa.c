/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tperraut <tperraut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/11 16:10:05 by tperraut          #+#    #+#             */
/*   Updated: 2016/05/21 18:17:20 by tperraut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	n = ABS(n);
	digit = ft_nbdigit(n);
	digit += neg;
	if (!(str = (char*)malloc(sizeof(char) * (digit + 1))))
		return (NULL);
	str[digit] = '\0';
	if (neg)
		str[0] = '-';
	while (neg < digit--)
	{
		str[digit] = (int)('0' + n % 10);
		n /= 10;
	}
	return (str);
}
