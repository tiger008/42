#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include "fillit.h"

int		ft_parser(int fd, t_trio **p_a_trio)
{
	char	buf[BUF_SIZE + 1];
	ssize_t	rd;
	short	len;

	len = 0;
	rd = 1;
	while (rd && (rd = read(fd, buf, BUF_SIZE)))
	{
		if (rd != BUF_SIZE)
			return (ER);
		buf[rd] = '\0';
		(*pa_trio + len) = ft_new_trio(buf);
		++len;
	}
	return (0);
}
