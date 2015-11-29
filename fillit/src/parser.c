/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tperraut <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 03:13:35 by tperraut          #+#    #+#             */
/*   Updated: 2015/11/29 05:12:04 by tperraut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include "fillit.h"
#include "libft.h"

static	short	new_trio(char *buf)
{
	short	res;
	short	i;
	short	imod;

	i = 0;
	res = 0x0000;
	while (i < BUF_SIZE)
	{
		imod = i % 5;
		if ((imod == 4 && buf[i] != '\n')
				|| (imod != 4 && (buf[i] != '.' || buf[i] != '#')))
			return (ERR);
		if (buf[i] == '#')
			res |= (1 << (i - i/5));
		++i;
	}
	return (res);
}

short		parser(int fd, short **tr)
{
	char	buf[BUF_SIZE + 1];
	ssize_t	rd;
	short	len;

	len = 0;
	rd = 1;
	while ((rd = read(fd, buf, BUF_SIZE)) && rd)
	{
		if (rd != BUF_SIZE)
			return (ERR);
		buf[rd] = '\0';
		*tr[len] = new_trio(buf);
		if ((rd = read(fd, buf, 1)) && (rd == 0 || rd == ERR))
			return (rd);
		if (*tr[len] == -1 || buf[0] != '\n')
			return (ERR);
		++len;
	}
	*tr[len] = 0;
	return (len);
}
