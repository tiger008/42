/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tperraut <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 16:08:29 by tperraut          #+#    #+#             */
/*   Updated: 2014/11/10 14:25:05 by tperraut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	unsigned int	nn;

	if (n < 0)
	{
		ft_putchar('-');
		nn = (unsigned int)-n;
	}
	else
		nn = (unsigned int)n;
	if (nn >= 10)
	{
		ft_putnbr((int)(nn / 10));
		ft_putnbr((int)(nn % 10));
	}
	else
		ft_putchar('0' + nn);
}
