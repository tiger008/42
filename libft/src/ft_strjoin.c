/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tperraut <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/11 22:16:21 by tperraut          #+#    #+#             */
/*   Updated: 2014/11/15 20:58:24 by tperraut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	var[4];
	char	*dest;

	var[0] = 0;
	var[1] = 0;
	var[2] = ft_strlen(s1);
	var[3] = ft_strlen(s2);
	dest = (char*)malloc(sizeof(char) * (var[2] + var[3] + 1));
	if (dest == NULL)
		return (NULL);
	if (s1)
	{
		while (s1[var[0]])
		{
			dest[var[0]] = s1[var[0]];
			var[0]++;
		}
	}
	if (s2)
	{
		while (s2[var[1]])
			dest[var[0]++] = s2[var[1]++];
	}
	dest[var[0]] = '\0';
	return (dest);
}
