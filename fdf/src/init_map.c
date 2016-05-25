/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tperraut <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/24 00:26:54 by tperraut          #+#    #+#             */
/*   Updated: 2016/05/25 10:09:05 by tperraut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdlib.h>

void	init_map(t_map **map, int co)
{
	t_map	*tmp;

	IF_ERROR(!map || co < 1, "map error");
	IF_ERROR(!(tmp = (t_map *)malloc(sizeof(t_map))), "init_map() fail");
	tmp->tab = NULL;
	tmp->li = 1;
	tmp->co = co;
	*map = tmp;
}
