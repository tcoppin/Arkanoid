/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoppin <tcoppin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/03 22:44:19 by tcoppin           #+#    #+#             */
/*   Updated: 2015/05/03 22:51:30 by tcoppin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*copy;
	char	*p1;
	size_t	i;

	copy = ft_strnew(len);
	p1 = (char *)dst;
	i = 0;
	while (i < len)
	{
		copy[i] = ((char *)src)[i];
		i++;
	}
	while (len > 0)
	{
		len--;
		p1[len] = copy[len];
	}
	return (dst);
}
