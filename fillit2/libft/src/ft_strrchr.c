/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tperraut <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 17:45:13 by tperraut          #+#    #+#             */
/*   Updated: 2014/11/10 17:56:45 by tperraut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strrchr(const char *s, int c)
{
	size_t	len;
	size_t	i;
	char	*dst;

	dst = NULL;
	i = 0;
	len = ft_strlen(s);
	if ((char)c == '\0')
		return ((char*)(s + len));
	while (i < len)
	{
		if (s[i] == (char)c)
			dst = (char*)(s + i);
		i++;
	}
	return (dst);
}
