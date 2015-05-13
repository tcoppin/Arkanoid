/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoppin <tcoppin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/03 22:44:19 by tcoppin           #+#    #+#             */
/*   Updated: 2015/05/03 22:50:50 by tcoppin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list		*list;
	void		*content_cpy;

	content_cpy = NULL;
	if (!content)
		content_size = 0;
	else
	{
		content_cpy = ft_memalloc(content_size);
		content_cpy = ft_memcpy(content_cpy, content, content_size);
	}
	list = (t_list *)ft_memalloc(sizeof(t_list));
	if (list)
	{
		list->content = content_cpy;
		list->content_size = content_size;
		list->next = NULL;
		return (list);
	}
	return (NULL);
}
