/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tperraut <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 19:25:54 by tperraut          #+#    #+#             */
/*   Updated: 2014/11/10 16:35:18 by tperraut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	void	*pt;
	size_t	i;
	char	*dstdst;
	char	*srcsrc;

	i = 0;
	srcsrc = (char*)src;
	dstdst = (char*)dst;
	while (i < n && (unsigned char)srcsrc[i] != (unsigned char)c)
	{
		dstdst[i] = srcsrc[i];
		i++;
	}
	if (i < n && (unsigned char)srcsrc[i] == (unsigned char)c)
	{
		dstdst[i] = srcsrc[i];
		i++;
		pt = (void*)&dstdst[i];
	}
	else
		pt = NULL;
	return (pt);
}
