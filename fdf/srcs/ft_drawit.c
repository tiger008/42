/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_drawit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tperraut <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/07 11:59:01 by tperraut          #+#    #+#             */
/*   Updated: 2015/01/07 14:53:20 by tperraut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_make_grid(line, height)
{
	char	**split_line;

	if(!(split_line = ft_strsplit(line, " ")))
	{
		perror("ft_make_grid");
		exit;
	}
}

int		ft_drawit(int fd)
{
	char	*line;
	int		height;
	int		width;
	t_grid	*grid;

	height = 0;
	width = 0;
	*line = NULL;
	grid = (t_grid *)malloc(sizeof(t_grid));
	while (get_next_line(fd, line))
	{
		width = ft_make_grid(line, height)
		ft_create_point();
		ft_point_to_grid();
		height++;
	}
	return(0);
}
