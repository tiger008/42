/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tperraut <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 14:33:13 by tperraut          #+#    #+#             */
/*   Updated: 2016/05/22 14:54:15 by tperraut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *b1, const void *b2, size_t len)
{
	unsigned char	*bb1;
	unsigned char	*bb2;

	bb1 = (unsigned char *)b1;
	bb2 = (unsigned char *)b2;
	while (len--)
	{
		if (*bb1 != *bb2)
			return ((int)(*bb1 - *bb2));
		bb1++;
		bb2++;
	}
	return (0);
}
