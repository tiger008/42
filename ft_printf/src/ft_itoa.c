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

static int	ft_nbdigit(int n, int *div)
{
	int	digit;

	digit = 1;
	*div = 1;
	while (n > 9)
	{
		n = n / 10;
		*div *= 10;
		++digit;
	}
	return (digit);
}

char		*ft_itoa(int n)
{
	char	*result;
	int		i;
	int		digit;
	int		div;

	digit = ft_nbdigit(n, &div);
	i = 0;
	if (!(result = (char*)malloc(sizeof(char) * (digit + ((n < 0) ? 2 : 1)))))
		return (NULL);
	if (n == -2147483648)
		result = "-2147483648";
	else
	{
		n = (n < 0) ? -n : n;
		while (digit)
		{
			result[i] = (int)('0' + ((n / div) % 10));
			div /= 10;
			digit--;
			++i;
		}
		result[i] = '\0';
	}
	return (result);
}
