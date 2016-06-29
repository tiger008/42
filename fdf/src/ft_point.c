/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_point.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tperraut <tperraut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/29 09:01:47 by tperraut          #+#    #+#             */
/*   Updated: 2016/06/29 17:17:08 by tperraut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#include <math.h>

void	pt_new(t_pt *p, int x, int y, int z)
{
	p->x = x;
	p->y = y;
	p->z = z;
}

void	pt_inv(t_pt *p)
{
	pt_new(p, p->y, p->x, p->z);
}

void	pt_iso(t_pt *p)
{
	double	x;
	double	y;

	x = (sqrt(2) / 2) * (p->x - p->y);
	y = (sqrt(2 / 3) * p->z - (1 / sqrt(6)) * (p->x + p->y));
	pt_new(p, (int)nearbyint(x), (int)nearbyint(y), p->z);
}
