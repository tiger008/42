/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tperraut <tperraut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/29 14:44:54 by tperraut          #+#    #+#             */
/*   Updated: 2016/07/06 16:10:49 by tperraut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"

#include <stdio.h> /*TODO DEBUG*/

static void	fill_pt(t_pt p, t_img *img)
{
	unsigned char	*pixel;

	if ((p.x > W_IMG) || (p.y > H_IMG))
		return ;
	pixel = (unsigned char *)img->data + (p.y * img->sizeline
			+ (img->bpp / 8) * p.x);
	pixel[2] = (((W_IMG - p.x) % (2 * W_IMG)) / (W_IMG / 100)) * (255 / 100);
	pixel[1] = ((p.y % (2 * H_IMG)) / (H_IMG / 100)) * (255 / 100);
	pixel[0] = (((2 * W_IMG + p.x) % W_IMG) / (W_IMG / 100)) * (255 / 100);
}

void		fill_line(t_pt p1, t_pt p2, t_img *img, int mode)
{
	t_pt	tmp;

	printf("p1(%d, %d)\np2(%d, %d)\nmode: %d\n-----\n", p1.x, p1.y, p2.x, p2.y, mode);
	if (p2.x < p1.x)
		return (fill_line(p2, p1, img, mode));
	else if ((ABS(p2.x - p1.x)) < (ABS(p2.y - p1.y)))
	{
		pt_inv(&p1);
		pt_inv(&p2);
		return (fill_line(p1, p2, img, !mode));
	}
	else
	{
		pt_new(&tmp, p1.x, p1.y, p1.z);
		if (ABS(p2.x - p1.x) > 0)
			while (tmp.x <= p2.x)
			{
				if (mode > 0)
					pt_inv(&tmp);
				fill_pt(tmp, img);
				if (mode > 0)
					pt_inv(&tmp);
				tmp.y = p1.y + ((p2.y - p1.y) * (tmp.x - p1.x)) / (p2.x - p1.x);
				tmp.x++;
			}
	}
}
