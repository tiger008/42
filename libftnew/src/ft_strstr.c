/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tperraut <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 23:53:00 by tperraut          #+#    #+#             */
/*   Updated: 2016/05/20 19:02:30 by tperraut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//static int	ft_tostr(const char *str, const char *tofind, size_t tolen)
//{
//	size_t	i;
//
//	i = 1;
//	while (i < tolen && str[i] == tofind[i])
//		i++;
//	if (i < tolen)
//		return (FALSE);
//	return (TRUE);
//}
//
//char		*ft_strstr(const char *s1, const char *s2)
//{
//	size_t	i;
//	size_t	s1len;
//	size_t	s2len;
//
//	s1len = ft_strlen(s1);
//	s2len = ft_strlen(s2);
//	if (s2len == 0)
//		return ((char *)s1);
//	i = 0;
//	while (s1[i] && s1len - i >= s2len)
//	{
//		if (s2[0] == s1[i])
//		{
//			if (ft_tostr(s1 + i, s2, s2len))
//				return ((char*)(s1 + i));
//		}
//		i++;
//	}
//	return (NULL);
//}

char		*ft_strstr(const char *s1, const char *s2)
{
	char	lock;
	size_t	m;
	size_t	next;
	size_t	i;
	char	*tmp;

	i = 0;
	m = 0;
	lock = 0;
	tmp = (char *)s1;
	if (!*s2)
		return ((char *)s1);
	if (!(s1 = ft_strchr(s1, (int)s2[0])))
		return (NULL);
	next = s1 - tmp;
	while (s1[i + m] && s2[i])
	{
		if (i > 0 && s1[i + m] == s2[0] && !lock)
		{
			next = m + i;
			lock = 1;
		}
		if (s1[i + m] == s2[i])
			++i;
		else
		{
			m = next;
			lock = 0;
			i = 0;
		}
	}
	if (!s2[i])
		return ((char *)s1 + m);
	return (NULL);
}
