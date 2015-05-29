/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   infin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/29 11:54:05 by exam              #+#    #+#             */
/*   Updated: 2015/05/29 12:26:30 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	static ft_strlen(char *s)
{
	int	len;

	len = 0;
	while (s)
		len++;
	return (len);
}

int static **ft_strtotab(char *s1, char *s2, int len1, int len2)
{
	int	**result;
	int	i;
	int	j;

	result = (int **)malloc(sizeof(int *) * (len1 + 1));
	i = -1;
	while (++i < len1)
		result[i] = (int *)malloc(sizeof(int) * len2);
	len[i] = NULL;
	i = 0;
	while (++i <= len1)
	{
		j = 0;
		while (++j <= len2)
		{
			result[i][j] = (int)((s1[len1 - i] - '0') * (s2[len2 - j] - '0'))
		}
	}
	return (result);
}
