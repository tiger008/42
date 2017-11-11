
#include "libftprintf.h"

static int	get_base(t_specs *specs)
{
	if (GET_BYTE(specs->type, X_TYPE) || GET_BYTE(specs->type, UX_TYPE))
		return (16);
	if (GET_BYTE(specs->type, O_TYPE))
		return (8);
	if (GET_BYTE(specs->type, B_TYPE))
		return (2);
	return (10);
}

void		print_int(unsigned int n, t_specs *specs, t_buffer *b)
{
	char			*alpha_16;
	unsigned int	div;
	unsigned int	base;
	unsigned int	i;

	base = (unsigned int) get_base(specs);
	alpha_16 = (GET_BYTE(specs->type, X_TYPE)) ? ALPHA_16 : UALPHA_16;
	i = n;
	div = 1;
	if (GET_BYTE(specs->type, SIGN))
		b->add('-', b);
	while (i >= base)
	{
		div *= base;
		i /= base;
	}
	while (div)
	{
		b->add(alpha_16[(n / div) % base], b);
		div /= base;
	}
}
