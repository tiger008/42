/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   infin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/29 11:54:05 by exam              #+#    #+#             */
/*   Updated: 2015/05/29 15:54:20 by tperraut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

static int	ft_strlen(char *s)
{
	int	len;

	len = 0;
	while (s[len])
		len++;
	return ((len == 1 && s[0] == '0') ? 0 : len);
}

static int	**ft_init(int len1, int len2)
{
	int	**result;
	int	i;

	result = (int **)malloc(sizeof(int *) * (len1 + 1));
	i = -1;
	if (result != NULL)
	{
		while (++i < len1)
			result[i] = (int *)malloc(sizeof(int) * len2);
		result[i] = NULL;
	}
	return (result);
}

static int	**ft_strtotab(char *s1, char *s2, int len1, int len2)
{
	int	**result;
	int	i;
	int	j;

	if (!(result = ft_init(len1, len2)))
		return (NULL);
	i = 0;
	while (++i <= len1)
	{
		j = 0;
		while (++j <= len2)
		{
			if (j == 1)
				result[i - 1][j - 1] = (int)((s1[len1 - i] - '0')
						* (s2[len2 - j] - '0'));
			else
			{
				result[i - 1][j - 1] = (int)((s1[len1 - i] - '0')
						* (s2[len2 - j] - '0') + (result[i - 1][j - 2] / 10));
				result[i - 1][j - 2] = result[i][j - 1] % 10;
			}
		}
	}
	return (result);
}

static int	*ft_rinit(int len1, int len2)
{
	int	*r;
	int	i;

	i = 0;
	if (!(r = (int *)malloc(sizeof(int) * (len1 + len2 + 1))))
		return (NULL);
	while (i < len1 + len2 + 1)
		r[i] = 0;
	return (r);
}
void	infin(char **av)
{
	int	**in;
	int	*r;
	int	l12[2];
	int	i;
	int	j;
	int	k;

	j = -1;
	l12[0] = ft_strlen(av[1]);
	l12[1] = ft_strlen(av[2]);
	r = rinit(l12[0], l12[1]);
	if (!l12[0] || !l12[1])
		write(1, "0\n", 2);
	else if (av[1][0] == '-' && av[2][0] == '-')
		in = ft_strtotab(&av[1][1], &av[2][1], --l12[0], --l12[1]);
	else if (av[1][0] == '-'
			&& (in = ft_strtotab(&av[1][1], av[2], --l12[0], l12[1])))
		write(1, "-", 1);
	else if (av[2][0] == '-'
			&& (in = ft_strtotab(av[1], &av[2][1], l12[0], --l12[1])))
		write(1, "-", 1);
	else
		in = ft_strtotab(av[1], av[2], l12[0], l12[1]);
	if (!in || !r)
		return ();
	while (++j < len2)
	{
		k = j + 1;
		i = -1
		while (++i < len1 && --k >= 0)
		{
			if (j = 0)
			r[j * len1 + i] += in[i][j - k] + (r[j * len1 + i - 1]) / 10;
			r[j * len1 + i - 1] = r[j * len1 + i - 1] % 10;
		}
	}
	return ();
}
