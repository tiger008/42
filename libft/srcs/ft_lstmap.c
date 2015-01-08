/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tperraut <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/08 14:19:38 by tperraut          #+#    #+#             */
/*   Updated: 2015/01/08 15:22:56 by tperraut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*to_add;

	if (!lst)
		return (NULL);
	if (!(new = ft_lstnew(f(lst)->content, f(lst)->content_size)))
		return (NULL);
	lst = lst->next;
	while (lst->next)
	{
		if (!(to_add = ft_lstnew(f(lst)->content, f(lst)->content_size)))
			return (NULL);
		ft_lstadd(&new, to_add);
	}
	if (!(to_add = ft_lstnew(f(lst)->content, f(lst)->content_size)))
		return (NULL);
	ft_lstadd(&new, to_add);
	return (new);
}
