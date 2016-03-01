#include "libft.h"

void	ft_affiche(char **sq)
{
	int	i;

	i = 0;
	while (sq[i])
		ft_putendl(sq[i++]);
}
