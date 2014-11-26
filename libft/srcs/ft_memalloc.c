/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tperraut <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 19:24:59 by tperraut          #+#    #+#             */
/*   Updated: 2014/11/18 20:58:55 by tperraut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char	*str;
	size_t	i;

	i = 0;
	if (size == 0)
		return (NULL);
	str = (char*)malloc(sizeof(char) * size);
	if (str == NULL)
		return (NULL);
	while (i < size)
		str[i++] = '\0';
	return ((void*)str);
}
