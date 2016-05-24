/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tperraut <tperraut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/07 10:50:12 by tperraut          #+#    #+#             */
/*   Updated: 2016/05/24 09:48:24 by tperraut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <stdlib.h>
# define WIN_X 640
# define WIN_Y 640
# define RGB 0x3333FF
# define CST1 0.8
# define CST2 0.8
# define DELTA 20

typedef struct	s_pt
{
	int		x;
	int		y;
}				t_pt;

typedef struct	s_iimg
{
	char	*data;
	int		bpp;
	int		sizeline;
	int		endian;
}				t_iimg;

typedef	struct	s_env
{
	void	*mlx;
	void	*win;
	void	*img;
}				t_env;

typedef	struct	s_map
{
	int	**tab;
	int	li;
	int	co;
}				t_map;

/*
** PARSE
*/

t_map	*parser(int fd);
void	init_map(t_map **map, int co);
void	free_mat(t_map **map);

/*
** CHECK
*/

void	error(const char *s);
# define IF_ERROR(x, s) if (x) error(s)

/*
** DEBUG
*/

void	print_map(t_map m);

/*
** DRAW
*/

#endif
