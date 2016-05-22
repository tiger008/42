/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tperraut <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 17:45:13 by tperraut          #+#    #+#             */
/*   Updated: 2016/05/20 18:38:14 by tperraut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strrchr(const char *s, int c)
{
	char	*tmp;

	tmp = (char *)s + ft_strlen(s) + 1;
	while (--tmp > s - 1)
		if (*tmp == (char)c)
			return (tmp);
	return (NULL);
}
