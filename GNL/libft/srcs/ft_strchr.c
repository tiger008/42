/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tperraut <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 17:35:19 by tperraut          #+#    #+#             */
/*   Updated: 2014/11/10 17:56:02 by tperraut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	len;
	size_t	i;

	i = 0;
	if (s == NULL)
		return (NULL);
	len = ft_strlen(s);
	if ((char)c == '\0')
		return ((char*)(s + len));
	while (i < len && s[i] != (char)c)
		i++;
	if (i < len)
		return ((char*)(s + i));
	return (NULL);
}
