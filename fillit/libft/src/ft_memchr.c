/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tperraut <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 14:32:15 by tperraut          #+#    #+#             */
/*   Updated: 2016/05/22 14:50:16 by tperraut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *b, int c, size_t len)
{
	unsigned char	*bb;

	bb = (unsigned char *)b;
	while (len--)
	{
		if (*bb == (unsigned char)c)
			return ((void *)bb);
		bb++;
	}
	return (NULL);
}
