#include "fillit.h"
#include "libft.h" /*DEBUG*/

void	ft_add_trio(t_trio t, char ***pa_sq, t_pt p)
{
	int	i;

	i = 0;
	pa_sq[0][p.y][p.x] = t.lt;
	while (i < 3)
	{
		pa_sq[0][p.y + t.a_tab[i].y][p.x + t.a_tab[i].x] = t.lt;
		++i;
	}
}
