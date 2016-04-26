/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tperraut <tperraut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 16:22:02 by tperraut          #+#    #+#             */
/*   Updated: 2016/04/26 16:23:05 by tperraut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H

# include <string.h>
# define LIBFTPRINTF_H
# define TRUE 1
# define FALSE 0
# define ABS(X) (X < 0) ? -X : X

size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s1);
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_itoa(int n);
void	ft_putchar(char c);
void	ft_putstr(char const *s);
int		ft_printf(const char *format, ...);

#endif
