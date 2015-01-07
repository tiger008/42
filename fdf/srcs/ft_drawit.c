/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_drawit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tperraut <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/07 11:59:01 by tperraut          #+#    #+#             */
/*   Updated: 2015/01/07 15:59:05 by tperraut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point	*ft_create_point(int width, int height, char **split_line)
{
	t_point	*point;

	if(!(point = (t_point *)malloc(sizeof(t_point))))
		return (NULL);
	point->x = width;
	point->y = height;
	point->z = ft_atoi(split_line[width]);
	return (t_point);
}

t_grid	*ft_add_point(t_grid *grid, t_point *point)
{
	t_grid	*tmp;

	tmp = (t_grid *)malloc(sizeof(t_grid));
	if (tmp)
	{
		tmp->point = point;
		tmp->next = grid;
	}
	return (tmp);
}

int		ft_make_grid(char *line, int height, t_grid *grid)
{
	char	**split_line;
	int		width;

	width = 0;
	if(!(split_line = ft_strsplit(line, " ")))
	{
		perror("ft_make_grid");
		exit;
	}
	while (split_line[width])
	{
		grid = ft_add_point(grid, ft_create_point(width, height, split_line));
		width++;
	}
}

int		ft_drawit(int fd)
{
	char	*line;
	int		height;
	int		width;
	t_grid	*grid;

	height = 0;
	*line = NULL;
	while (get_next_line(fd, line))
	{
		width = ft_make_grid(line, height, grid)
		height++;
	}
	return(0);
}
