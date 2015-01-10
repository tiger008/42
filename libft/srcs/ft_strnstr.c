/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tperraut <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/11 15:00:00 by tperraut          #+#    #+#             */
/*   Updated: 2015/01/08 10:22:26 by tperraut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_tonstr(const char *str, const char *tofind, size_t n, size_t len)
{
	size_t	i;

	i = 1;
	while (i < n && str[i] == tofind[i] && tofind[i] != '\0')
		i++;
	if ((i < n && tofind[i] != '\0') || (len + i) > n)
		return (FALSE);
	return (TRUE);
}

char		*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (ft_strlen(s2) == 0)
		return ((char *)s1);
	i = 0;
	while (s1[i] && i < n)
	{
		if (s2[0] == s1[i])
		{
			if (ft_tonstr(s1 + i, s2, n, i))
				return ((char*)(s1 + i));
		}
		i++;
	}
	return (NULL);
}
