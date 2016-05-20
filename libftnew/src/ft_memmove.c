/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tperraut <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 22:30:57 by tperraut          #+#    #+#             */
/*   Updated: 2016/05/20 15:43:24 by tperraut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	if (src < dst)
	{
		while (--len > 0)
			((char *)dst)[len] = ((char *)src)[len];
		((char *)dst)[len] = ((char *)src)[len];
	}
	else if (src != dst)
		ft_memcpy(dst, src, len);
	return (dst);
}
