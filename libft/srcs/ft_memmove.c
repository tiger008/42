/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tperraut <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 22:30:57 by tperraut          #+#    #+#             */
/*   Updated: 2014/11/26 11:59:29 by tperraut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*temp;
	char	*dstdst;
	char	*srcsrc;
	size_t	i;
	size_t	srcsrclen;

	i = 0;
	dstdst = (char*)dst;
	srcsrc = (char*)src;
	srcsrclen = ft_strlen(srcsrc);
	if (!(temp = (char*)malloc(sizeof(char) * (srcsrclen + 1))) || !src || !dst)
		return (NULL);
	while (i++ < srcsrclen)
		temp[i - 1] = srcsrc[i - 1];
	temp[i] = '\0';
	i = 0;
	while (i < len)
	{
		dstdst[i] = temp[i];
		i++;
	}
	free(temp);
	return (dst);
}
