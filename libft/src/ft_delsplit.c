/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_delsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tperraut <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/23 21:14:04 by tperraut          #+#    #+#             */
/*   Updated: 2016/05/24 03:42:38 by tperraut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_delsplit(char ***pa_str)
{
	int		i;
	char	**tmp;

	if (pa_str && *pa_str)
	{
		tmp = *pa_str;
		i = 0;
		while (tmp[i])
		{
			free(tmp[i]);
			i++;
		}
		free(tmp[i]);
		free(tmp);
		tmp = NULL;
	}
}
