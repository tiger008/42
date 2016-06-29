/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tperraut <tperraut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/25 17:45:55 by tperraut          #+#    #+#             */
/*   Updated: 2016/06/29 12:16:50 by tperraut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fill_pt(t_pt p, t_img *img)
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

void	draw_bg(t_img *img)
{
	int				x = 0;
	int				y = 0;
	unsigned char	*pixel;

	while (y <= H_IMG)
	{
		x = 0;
		while (x <= W_IMG)
		{
			pixel = (unsigned char *)img->data + y * img->sizeline
				+ (img->bpp/8) * x;
			pixel[2] = (((W_IMG - x) % (2 * W_IMG)) / (W_IMG / 100))
				* (255 / 100);
			pixel[1] = ((y % (2 * H_IMG)) / (H_IMG / 100)) * (255 / 100);
			pixel[0] = (((2 * W_IMG + x) % W_IMG) / (W_IMG / 100))
				* (255 / 100);
			x++;
		}
		y++;
	}
}

static void	fill_line(t_pt p1, t_pt p2)
{
	t_pt	tmp;

}

int			draw(void *param)
{
	t_env	*e;
	t_pt	p1;
	t_pt	p2;
	int		i;
	int		j;

	i = 0;
	j = 0;
	e = (t_env *)param;
	pt_iso(pt_init(&p1, i, j, ((e->map)->tab)[i][j]));
	if (param)
		return (0);
	return (0);
}
