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
** r for result
** i for index
*/

int		ft_atoi(const char *str)
{
	int				n;
	int				i;
	unsigned int	r;

	n = 1;
	i = 0;
	r = 0;
	while (ft_isblank(str[i]) || ft_isreturn(str[i]))
		i++;
	if (str[i] == '-' && ++i)
		n = -1;
	else if (str[i] == '+')
		i++;
	while (str[i] == '0')
		i++;
	while (ft_isdigit(str[i]))
	{
		if (r > MAX_INT)
			return(0);
		r = r * 10 + (unsigned int)(str[i++] - '0');
	}
	return ((int)r * n);
}

int		ft_satoi(const char *str)
{
	int				ni[2];
	unsigned int	r;

	ni[0] = 1;
	ni[1] = 0;
	r = 0;
	while (ft_isblank(str[ni[1]]) || ft_isreturn(str[ni[1]]))
		ni[1]++;
	if (str[ni[1]] == '-' && ++ni[1])
		ni[0] = -1;
	else if (str[ni[1]] == '+')
		ni[1]++;
	while (str[ni[1]] == '0')
		ni[1]++;
	while (ft_isdigit(str[ni[1]]))
	{
		if (r > MAX_INT)
			ft_error("atoi int limit");
		r = r * 10 + (unsigned int)(str[ni[1]++] - '0');
	}
	return (r * ni[0]);
}
