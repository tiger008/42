/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tperraut <tperraut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 16:22:02 by tperraut          #+#    #+#             */
/*   Updated: 2016/05/17 11:10:34 by tperraut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H

# define LIBFTPRINTF_H
# include <string.h>
# include <stdarg.h>
# include <stdint.h>
# define TRUE 1
# define FALSE 0
# define ABS(X) (X < 0) ? -X : X
# define MIN(X, Y) (X > Y) ? Y : X
# define INIT(Type, Var, Value) Type Var = Value
# define BUF_SIZE 1024
# define UALPHA_16 "0123456789ABCDEF"
# define ALPHA_16 "0123456789abcdef"
# define L_FLAG 0x0001
# define LL_FLAG 0x0002
# define H_FLAG 0x0004
# define HH_FLAG 0x0008
# define J_FLAG 0x0010
# define Z_FLAG 0x0020
# define D_TYPE 0x0040
# define I_TYPE 0x0080
# define O_TYPE 0x0100
# define U_TYPE 0x0200
# define X_TYPE 0x0400
/* X (upper case) type option */
# define UX_TYPE 0x0800
/* BONUS : Binary type */
# define B_TYPE 0x1000
# define SIGN 0x8000
# define IS_SIGN(Num) (Num & SIGN) ? TRUE : FALSE
# define SET_BYTE(Num, Mask) Num |= Mask
# define GET_BYTE(Num, Mask) (Num & Mask) ? TRUE : FALSE

typedef struct	s_buffer
{
	char	data[BUF_SIZE];
	int		size;
	void	(*add)(char c, struct s_buffer *b);
	void	(*flush)(struct s_buffer *b);
}				t_buffer;

/*
** preci : precision asked
** width : number length
** type : 1 byte for the sign, 9 bytes for the type and 6 bytes for the options
*/

typedef struct	s_specs
{
	int		preci;
	int		width;
	short	type;
}				t_specs;

int		ft_printf(const char *format, ...);
void	print_char(unsigned char n, t_specs *specs, t_buffer *b);
void	print_short(unsigned short n, t_specs *specs, t_buffer *b);
void	print_int(unsigned int n, t_specs *specs, t_buffer *b);
void	print_long(unsigned long n, t_specs *specs, t_buffer *b);
void	print_llong(unsigned long long n, t_specs *specs, t_buffer *b);
void	print_intmax_t(uintmax_t n, t_specs *specs, t_buffer *b);
void	print_size_t(size_t n, t_specs *specs, t_buffer *b);
//void	print_str(char *s, t_specs *specs, t_buffer *b);
//void	print_wstr(wchar_t *s, t_specs *specs, t_buffer *b);
void	buf_init(t_buffer *b);
void	switch_mode(char **format, t_buffer *b, va_list ap);

#endif
