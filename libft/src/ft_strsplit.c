/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tperraut <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/15 23:20:19 by tperraut          #+#    #+#             */
/*   Updated: 2014/11/16 00:03:15 by tperraut         ###   ########.fr       */
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

char	**ft_freetab(char ***t, int i)
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
	int		i;
	int		len;
	int		w;

	i = 0;
	w = 0;
	if (s == NULL)
		return (NULL);
	ft_count_word(s, c, &w);
	if ((t = (char **)malloc(sizeof(char *) * (w + 1))) == NULL)
		return (NULL);
	while (i < w)
	{
		while (*s != '\0' && *s == c)
			s++;
		len = ft_wordlen(s, c);
		if ((t[i] = (char *)malloc(sizeof(char) * (len + 1))) == NULL)
			return (ft_freetab(&t, i));
		t[i] = ft_strncpy(t[i], s, len);
		t[i][len] = '\0';
		while (*s != '\0' && *s != c)
			s++;
		++i;
	}
	t[i] = NULL;
	return (t);
}
