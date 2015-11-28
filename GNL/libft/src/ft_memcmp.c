/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tperraut <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 14:33:13 by tperraut          #+#    #+#             */
/*   Updated: 2014/11/18 22:03:24 by tperraut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *b1, const void *b2, size_t len)
{
	size_t			i;
	unsigned char	*bb1;
	unsigned char	*bb2;

	if (len == 0 || (!b1 && !b2))
		return (0);
	bb1 = (unsigned char*)b1;
	bb2 = (unsigned char*)b2;
	i = 0;
	if (b1 == NULL)
		return ((int)bb2[i]);
	if (b2 == NULL)
		return ((int)bb1[i]);
	while (i < len)
	{
		if (bb1[i] != bb2[i])
			return ((int)(bb1[i] - bb2[i]));
		i++;
	}
	return (0);
}
