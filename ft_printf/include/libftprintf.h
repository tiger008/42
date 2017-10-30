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
# define TRUE 1
# define FALSE 0
# define BUF_SIZE 1024
# define ALPHA_16 "0123456789ABCDEF"
# define A_MAX_ALPHA_16 {"-10000000000000000000000000000000", \
	"-12112122212110202102", \
	"-2000000000000000", \
	"-13344223434043", \
	"-553032005532", \
	"-104134211162", \
	"-20000000000", \
	"-5478773672", \
	"-2147483648", \
	"-A02220282", \
	"-4BB2308A8", \
	"-282BA4AAB", \
	"-1652CA932", \
	"-C87E66B8", \
	"-80000000"}

size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s1);
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_itoabase(int n, int base);
void	ft_putchar(char c);
void	ft_putstr(char const *s);
int		ft_printf(const char *format, ...);

#endif
