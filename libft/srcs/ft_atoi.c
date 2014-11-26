/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tperraut <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 17:04:17 by tperraut          #+#    #+#             */
/*   Updated: 2014/11/15 22:57:32 by tperraut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi(const char *str)
{
	int	nmri[4];

	nmri[0] = -3;
	while (nmri[0]++ < 0)
		nmri[nmri[0] + 3] = 0;
	while (str[nmri[3]] == ' ' || str[nmri[3]] == '\t' || str[nmri[3]] == '\n'
			|| str[nmri[3]] == '\f' || str[nmri[3]] == '\r'
			|| str[nmri[3]] == '\v')
		nmri[3]++;
	if (str[nmri[3]] == '-')
	{
		nmri[0] = -1;
		nmri[3]++;
	}
	else if (str[nmri[3]] == '+')
		nmri[3]++;
	while (str[nmri[3]] >= '0' && str[nmri[3]] <= '9' && nmri[1] < 12)
	{
		nmri[2] = nmri[2] * 10 + (int)(str[nmri[3]++] - '0');
		nmri[1]++;
	}
	return (nmri[2] * nmri[0]);
}
