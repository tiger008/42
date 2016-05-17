/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tperraut <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 17:06:23 by tperraut          #+#    #+#             */
/*   Updated: 2014/11/10 17:55:04 by tperraut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	lens1;

	lens1 = ft_strlen(s1);
	i = 0;
	while (i < n)
	{
		s1[i + lens1] = s2[i];
		i++;
	}
	s1[i + lens1] = '\0';
	return (s1);
}
