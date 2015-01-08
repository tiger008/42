/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tperraut <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/07 10:50:12 by tperraut          #+#    #+#             */
/*   Updated: 2015/01/08 13:17:57 by tperraut         ###   ########.fr       */
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
	t_grid	*left;
	t_grid	*up;
}
typedef	struct	s_env
{
	void	*mlx;
	void	*win;
}				t_env;
t_point	*ft_create_point(int x, int y, int z);
t_grid	*ft_add_left(t_grid *grid, t_point *point);
#endif
