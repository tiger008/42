/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initgrid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tperraut <tperraut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/20 16:14:50 by tperraut          #+#    #+#             */
/*   Updated: 2015/04/06 23:04:11 by tperraut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdlib.h>

void	ft_initgrid(t_grid *grid)
{
	grid->li = 0;
	grid->co = 0;
	grid->tab = (int *)malloc(1);
}
