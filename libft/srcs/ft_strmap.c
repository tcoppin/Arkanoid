/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoppin <tcoppin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/09 22:05:44 by tcoppin           #+#    #+#             */
/*   Updated: 2014/11/09 23:44:33 by tcoppin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*tmp;

	i = 0;
	if (s != 0 && (*f) != 0)
	{
		tmp = (char*)malloc(ft_strlen(s) + 1);
		while (s[i] != '\0')
		{
			tmp[i] = (*f)(s[i]);
			i++;
		}
		return (tmp);
	}
	return (0);
}
