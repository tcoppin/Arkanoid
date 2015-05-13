/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoppin <tcoppin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/12 16:15:02 by tcoppin           #+#    #+#             */
/*   Updated: 2015/05/03 22:55:35 by tcoppin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*tmp;
	int		i;
	int		str;
	int		j;

	if (!s)
		return (NULL);
	i = 0;
	tmp = (char*)malloc(sizeof(char) * (ft_strlen(s) + 1));
	str = ft_strlen(s) - 1;
	while (s[str] == ' ' || s[str] == '\n' || s[str] == '\t')
		str--;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	j = 0;
	while (i <= str)
		tmp[j++] = s[i++];
	tmp[j] = '\0';
	return (tmp);
}
