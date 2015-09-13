#include "libft.h"

void	ft_strstrdel(char ***a)
{
	if (a == NULL)
		return;
	while (*a)
	{
		free(**a);
		*a = NULL;
		(*a)++;
	}
}
