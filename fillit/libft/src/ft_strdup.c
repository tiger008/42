/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tperraut <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 22:42:20 by tperraut          #+#    #+#             */
/*   Updated: 2016/05/22 14:58:44 by tperraut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*dst;
	size_t	len;

	len = ft_strlen(s1);
	IF_RETURN(!(dst = (char*)malloc(sizeof(char) * (len + 1))), NULL);
	dst[len] = '\0';
	while (len--)
		dst[len] = s1[len];
	return (dst);
}
