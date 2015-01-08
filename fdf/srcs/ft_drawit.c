/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_drawit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tperraut <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/07 11:59:01 by tperraut          #+#    #+#             */
/*   Updated: 2015/01/08 13:17:54 by tperraut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"

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
		grid = ft_add_point(grid, ft_create_point(width, height,
					ft_atoi(split_line[width])));
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
