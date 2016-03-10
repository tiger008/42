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
/*# define UP_X -1
# define UP_Y -2
# define DOWN_X -3
# define DOWN_Y -4
# define CONFLICT 0
# define ACCEPT 1
*/

typedef enum	e_tr
{
	ACCEPT, CONFLICT, UP_X, UP_Y, DOWN_X, DOWN_Y
}				e_tr;

typedef struct	s_pt
{
	int	x;
	int	y;
}				t_pt;

typedef struct	s_trio
{
	t_pt	a_tab[3];
	char	lt;
}				t_trio;

int				parser(int fd, t_trio **pa_trio);
void			ft_pset(t_pt *p, int x, int y);
void			ft_putpt(t_pt p);
int				ft_sqrt(int n);
char			**ft_create_mat(int n);
void			ft_free_mat(char ***a, int n);
void			ft_remove_trio(t_trio t, char ***pa_sq, t_pt p);
void			ft_add_trio(t_trio t, char ***pa_sq, t_pt p);
void			ft_affiche(char **sq);
char			**ft_resolve(t_trio *a_t, int size, int *sq_size, int i);
int				ft_next_perm(t_trio **pa_t, int len);
e_tr			ft_accept(t_trio t, char **a_sq, t_pt pt, int sq_size);

#endif
