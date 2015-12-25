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

/*
static short	check(char *buf, short i)
{
	short	c;

	if ((c = i - 1) >= 0 && buf[c] == '#')
		return (0);
	if ((c = i - 5) >= 0 && buf[c] == '#')
		return (0);
	if ((c = i + 1) < 19 && buf[c] == '#')
		return (0);
	if ((c = i + 5) < 19 && buf[c] == '#')
		return (0);
	return (1);
}
*/

static short	new_trio(char *buf)
{
	short	res;
	short	i;
	short	imod;
	short	len;

	i = 0;
	len = 0;
	res = 0x0000;
	while (i < BUF_SIZE)
	{
		imod = i % 5;
		if ((imod == 4 && buf[i] != '\n')
				|| (imod != 4 && buf[i] != '.' && buf[i] != '#'))
			return (ERR);
		if (buf[i] == '#')
		{
			/*
			if(check(buf, i))
				return (ERR);
			*/
			++len;
			res |= (1 << (i - i/5));
		}
		++i;
	}
	if (len != 4)
		return (ERR);
	return (res);
}

short		parser(int fd, short **tr)
{
	char	buf[BUF_SIZE + 1];
	ssize_t	rd;
	short	len;

	len = 0;
	rd = 1;
	while (rd && (rd = read(fd, buf, BUF_SIZE)))
	{
		if (rd != BUF_SIZE)
			return (ERR);
		buf[rd] = '\0';
		tr[0][len] = new_trio(buf);
		if (tr[0][len] == ERR || (rd = read(fd, buf, 1)) == ERR
				|| (rd && buf[0] != '\n'))
			return (ERR);
		++len;
	}
	tr[0][len] = 0;
	return (len);
}
