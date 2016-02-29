#include "fillit.h"

#include <stdlib.h>

char	**ft_create_mat(int n)
{
	char	**a;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if ((a = (char **)malloc(sizeof(char *) * n + 1)) == NULL)
		return (NULL);
	while (i < n)
	{
		if ((a[i] = (char *)malloc(sizeof(char) * n + 1)) == NULL)
		{
			ft_free_mat(&a, j);
			return (NULL);
		}
		a[i][n] = '\0';
		++j;
		++i;
	}
	a[n] = NULL;
	return (a);
}
