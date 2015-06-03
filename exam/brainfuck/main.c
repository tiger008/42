/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/03 09:27:11 by exam              #+#    #+#             */
/*   Updated: 2015/06/03 16:09:54 by tperraut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "brainfuck.h"
#include <unistd.h>
#include <stdlib.h>

char	*ft_bzero(int size)
{
	char	*result;

	if (!(result = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	result[size] = '\0';
	while (size--)
		result[size] = '\0';
	return (result);
}

void	ft_begin(int t, int **p, char **av, int **i)
{
	(**p)++;
	while (av[1][**i] && t != **p)
	{
		(**i)++;
		if (av[1][**i] == ']')
			(**p)--;
		if (av[1][**i] == '[')
			(**p)++;
	}
	return ;
}

void	ft_end(int t, int **p, char **av, int **i)
{
	(**p)--;
	while (av[1][**i] && t != **p)
	{
		(**i)--;
		if (av[1][**i] == '[')
			(**p)++;
		if (av[1][**i] == ']')
			(**p)--;
	}
	(**i)--;
	return ;
}

int		ft_rbf(char **t, char **av, int *i, int *p)
{
	int	temp;

	if (av[1][*i] == '\0')
		return (0);
	temp = *p;
	if (av[1][*i] == '+')
		(**t)++;
	if (av[1][*i] == '-')
		(**t)--;
	if (av[1][*i] == '<')
		(*t)--;
	if (av[1][*i] == '>')
		(*t)++;
	if (av[1][*i] == '.')
		write (1, *t, 1);
	if (av[1][*i] == '[' && **t == '\0')
		ft_begin(temp, &p, av, &i);
	if (av[1][*i] == ']' && **t != '\0')
		ft_end(temp, &p, av, &i);
	if (av[1][*i] == '[')
		(*p)++;
	if (av[1][*i] == ']')
		(*p)--;
	(*i)++;
	return (ft_rbf(t, av, i, p));
}

int		main(int ac, char **av)
{
	char	*t;
	int		i;
	int		p;

	i = 0;
	p = 0;
	t = ft_bzero(MAX);
	if (ac == 2 && t)
		return (ft_rbf(&t, av, &i, &p));
	else
		write(1, "\n", 1);
	return (0);
}
