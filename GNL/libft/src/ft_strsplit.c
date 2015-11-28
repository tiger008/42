/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tperraut <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/15 23:20:19 by tperraut          #+#    #+#             */
/*   Updated: 2015/11/28 13:03:43 by tperraut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_count_word(const char *s, char c, int *w)
{
	char	boo;

	boo = 1;
	while (*s != '\0')
	{
		if (!boo && *s == c)
			boo = 1;
		else if (boo && *s != c)
		{
			*w += 1;
			boo = 0;
		}
		s++;
	}
}

static int	ft_wordlen(const char *s, char c)
{
	int	len;

	len = 0;
	while (*s != '\0' && *s != c)
	{
		++len;
		s++;
	}
	return (len);
}

char		**ft_freetab(char ***t, int i)
{
	int	j;

	if (t != NULL)
	{
		j = 0;
		while (j < i)
		{
			free(*t[j]);
			++j;
		}
		free(*t);
		*t = NULL;
	}
	return (NULL);
}

char		**ft_strsplit(const char *s, char c)
{
	char	**t;
	int		i[2];
	int		w;

	i[0] = -1;
	w = 0;
	if (s == NULL)
		return (NULL);
	ft_count_word(s, c, &w);
	if ((t = (char **)malloc(sizeof(char *) * (w + 1))) == NULL)
		return (NULL);
	while (++i[0] < w)
	{
		while (*s != '\0' && *s == c)
			s++;
		i[1] = ft_wordlen(s, c);
		if ((t[i[0]] = (char *)malloc(sizeof(char) * (i[1] + 1))) == NULL)
			return (ft_freetab(&t, i[0]));
		t[i[0]] = ft_strncpy(t[i[0]], s, i[1]);
		t[i[0]][i[1]] = '\0';
		while (*s != '\0' && *s != c)
			s++;
	}
	t[i[0]] = NULL;
	return (t);
}
