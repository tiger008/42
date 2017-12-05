/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tperraut <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 23:53:00 by tperraut          #+#    #+#             */
/*   Updated: 2016/05/21 17:04:46 by tperraut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strstr(const char *s1, const char *s2)
{
	size_t	l2;

	if (!*s2)
		return ((char *)s1);
	if (!(s1 = ft_strchr(s1, (int)s2[0])))
		return (NULL);
	l2 = ft_strlen(s2);
	while (*s1)
	{
		if (!strncmp(s1, s2, l2))
			return ((char *)s1);
		s1++;
	}
	return (NULL);
}
