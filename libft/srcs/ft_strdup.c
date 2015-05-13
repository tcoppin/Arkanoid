/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoppin <tcoppin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/03 22:44:19 by tcoppin           #+#    #+#             */
/*   Updated: 2015/05/03 22:53:19 by tcoppin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strdup(char const *s1)
{
	char	*str;
	int		i;

	if (s1)
	{
		str = ft_strnew(ft_strlen(s1) + 1);
		if (str)
		{
			i = 0;
			while (s1[i])
			{
				str[i] = s1[i];
				i++;
			}
			return (str);
		}
	}
	return (NULL);
}
