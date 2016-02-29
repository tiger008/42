#include <stdlib.h>

void	ft_free_mat(char ***a, int n)
{
	int	i;

	i = 0;
	if (a && *a)
	{
		while (i < n)
		{
			free(a[0][i]);
			++i;
		}
		free(*a);
		*a = NULL;
	}
}
