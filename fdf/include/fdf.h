/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tperraut <tperraut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/07 10:50:12 by tperraut          #+#    #+#             */
/*   Updated: 2016/06/03 18:17:55 by tperraut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdlib.h>

# define W_MAX 600
# define H_MAX 400
# define W_IMG W_MAX
# define H_IMG H_MAX
# define WHITE 0xFFFFFF
# define CROSS_MASK (1L<<17)
# define CROSS_V 17
# define ENDIAN 0
# define S_PIXEL 3

typedef struct	s_img
{
	char	*data;
	int		bpp;
	int		sizeline;
	int		endian;
}				t_img;

typedef	struct	s_map
{
	int	**tab;
	int	li;
	int	co;
}				t_map;

typedef	struct	s_env
{
	void	*mlx;
	void	*win;
	void	*img;
	t_img	*img_data;
	t_map	*map;
	int		op;
}				t_env;

/*
** PARSE
*/

t_map			*parser(int fd);
t_img			*new_img_data(void *img);
void			init_map(t_map **map, int co);
void			free_map(t_map **map);

/*
** CHECK
*/

void			error(const char *s);
# define IF_ERROR(x, s) if (x) error(s)

/*
** DEBUG
*/

void			print_map(t_map m);

/*
** DRAW
*/

/*
** EVENT
*/

int				manage_key(int keycode, void *param);
int				manage_mouse(int button,int x,int y, void *param);
int				finish(void *param);
int				draw(void *param);

#endif
