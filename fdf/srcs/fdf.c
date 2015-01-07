/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tperraut <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/07 10:50:50 by tperraut          #+#    #+#             */
/*   Updated: 2015/01/07 13:56:06 by tperraut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int		main(int ac, char **av)
{
	int	fd;

	if (ac < 2)
		write(2, "Give me a file dude !\n", 22);
	else if (ac > 2)
		write(2, "Too much files dude !\n", 22);
	else
	{
		fd = open(av[1], O_RDONLY);
		if (fd == -1)
			perror("Open fail");
		else
		{
			ft_drawit(fd);
			close(fd);
		}
	}
	return (0);
}
