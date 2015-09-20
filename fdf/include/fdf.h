/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tperraut <tperraut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/07 10:50:12 by tperraut          #+#    #+#             */
/*   Updated: 2015/04/09 11:37:32 by tperraut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define ERROR -1
# define WIN_X 480
# define WIN_Y 640
# define RED 0x33
# define GREEN 0x33
# define BLUE 0xFF
# define CST1 0.7
# define CST2 0.7
# define DELTA 20

typedef struct	s_pt
{
	int		x;
	int		y;
}		t_pt;

typedef struct	s_iimg
{
	char	*data;
	int		bpp;
	int		sizeline;
	int		endian;
}		t_iimg;

typedef	struct	s_env
{
	void	*mlx;
	void	*win;
	void	*img;
}				t_env;
typedef	struct	s_grid
{
	int	*tab;
	int	li;
	int	co;
}				t_grid;
int		ft_parser(int fd, t_grid *grid);
void	ft_initgrid(t_grid *grid);
#endif
