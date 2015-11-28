/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tperraut <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/11 19:20:47 by tperraut          #+#    #+#             */
/*   Updated: 2014/11/11 19:26:20 by tperraut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	nn;

	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		nn = (unsigned int)-n;
	}
	else
		nn = (unsigned int)n;
	if (nn >= 10)
	{
		ft_putnbr_fd((int)(nn / 10), fd);
		ft_putnbr_fd((int)(nn % 10), fd);
	}
	else
		ft_putchar_fd('0' + nn, fd);
}
