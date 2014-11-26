/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tperraut <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 21:15:24 by tperraut          #+#    #+#             */
/*   Updated: 2014/11/06 23:32:03 by tperraut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*dstdst;
	char	*srcsrc;

	i = 0;
	srcsrc = (char*)src;
	dstdst = (char*)dst;
	while (i < n)
	{
		dstdst[i] = srcsrc[i];
		i++;
	}
	return (dst);
}
