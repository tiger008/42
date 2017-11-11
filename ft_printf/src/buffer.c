#include <unistd.h>
#include "libftprintf.h"

static void	buf_flush(t_buffer *b)
{
	if (!b)
		return;
	write(1, b->data, MIN(b->size, BUF_SIZE));
	b->size = 0;
}

static void	buf_add(char c, t_buffer *b)
{
	if (!b)
		return;
	if (!(b->size < BUF_SIZE))
		b->flush(b);
	b->data[b->size] = c;
	b->size++;
}

void		buf_init(t_buffer *b)
{
	if (!b)
		return;
	b->size = 0;
	b->flush = buf_flush;
	b->add = buf_add;
}
