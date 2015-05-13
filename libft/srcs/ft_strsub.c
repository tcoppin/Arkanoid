/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoppin <tcoppin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/11 20:29:15 by tcoppin           #+#    #+#             */
/*   Updated: 2015/05/03 22:55:37 by tcoppin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*dst;

	if (!s)
		return (NULL);
	dst = (char*)malloc(sizeof(char) * len + 1);
	if (!dst)
		return (NULL);
	return (ft_strncpy(dst, &s[start], len));
}
