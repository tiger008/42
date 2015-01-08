/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tperraut <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/11 22:16:40 by tperraut          #+#    #+#             */
/*   Updated: 2014/11/15 20:42:32 by tperraut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	i;
	char	*dst;
	size_t	slen;

	i = 0;
	if (s == NULL)
		return (NULL);
	slen = ft_strlen(s) - 1;
	while ((s[i] == ' ' || s[i] == '\n' || s[i] == '\t') && s[i])
		i++;
	while ((s[slen] == ' ' || s[slen] == '\n' || s[slen] == '\t') && slen > i)
		slen--;
	dst = ft_strsub(s, i, slen - i + 1);
	return (dst);
}
