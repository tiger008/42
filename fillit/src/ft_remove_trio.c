#include "fillit.h"

void	ft_remove_trio(t_trio t, char ***pa_sq, t_pt p)
{
	int	i;

	i = 0;
	pa_sq[0][p.y][p.x] = '.';
	while (i < 3)
	{
		pa_sq[0][t.a_tab[i].y + p.y][t.a_tab[i].x + p.x] = '.';
		++i;
	}
}