/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_delsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tperraut <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/23 21:14:04 by tperraut          #+#    #+#             */
/*   Updated: 2016/05/23 21:22:19 by tperraut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_delsplit(char ***pa_str)
{
	int	i;

	if (pa_str && *pa_str)
	{
		i = 0;
		while ((*pa_str)[i])
		{
			free(&((*pa_str)[i]));
			i++;
		}
		free(*pa_str);
		*pa_str = NULL;
	}
}
