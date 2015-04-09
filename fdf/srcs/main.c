/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tperraut <tperraut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/06 23:04:21 by tperraut          #+#    #+#             */
/*   Updated: 2015/04/07 01:21:13 by tperraut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <sys/stat.h>
#include <fcntl.h>
#include "libft.h"

int		main(int ac, char **av)
{
	t_grid	grid;
	int		op;
	int		i;
	int		j;

	if (ac == 2)
	{
		ft_initgrid(&grid);
		if((op = open(av[1], O_RDONLY)) == -1)
		{
			ft_putendl("Open fail");
			return (0);
		}
		if ((ft_parser(op, &grid)) == -1)
		{
			ft_putendl("Parse Fail");
			return (0);
		}
		i = 0;
		while (i < grid.li)
		{
			j = 0;
			while (j < grid.co)
			{
				ft_putnbr(grid.tab[j + (i * grid.co)]);
				ft_putchar(' ');
				j++;
			}
			ft_putendl("");
			i++;
		}
	}
	while (1)
	{
	}
	return (0);
}