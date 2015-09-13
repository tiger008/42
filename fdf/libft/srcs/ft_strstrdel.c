#include "libft.h"

void	ft_strstrdel(char ***a)
{
	if (a == NULL)
		return;
	while (*a != NULL)
	{
		free(**a);
		(*a)++;
	}
	free(a);
}
