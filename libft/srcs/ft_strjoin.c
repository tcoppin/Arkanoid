/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoppin <tcoppin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/14 15:34:17 by tcoppin           #+#    #+#             */
/*   Updated: 2015/05/03 22:54:41 by tcoppin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strjoin(char const *s1, char const *s2)
{
	char			*new;

	if (s1 && s2)
	{
		new = ft_strnew(ft_strlen(s1) + ft_strlen(s2) + 1);
		if (new)
		{
			new = ft_strcat(new, s1);
			new = ft_strcat(new, s2);
			return (new);
		}
	}
	else if (s1)
		return (ft_strdup(s1));
	else if (s2)
		return (ft_strdup(s2));
	return (NULL);
}
