/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tperraut <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/11 22:00:00 by tperraut          #+#    #+#             */
/*   Updated: 2014/11/15 18:02:57 by tperraut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*ss;
	size_t	i;

	i = 0;
	if (s == NULL || f == NULL)
		return (NULL);
	ss = (char*)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (ss == NULL)
		return (NULL);
	while (s[i])
	{
		ss[i] = f(i, s[i]);
		i++;
	}
	ss[i] = '\0';
	return (ss);
}
