/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoppin <tcoppin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 14:19:45 by tcoppin           #+#    #+#             */
/*   Updated: 2014/11/08 14:52:45 by tcoppin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*tmp;

	tmp = (char *)s + ft_strlen(s);
	while (*tmp != c)
	{
		if (tmp == s)
			return (NULL);
		tmp--;
	}
	return (tmp);
}
