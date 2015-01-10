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

#include "libft.h"

static int	ft_nbdigit(int n)
{
	int	digit;

	digit = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n = n / 10;
		digit++;
	}
	return (digit);
}

static int	ft_tenpower(int power)
{
	int	result;
	int	i;

	i = 0;
	result = 1;
	while (i++ < power)
		result = result * 10;
	return (result);
}

char		*ft_itoa(int n)
{
	char			*result;
	unsigned int	nn;
	size_t			i;
	int				digit;

	digit = ft_nbdigit(n);
	i = 0;
	result = (char*)malloc(sizeof(char) * (digit + 2));
	if (!result)
		return (NULL);
	if (n < 0)
	{
		result[i++] = '-';
		nn = (unsigned int)-n;
	}
	else
		nn = (unsigned int)n;
	while (digit)
	{
		result[i++] = '0' + (char)((nn / ft_tenpower(digit - 1)) % 10);
		digit--;
	}
	result[i] = '\0';
	return (result);
}
