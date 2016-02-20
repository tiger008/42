#include <unistd.h>
#include <stdlib.h>
#include "fillit.h"

static int	*init_tab(int size, int x)
{
	int	i;
	int	*a_tab;

	i = 0;
	if ((a_tab = (int *)malloc(sizeof(int) * size)) == NULL)
		return (NULL);
	while (i < size)
		a_tab[i] = x;
	return (a_tab);
}
/*TODO : split init_trio, made first # the origin*/
static int	init_trio(char *buf, t_trio *trio)
{
	int	len;
	int	i;
	int	end_line;
	int	*a_fxy;

	a_fxy = init_tab(3, 0);
	i = 0;
	len = 0;
	while (i < BUF_SIZE)
	{
		end_line = i % 5;
		if (len > 3 || a_fxy == NULL || (end_line == 4 && buf[i] != '\n')
				|| (end_line != 4 && buf[i] != '.' && buf[i] != '#'))
			return (ER);
		if (a_fxy[0])
		{
			if (buf[i] == '\n' && ++a_fxy[2])
				a_fxy[1] = 0;
			else if (buf[i] == '#')
			{
				trio->a_tab[len].x = a_fxy[1];
				trio->a_tab[len].y = a_fxy[2];
				++len;
			}
			else
				++a_fxy[1];
		}
		if (!a_fxy[0] && buf[i] == '#')
			a_fxy[0] = TRUE;
		++i;
	}
	free(a_fxy);
	return (len);
}

int			ft_parser(int fd, t_trio **pa_trio)
{
	char	buf[BUF_SIZE + 1];
	ssize_t	rd;
	short	len;

	len = 0;
	rd = 1;
	while (rd && (rd = read(fd, buf, BUF_SIZE)))
	{
		if (rd != BUF_SIZE || len > MAX_TRIO)
			return (ER);
		buf[rd] = '\0';
		if (init_trio(buf, &((*pa_trio)[len])) == ER
				|| (rd = read(fd, buf, 1)) == ER
				|| (rd && buf[0] != '\n'))
			return (ER);
		++len;
	}
	return (len);
}
