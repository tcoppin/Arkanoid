/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoppin <tcoppin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/03 22:44:19 by tcoppin           #+#    #+#             */
/*   Updated: 2015/05/03 22:51:20 by tcoppin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*s1;
	char	*s2;

	if (n == 0 || dst == src)
		return (dst);
	s1 = (char *)dst;
	s2 = (char *)src;
	while (--n)
		*s1++ = *s2++;
	*s1 = *s2;
	return (dst);
}
