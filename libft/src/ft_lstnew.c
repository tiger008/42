/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tperraut <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/08 10:59:31 by tperraut          #+#    #+#             */
/*   Updated: 2016/05/24 03:04:50 by tperraut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list			*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*list;
	char	*save;
	void	*new_content;

	if (!(list = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	if (!(save = (char *)malloc(sizeof(char) * content_size)))
		return (NULL);
	if (content)
	{
		new_content = (void *)ft_strncpy(save, (char *)content, content_size);
		list->content = new_content;
		list->content_size = content_size;
	}
	else
	{
		list->content = NULL;
		list->content_size = 0;
	}
	list->next = NULL;
	return (list);
}
