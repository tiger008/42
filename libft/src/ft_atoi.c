/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tperraut <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 17:04:17 by tperraut          #+#    #+#             */
/*   Updated: 2016/05/23 20:48:48 by tperraut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** n for the sign
** m for max digit
** r for result
** i for index
*/

int		ft_atoi(const char *str)
{
	int	nmri[4];

	nmri[0] = -3;
	while (nmri[0]++ < 0)
		nmri[nmri[0] + 3] = 0;
	while (ft_isblank(str[nmri[3]]) || ft_isreturn(str[nmri[3]]))
		nmri[3]++;
	if (str[nmri[3]] == '-')
	{
		nmri[0] = -1;
		nmri[3]++;
	}
	else if (str[nmri[3]] == '+')
		nmri[3]++;
	while (str[nmri[3]] == '0')
		nmri[3]++;
	while (ft_isdigit(str[nmri[3]]) && nmri[1]++ < 12)
		nmri[2] = nmri[2] * 10 + (int)(str[nmri[3]++] - '0');
	return (nmri[2] * nmri[0]);
}
