/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoppin <tcoppin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/03 22:44:19 by tcoppin           #+#    #+#             */
/*   Updated: 2015/05/03 22:50:46 by tcoppin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list			*new;
	t_list			*first;

	if (lst && f)
	{
		new = f(lst);
		if (new)
		{
			first = new;
			while (lst->next)
			{
				lst = lst->next;
				new->next = f(lst);
				new = new->next;
				if (!new)
					return (NULL);
			}
			return (first);
		}
	}
	return (NULL);
}
