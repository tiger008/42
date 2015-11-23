/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tperraut <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 14:32:15 by tperraut          #+#    #+#             */
/*   Updated: 2014/11/18 21:01:12 by tperraut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *b, int c, size_t len)
{
	char	*bb;
	size_t	i;

	i = 0;
	if (b == NULL)
		return (NULL);
	bb = (char*)b;
	while (i < len)
	{
		if ((unsigned char)bb[i] == (unsigned char)c)
			return ((void*)&bb[i]);
		i++;
	}
	return (NULL);
}
