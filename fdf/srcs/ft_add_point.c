/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_point.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tperraut <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/08 08:32:04 by tperraut          #+#    #+#             */
/*   Updated: 2015/01/08 13:17:52 by tperraut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdlib.h>

t_grid	*ft_add_left(t_grid *grid, t_point *point)
{
	t_grid	*tmp;

	tmp = (t_grid *)malloc(sizeof(t_grid));
	if (tmp)
	{
		tmp->point = point;
		tmp->left = grid;
	}
	return (tmp);
}
