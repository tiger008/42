#include "fillit.h"

int	ft_next_perm(t_trio **pa_t, int len)
{
	int		i;
	int		j;
	t_trio	tmp;

	i = len - 1;
	while (i > 0 && pa_t[0][i - 1].lt >= pa_t[0][i - 1].lt)
		--i;
	if (i == 0)
		return (0);
	j = len - i;
	while (pa_t[0][j].lt <= pa_t[0][i - 1].lt)
		--j;
	tmp = pa_t[0][i - 1];
	pa_t[0][i - 1] = pa_t[0][j];
	pa_t[0][j] = tmp;
	j = len - 1;
	while (i < j)
	{
		tmp = pa_t[0][i];
		pa_t[0][i] = pa_t[0][j];
		pa_t[0][j] = tmp;
		++i;
		--j;
	}
	return (1);
}
