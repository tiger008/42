/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tperraut <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 11:54:41 by tperraut          #+#    #+#             */
/*   Updated: 2016/02/23 20:47:26 by tperraut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# define BUF_SIZE 20
# define ER -1
# define MAX_TRIO 26

typedef struct	s_pt
{
	int	x;
	int	y;
}				t_pt;

typedef struct	s_trio
{
	t_pt	a_tab[3];
}				t_trio;

int				parser(int fd, t_trio **pa_trio);
void			ft_pset(t_pt *p, int x, int y);
void			ft_putpt(t_pt p);
#endif
