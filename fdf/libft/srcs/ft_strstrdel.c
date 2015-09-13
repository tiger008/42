#include "libft.h"

void	ft_strstrdel(char **a)
{
	int	i;

	i = 0;
	if (a == NULL)
		return;
	while (a[i])
	{
		free(a[i]);
		i++;
	}
	free(a);
}
