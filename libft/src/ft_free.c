/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tperraut <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/25 15:52:55 by tperraut          #+#    #+#             */
/*   Updated: 2016/05/25 16:11:39 by tperraut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>

void	ft_free(int n, ...)
{
	va_list	ap;
	void	*p;

	va_start(ap, n);
	while (n--)
	{
		p = va_arg(ap, void *);
		free(p);
	}
	va_end(ap);
}
