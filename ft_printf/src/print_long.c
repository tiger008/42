/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_long.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tperraut <tperraut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/11 16:10:05 by tperraut          #+#    #+#             */
/*   Updated: 2016/05/17 18:07:29 by tperraut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static long	get_base(t_specs *specs)
{
	if (GET_BYTE(specs->type, X_TYPE) || GET_BYTE(specs->type, UX_TYPE))
		return (16);
	if (GET_BYTE(specs->type, O_TYPE))
		return (8);
	if (GET_BYTE(specs->type, B_TYPE))
		return (2);
	return (10);
}

void		print_long(unsigned long n, t_specs *specs, t_buffer *b)
{
	char			*alpha_16;
	unsigned long	div;
	unsigned long	base;
	unsigned long	i;

	base = (unsigned long) get_base(specs);
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
