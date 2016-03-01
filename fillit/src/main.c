/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tperraut <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 11:56:26 by tperraut          #+#    #+#             */
/*   Updated: 2016/02/23 17:11:38 by tperraut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

#include <fcntl.h>

/*
**TODO
**ft_resolve
*/

int		main(int argc, char **argv)
{
	int		fd;
	int		len;
	t_trio	*a_trio;

	if (argc == 2)
	{
		if ((fd = open(argv[1], O_RDONLY)) != ER)
		{
			if ((len = parser(fd, &a_trio)) == ER || len == 0)
				ft_putendl("error");
			else
				ft_affiche(ft_resolve(a_trio, len));
		}
		else
			ft_putendl("error");
	}
	else
		ft_putendl("usage: ./fillit file");
	return (0);
}
