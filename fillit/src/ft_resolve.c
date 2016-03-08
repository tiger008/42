#include "fillit.h"

#include <stdlib.h>

char		**ft_resolve(t_trio *a_t, int size, int *sq_size)
{
	char	**a_sq;
	e_tr	test;
	int		i;
	t_pt	pt;
	t_pt	a_ref[size];

	ft_pset(&pt, 0, 0);
	i = 0;
	if ((a_sq = ft_create_mat(*sq_size)) == NULL)
		return (NULL);
	while (i < size)
	{
		if ((test = ft_accept(a_t[i], a_sq, pt, *sq_size)) == ACCEPT)
		{
			ft_add_trio(a_t[i], &a_sq, pt);
			a_ref[i] = pt;
			ft_pset(&pt, 0, 0);
			++i;
		}
		else if (test == CONFLICT || test == DOWN_X)
			++pt.x;
		else if (test == UP_X || test == DOWN_Y)
			ft_pset(&pt, 0, pt.y + 1);
		else if (test == UP_Y)
		{
			--i;
			if (i < 0)
			{
				i = 0;
				ft_free_mat(&a_sq, ++*sq_size);
				a_sq = ft_create_mat(*sq_size);
			ft_pset(&pt, 0, 0);
			ft_pset(&pt, 0, 0);
			}
			else
			{
				ft_remove_trio(a_t[i], &a_sq, a_ref[i]);
				ft_pset(&pt, a_ref[i].x + 1, a_ref[i].y);
			}
		}
	}
	return (a_sq);
}
