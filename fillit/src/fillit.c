/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tperraut <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 00:42:06 by tperraut          #+#    #+#             */
/*   Updated: 2015/11/29 04:53:41 by tperraut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int	main(void)
{
	short	*t;
	short	i;
	int		fd;

	fd = open("test", O_RDONLY);
	t = (short *)malloc(sizeof(short) * 27);
	i = 0;
	if (parser(fd, &t) != -1)
	{
		while (t[i])
		{
			ft_putnbr((int)*t);
			ft_putendl("");
			i++;
		}
	}
	else
		ft_putendl("BAD file");
	close(fd);
	return (0);
}
