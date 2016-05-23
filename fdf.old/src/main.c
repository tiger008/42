/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tperraut <tperraut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/06 23:04:21 by tperraut          #+#    #+#             */
/*   Updated: 2016/03/22 14:56:09 by tperraut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"

#include <sys/stat.h>
#include <fcntl.h>
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
	return (p_init(p.y, p.x));
}

void	add_pt(t_pt p, t_iimg *img)
{
	unsigned char	*pixel;

	if ((p.x > WIN_X) || (p.y > WIN_Y))
		return ;
	pixel = (unsigned char *)img->data + (p.y * img->sizeline
		+ (img->bpp/8) * p.x);
			pixel[2] = (((WIN_X - p.x) % (2 * WIN_X))/(WIN_X/100))*(255/100);
			pixel[1] = ((p.y % (2 * WIN_Y))/(WIN_Y/100))*(255/100);
			pixel[0] = (((2 * WIN_X + p.x) % WIN_X)/(WIN_X/100))*(255/100);
}
void	p_echo(t_pt p)
{
	ft_putnbr(p.x);
	ft_putchar(' ');
	ft_putnbr(p.y);
	ft_putendl("");
}
void	draw_line(t_pt p1, t_pt p2, t_iimg *img, int x)
{
	t_pt		p;

	if (p2.x - p1.x < 0)
		return(draw_line(p2, p1, img, x));
	else if ((ABS((p2.y - p1.y))) > (ABS((p2.x - p1.x))))
		return(draw_line(p_inv(p1), p_inv(p2), img, 1));
	else
	{
		p = p_init(p1.x, p1.y);
		while (p.x <= p2.x)
		{
			(x == 0) ? add_pt(p, img) : add_pt(p_inv(p), img);
			p.y = p1.y + ((p2.y - p1.y) * (p.x - p1.x)) / ((p2.x - p1.x == 0) ? 1 : p2.x - p1.x);
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
			pixel = (unsigned char *)img->data + y * img->sizeline
				+ (img->bpp/8) * x;
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

t_pt	iso(int x, int y, int z)
{
	return(p_init(ABS(((CST1 * x - CST2 * y) + 170)),
				ABS(((-z/12 + (CST1 / 2) * x + (CST2 / 2) * y) + 170))));
}

t_pt	p_delta(t_pt p)
{
	return (p_init(p.x * DELTA, p.y * DELTA));
}

void	draw_grid(t_grid *grid, t_iimg *img)
{
	int	i;
	int	j;
	t_pt p;
	t_pt right;
	t_pt down;
	t_pt first;

	j = -1;
	p = iso(0, 0, grid->tab[0]);
	while (++j < grid->li)
	{
		i = -1;
		while (++i < grid->co)
		{
			/*
			 * right = p_init((i + 1) * DELTA, j * DELTA);
			 * down = p_init(i * DELTA, (j + 1) * DELTA);
			*/
			right = (((i + 1) == grid->co) ?  p_init(-1, -1)
				: iso((i + 1) * DELTA, j * DELTA,
					grid->tab[i + 1  + (grid->co * j)] * DELTA));
			down = (((j + 1) == grid->li) ?  p_init(-1, -1)
				: iso(i * DELTA, (j + 1) * DELTA,
					grid->tab[i + (grid->co * (j + 1))] * DELTA));
			if (down.x != -1)
				draw_line(p, down, img, 0);
			if (right.x != -1)
				draw_line(p, right, img, 0);
			if (i == 0)
				first = down;
			p = right;
		}
	p = first;
	}
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
			//draw_bg(&img);
			/*
			   draw_line(p_init(100, 100), p_init(200, 100), &img, 0);
			   draw_line(p_init(200, 100), p_init(200, 200), &img, 0);
			   draw_line(p_init(200, 200), p_init(100, 200), &img, 0);
			   draw_line(p_init(100, 200), p_init(100, 100), &img, 0);
			   */
			//draw_line(p_init(0, 639), p_init(479, 0), &img, 0);
			draw_grid(&grid, &img);
			mlx_expose_hook(env.win, &ft_expose, &env);
			mlx_loop(env.mlx);
		}

		/*else
		  {
		  i = 0;
		  m 3 contexts (suppressed: 0 from 0)
		  [tiger@archtoshi] ~/42semestre01/fdf $ make
		  make: Nothing to be done for 'all'
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
