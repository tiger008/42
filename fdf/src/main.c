/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tperraut <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/24 02:28:29 by tperraut          #+#    #+#             */
/*   Updated: 2016/05/24 05:07:45 by tperraut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#include <fcntl.h>

int	main(int ac, char **av)
{
	int		op;
	t_map	*map;

	IF_ERROR(ac != 2, "Bad args");
	IF_ERROR((op = open(av[1], O_RDONLY)) < 0, "open() fail");
	map = parser(op);
	print_map(*map);
	return (0);
}
