#ifndef FILLIT_H
# define FILLIT_H
# define ER -1
# define TRUE 1
# define FALSE 0
# define BUF_SIZE 20

typedef struct	s_pt
{
	int	x;
	int	y;
}				t_pt;
typedef struct	s_trio
{
	t_pt	a_tab[3];
	int		h;
	int		v;
}				t_trio;

int		ft_parser(int fd, t_trio **pa_trio);
#endif
