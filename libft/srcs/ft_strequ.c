/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoppin <tcoppin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/03 22:44:19 by tcoppin           #+#    #+#             */
/*   Updated: 2015/05/03 22:53:24 by tcoppin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strequ(char const *s1, char const *s2)
{
	int i;

	if (!s1 && !s2)
		return (1);
	if (!s1 || !s2)
		return (0);
	i = ft_strcmp(s1, s2);
	if (i != 0)
		return (0);
	else
		return (1);
}
