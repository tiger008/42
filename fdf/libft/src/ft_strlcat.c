/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tperraut <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 17:24:25 by tperraut          #+#    #+#             */
/*   Updated: 2016/05/22 16:14:12 by tperraut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len;
	size_t	i;
	char	*tmp;

	len = ft_strlen(dst);
	i = 0;
	tmp = dst + len;
	while (src[i] && len + i < size - 1)
	{
		tmp[i] = src[i];
		i++;
	}
	tmp[i] = '\0';
	return (MIN(size, len) + ft_strlen(src));
}
