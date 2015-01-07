/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tperraut <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/07 10:50:12 by tperraut          #+#    #+#             */
/*   Updated: 2015/01/07 14:53:23 by tperraut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
int		ft_drawit(int fd);
typedef	struct	s_point
{
	int	*x;
	int	*y;
	int	*z;
}				t_point;
typedef	struct	s_grid	t_grid;
typedef	struct	s_grid
{
	t_point	point;
	t_grid	*next;
}
typedef	struct	s_env
{
	void	*mlx;
	void	*win;
}				t_env;
#endif
