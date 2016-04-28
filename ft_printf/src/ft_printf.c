/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tperraut <tperraut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 23:50:11 by tperraut          #+#    #+#             */
/*   Updated: 2016/04/28 21:32:54 by tperraut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

#include "libftprintf.h"

int	ft_printf(const char *format, ...)
{
	va_list	ap;

	va_start(ap, format);
	return (1);
}
