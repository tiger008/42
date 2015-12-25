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

int	main(int argc, char **argv)
{
	short	*t;
	short	tt[9] = I;
	short	i;
	int		fd;

	if (argc == 2 && (fd = open(argv[1], O_RDONLY)) != -1)
	{
		t = (short *)malloc(sizeof(short) * 114);
		i = 0;
		if (parser(fd, &t) != -1)
		{
			while (t[i])
			{
				if (!(t[i] = ft_trio(t[i])))
				{
					ft_putendl("error");
					break;
				}
				i++;
			}
		}
		else
			ft_putendl("error");
		free(t);
		close(fd);
	}
	return (0);
}
