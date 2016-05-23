/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tperraut <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/11 15:00:00 by tperraut          #+#    #+#             */
/*   Updated: 2016/05/22 16:24:17 by tperraut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	size;

	IF_RETURN(!*s2, (char *)s1);
	size = ft_strlen(s2);
	while (*s1 != *s2)
	{
		IF_RETURN(!*s1 || size > n, NULL);
		s1++;
		n--;
	}
	while (*s1)
	{
		IF_RETURN(size > n, NULL);
		if (!strncmp(s1, s2, size))
			return ((char *)s1);
		n--;
		s1++;
	}
	return (NULL);
}
