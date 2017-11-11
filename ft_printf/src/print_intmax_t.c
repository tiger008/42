
#include "libftprintf.h"

static intmax_t	get_base(t_specs *specs)
{
	if (GET_BYTE(specs->type, X_TYPE) || GET_BYTE(specs->type, UX_TYPE))
		return (16);
	if (GET_BYTE(specs->type, O_TYPE))
		return (8);
	if (GET_BYTE(specs->type, B_TYPE))
		return (2);
	return (10);
}

void			print_intmax_t(uintmax_t n, t_specs *specs, t_buffer *b)
{
	char		*alpha_16;
	uintmax_t	div;
	uintmax_t	base;
	uintmax_t	i;

	base = (uintmax_t) get_base(specs);
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
