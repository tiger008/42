/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tperraut <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/23 19:02:47 by tperraut          #+#    #+#             */
/*   Updated: 2016/05/24 06:58:46 by tperraut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "get_next_line.h"
#include "libft.h"

#include <stdio.h> /* DEBUG */

static int		tablen(char **t)
{
	int	len;

	len = 0;
	IF_RETURN(!t, len);
	while (t[len])
		len++;
	return (len);
}

static int		*tabmap(char **t, int size, int (*f)(const char *s))
{
	int		*tab;
	int		i;

	IF_ERROR(!t || !f || !(tab = (int *)malloc(sizeof(int) * size)),
			"tabmap() fail");
	i = 0;
	while (i < size)
	{
		tab[i] = (*f)(t[i]);
		i++;
	}
	return (tab);
}

static void		set_list(t_list **alst, char **split, int size, int co)
{
	t_list	*tmp;
	int		*tab;

	tab = tabmap(split, size, &ft_atoi);
	tmp = ft_lstnew((void const *)tab, sizeof(int) * size);
	free(tab);
	IF_ERROR(!tmp, "set_list() fail");
	IF_ERROR(co != size, "map error");
	ft_lstadd(alst, tmp);
}

static int		**list_to_tab(t_list **alst, int size)
{
	int		**tab;
	t_list	*tmp;

	tab = (int **)malloc(sizeof(int *) * size);
	IF_ERROR(!tab, "list_to_tab() fail");
	tmp = *alst;
	while(tmp)
	{
		tab[--size] = (int *)tmp->content;
		tmp = tmp->next;
	}
	ft_lstdel(alst, NULL);
	return (tab);
}

t_map			*parser(int fd)
{
	int		rd;
	char	*line;
	char	**split;
	t_list	*tmp;
	t_map	*map;

	line = NULL;
	IF_ERROR((rd = get_next_line(fd, &line)) < 1, "parser() error");
	IF_ERROR(!(split = ft_strsplit(line, ' ')), "ft_strsplit() fail");
	init_map(&map, tablen(split));
	tmp = ft_lstnew((void *)tabmap(split, map->co, ft_atoi),
			sizeof(int) * map->co);
	ft_delsplit(&split);
	free(line);
	while ((rd = get_next_line(fd, &line)) > 0)
	{
		IF_ERROR(!(split = ft_strsplit(line, ' ')), "ft_strsplit() fail");
		set_list(&tmp, split, tablen(split), map->co);
		ft_delsplit(&split);
		free(line);
		map->li++;
	}
	map->tab = list_to_tab(&tmp, map->li);
	IF_ERROR(rd < 0, "get_next_line() fail");
	return (map);
}
