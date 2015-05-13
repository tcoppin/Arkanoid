/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoppin <tcoppin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/11 17:42:26 by tcoppin           #+#    #+#             */
/*   Updated: 2014/11/11 17:51:01 by tcoppin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	int i;

	if (!s1 && !s2)
		return (1);
	if (!s1 || !s2)
		return (0);
	i = ft_strncmp(s1, s2, n);
	if (i != 0)
		return (0);
	else
		return (1);
}
