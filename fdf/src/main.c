/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tperraut <tperraut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/06 23:04:21 by tperraut          #+#    #+#             */
/*   Updated: 2015/05/27 15:07:25 by tperraut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <sys/stat.h>
#include <fcntl.h>
#include "libft.h"
#include <mlx.h>

t_pt	p_init(int x, int y)
{
	t_pt	p;

	p.x = x;
	p.y = y;
	return (p);
}
t_pt	p_inv(t_pt p)
{
	t_pt	pp;

	pp.x = p.y;
	pp.y = p.x;
	return (pp);
}

void	add_pt(t_pt p, t_iimg *img)
{
	unsigned char	*pixel;

	pixel = (unsigned char *)img->data + p.y * img->sizeline + (img->bpp/8) * p.x;
			pixel[2] = RED;
			pixel[1] = GREEN;
			pixel[0] = BLUE;
}

void	draw_line(t_pt p1, t_pt p2, t_iimg *img)
{
	t_pt		p;
	static int	x = 0;

	if (p2.x - p1.x < 0)
		draw_line(p2, p1, img);
	else if (ABS((p2.y - p1.y) / (p2.x - p1.x)) > 1)
	{
		x = 1;
		draw_line(p_inv(p1), p_inv(p2), img);
	}
	else
	{
		p.x = p1.x;
		p.y = p1.y;
		while (p.x <= p2.x)
		{
			(x == 0) ? add_pt(p, img) : add_pt(p_inv(p), img);
			p.y = p1.y + ((p2.y - p1.y) * (p.x - p1.x)) / (p2.x - p1.x);
			(p.x)++;
		}
	}
}


void	draw_bg(t_iimg *img)
{
	int x = 0;
	int y = 0;
	unsigned char *pixel;

	while (y <= WIN_Y)
	{
		x = 0;
		while (x <= WIN_X)
		{
			pixel = (unsigned char *)img->data + y * img->sizeline + (img->bpp/8) * x;
			pixel[2] = (((WIN_X - x) % (2 * WIN_X))/(WIN_X/100))*(255/100);
			pixel[1] = ((y % (2 * WIN_Y))/(WIN_Y/100))*(255/100);
			pixel[0] = (((2 * WIN_X + x) % WIN_X)/(WIN_X/100))*(255/100);
			x++;
		}
		y++;
	}
}
void	*get_img_data(t_env *env, t_iimg *img)
{
		return (mlx_get_data_addr(env->img,
				&img->bpp,
				&img->sizeline,
				&img->endian));
}

int	ft_expose(t_env *env)
{
	mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
	return (0);
}

/*void	rgx_pix(int x, int y, unsigned int color, t_img_inf *img)
{
	unsigned char *pixel;
	unsigned int *tmp_color;

	pixel = (unsigned char *)(img->data + y * img.sizeline
			+ (img->bpp / 8) * x);
	tmp_color = (unsigned char *)&color;
	pixel[0] = tmp_color[0];
	pixel[1] = tmp_color[1];
	pixel[2] = tmp_color[2];
}*/
int		main(int ac, char **av)
{
	t_grid	grid;
	t_env	env;
	int		op;
	t_iimg	img;
	/*		int		i;
			int		j;*/
	if (ac == 2)
	{
		ft_initgrid(&grid);
		if((op = open(av[1], O_RDONLY)) == -1)
			ft_putendl("Open fail");
		else if ((ft_parser(op, &grid)) == -1)
			ft_putendl("Parse Fail");
		else if ((env.mlx = mlx_init()) == NULL)
			ft_putendl("mlx fail to initialized");
		else if ((env.win = mlx_new_window(env.mlx, WIN_X, WIN_Y, "fdf")) == NULL)
			ft_putendl("mlx fail to initialized window");
		else if ((env.img = mlx_new_image(env.mlx, WIN_X, WIN_Y)) == NULL)
			ft_putendl("mlx fail to initialized image");
		//mlx_hook(env->win, KeyPress, KeyPressMask, &gere_key, env);
		else
		{
			img.data = get_img_data(&env, &img);
			draw_bg(&img);
			draw_line(p_init(0, 0), p_init(479, 639), &img);
			draw_line(p_init(0, 50), p_init(479, 50), &img);
			draw_line(p_init(0, 639), p_init(479, 0), &img);
			mlx_expose_hook(env.win, &ft_expose, &env);
			mlx_loop(env.mlx);
		}

		/*else
		  {
		  i = 0;
		  while (i < grid.li)
		  {
		  j = 0;
		  while (j < grid.co)
		  {
		  ft_putnbr(grid.tab[j + (i * grid.co)]);
		  ft_putchar(' ');
		  j++;
		  }
		  ft_putendl("");
		  i++;
		  }
		  }*/
	}
	return (0);
}
