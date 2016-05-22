/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tperraut <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/08 12:15:43 by tperraut          #+#    #+#             */
/*   Updated: 2016/05/17 15:55:31 by tperraut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_lstdelone(t_list **alst, void (*del)(void *, size_t))
{
	if (!alst || !*alst)
		return ;
	if (!del)
	{
		*alst = NULL;
		return ;
	}
	del((**alst).content, (**alst).content_size);
	free(*alst);
	*alst = NULL;
}
