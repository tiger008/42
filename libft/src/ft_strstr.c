/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tperraut <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 23:53:00 by tperraut          #+#    #+#             */
/*   Updated: 2014/11/26 12:52:26 by tperraut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_tostr(const char *str, const char *tofind, size_t tolen)
{
	size_t	i;

	i = 1;
	while (i < tolen && str[i] == tofind[i])
		i++;
	if (i < tolen)
		return (FALSE);
	return (TRUE);
}

char		*ft_strstr(const char *s1, const char *s2)
{
	size_t	i;
	size_t	s1len;
	size_t	s2len;

	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	if (s2len == 0)
		return ((char *)s1);
	i = 0;
	while (s1[i] && s1len - i >= s2len)
	{
		if (s2[0] == s1[i])
		{
			if (ft_tostr(s1 + i, s2, s2len))
				return ((char*)(s1 + i));
		}
		i++;
	}
	return (NULL);
}
