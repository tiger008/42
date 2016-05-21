/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tperraut <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/11 15:00:00 by tperraut          #+#    #+#             */
/*   Updated: 2016/05/21 18:59:12 by tperraut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*static int	ft_strn(const char *s1, const char *s2, size_t n)
**{
**	size_t	i;
**
**	i = 0;
**	if (n == 0)
**		return (0);
**	while (s1[i] && (unsigned char)s1[i] == (unsigned char)s2[i] && i < n)
**		i++;
**	if (i == n || !s2[i])
**		return (0);
**	return ((int)((unsigned char)s1[i] - (unsigned char)s2[i]));
**}
**
**char		*ft_strnstr(const char *s1, const char *s2, size_t n)
**{
**	size_t	i;
**
**	i = 0;
**	if (!*s2)
**		return ((char *)s1);
**	while (s1[i])
**	{
**		if (s2[0] == s1[i])
**		{
**			if (!ft_strn(s1 + i, s2, n))
**				return ((char *)(s1 + i));
**		}
**		i++;
**	}
**	return (NULL);
**}
*/

char		*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	size;

	IF_RETURN(!*s2, (char *)s1);
	IF_RETURN(!(s1 = ft_strchr(s1, (int)s2[0])), NULL);
	size = MIN(ft_strlen(s2), n);
	i = -1;
	while (s1[i++] && i < n)
	{
		if (!strncmp(&s1[i], s2, size) && i + size < n)
			return ((char *)s1);
		i++;
	}
	return (NULL);
}
