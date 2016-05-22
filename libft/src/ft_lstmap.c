/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tperraut <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/08 14:19:38 by tperraut          #+#    #+#             */
/*   Updated: 2016/05/17 14:23:21 by tperraut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*actual;

	if (!lst || !f)
		return (NULL);
	if (!(new = f(lst)))
		return (NULL);
	actual = new;
	lst = lst->next;
	while (lst->next)
	{
		if (!(actual->next = f(lst)))
			return (NULL);
		actual = actual->next;
		lst = lst->next;
	}
	if (!(actual->next = f(lst)))
		return (NULL);
	return (new);
}
