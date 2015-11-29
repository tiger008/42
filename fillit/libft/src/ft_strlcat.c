/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tperraut <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 17:24:25 by tperraut          #+#    #+#             */
/*   Updated: 2014/11/18 21:25:02 by tperraut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dstlen;
	size_t	srclen;
	size_t	i;
	size_t	j;

	if (!src || !dst)
		return (size);
	dstlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	if (size == 0)
		return (dstlen);
	j = dstlen;
	i = 0;
	while (j < size - 1)
	{
		dst[j++] = src[i++];
	}
	dst[j] = '\0';
	if (size < dstlen)
		return (srclen + size);
	return (srclen + dstlen);
}
