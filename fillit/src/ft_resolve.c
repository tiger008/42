#include "fillit.h"

char		**ft_resolve(t_trio *a_t, int size)
{
	int		sq_size;
	char	**a_sq;

	sq_size = ft_sqrt(size * 4);
	if (sq_size * sq_size < size * 4)
		++sq_size;
	a_sq = ft_create_mat(sq_size);
}
