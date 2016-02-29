#include "libft.h"

int	ft_sqrt(int n)
{
	int	sq;
	int	tmp;

	tmp = 1;
	sq = (int)(0.5 * (1 + n));
	while (ft_abs(sq - tmp) > 0)
	{
		tmp = sq;
		sq = (int)(0.5 * (tmp + n / tmp));
	}
	return (sq);
}
