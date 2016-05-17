/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tperraut <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/11 15:00:00 by tperraut          #+#    #+#             */
/*   Updated: 2016/05/17 19:34:31 by tperraut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* static int	ft_min(int a, int b) */
/* { */
/* 	return ((a < b) ? a : b); */
/* } */

/* static int	ft_tonstr(const char *str, const char *tofind, size_t n) */
/* { */
/* 	size_t	i; */

/* 	i = 0; */
/* 	while (i < n && str[i] == tofind[i]) */
/* 		i++; */
/* 	if (i == n || (i < n && tofind[i])) */
/* 		return (TRUE); */
/* 	return (FALSE); */
/* } */

static int	ft_strn(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] && (unsigned char)s1[i] == (unsigned char)s2[i] && i < n)
		i++;
	if (i == n || !s2[i])
		return (0);
	return ((int)((unsigned char)s1[i] - (unsigned char)s2[i]));
}

char		*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (!*s2)
		return ((char *)s1);
	while (s1[i])
	{
		if (s2[0] == s1[i])
		{
			if (!ft_strn(s1 + i, s2, n))
				return ((char *)(s1 + i));
		}
		i++;
	}
	return (NULL);
}










