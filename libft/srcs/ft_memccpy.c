/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoppin <tcoppin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/03 22:44:19 by tcoppin           #+#    #+#             */
/*   Updated: 2015/05/03 22:51:08 by tcoppin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char		*s1;
	const char	*s2;

	s1 = dst;
	s2 = src;
	while (n-- != 0)
	{
		if (*s2 == c)
		{
			*s1++ = *s2++;
			return (s1);
		}
		*s1++ = *s2++;
	}
	return (NULL);
}
