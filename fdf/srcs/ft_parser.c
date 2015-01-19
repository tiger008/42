#include "fdf.h"
#include "get_next_line.h"
#include <stdlib.h>
#include "libft.h"

void	ft_freethree(char **one, int **two, int **three)
{
	if (one)
		free(*one);
	if (two)
		free(*two);
	if (three)
		free(*three);
}

int		*ft_strtoint(char *line)
{
	char	**splited;
	int		i;
	int		*result;
	int		len;

	len = 0;
	if(!(splited = ft_strsplit(line, ' ')))
		return (NULL);
	i = -1;
	while (splited[++i])
		len++;
	if(!(result = (int *)malloc(sizeof(int) * (len + 1))))
		return (NULL);
	i = 0;
	while (splited[++i])
		result[i] = ft_atoi(splited[i]);
	result[0] = len;
	return (result);
}

int		*ft_tabjoin(int *tab1, int *tab2, int t1_size, int t2_size)
{
	int	*dest;
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!(dest = (int *)malloc(sizeof(int) * (t1_size + t2_size)))
			|| (!tab1 && !tab2))
		return (NULL);
	if (tab1)
	{
		while (i < t1_size)
			dest[j++] = tab1[i++];
	}
	i = 1;
	if (tab2)
	{
		while (i <= t2_size)
			dest[j++] = tab2[i++];
	}
	return (dest);
}

int		ft_parser(int fd, t_grid *grid)
{
	char	*line;
	int		get;
	int		*temp;
	int		*to_free;

	temp = NULL;
	line = NULL;
	get = 0;
	while ((get = get_next_line(fd, &line)) && get != ERROR)
	{
		if (!(temp = ft_strtoint(line)))
			return (ERROR);
		if (!grid->co)
			grid->co = temp[0];
		else if (grid->co != temp[0])
			return (ERROR);
		to_free = grid->tab;
		if(!(grid->tab = ft_tabjoin(grid->tab, temp,
				grid->co * grid->li, grid->co)))
			return (ERROR);
		ft_freethree(&line, &to_free, &temp);
		grid->li++;
	}
	if (get ==  ERROR)
		return (ERROR);
	return (1);
}
