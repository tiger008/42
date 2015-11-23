/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tperraut <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/11 22:15:35 by tperraut          #+#    #+#             */
/*   Updated: 2014/11/18 21:30:16 by tperraut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (TRUE);
	if (s1 == NULL || s2 == NULL)
		return (FALSE);
	while (i < n && s1[i] && s1[i] == s2[i])
		i++;
	if (i == n || (ft_strlen(s1 + i) == 0 && ft_strlen(s2 + i) == 0))
		return (TRUE);
	return (FALSE);
}
