#include "fillit.h"

void	ft_add_trio(t_trio t, char ***pa_sq, t_pt p, char c)
{
	int	i;

	i = 0;
	pa_sq[0][p.x][p.y] = c;
	while (i < 3)
		pa_sq[0][p.x + t.a_tab[i].x][p.y + t.a_tab[i].x] = c;
}
