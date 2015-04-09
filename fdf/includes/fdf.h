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

typedef	struct	s_env
{
	void	*mlx;
	void	*win;
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