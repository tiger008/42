#include "libftprintf.h"
#include <stdlib.h>
#include <stdio.h> //DEBUG

/*
t_flag	flag_mode(char **format, t_buffer *b, va_list ap)
{
	t_flag	flag;

	flag = NULL;
	if (format && b && ap)
		return(NULL);
	return (flag);
}
*/

void	switch_mode(char **format, t_buffer *b, va_list ap)
{
	t_specs	specs;

	//TODO Pointeur sur fonction avec les char correspondant
	if (!format || !b || !ap)
		return;
	(*format)++;
	if (**format == '%')
	{
		b->add('%', b);
		(*format)++;
	}
	if (**format == 'd')
	{
		specs.preci = 1;
		specs.width = 1;
		specs.type = D_TYPE;
		INIT(int, d, va_arg(ap, int));
		SET_BYTE(specs.type, (d < 0) ? SIGN : FALSE);
		print_int((unsigned int) ABS(d), &specs, b);
		(*format)++;
	}
}
