/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoppin <tcoppin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/12 16:57:19 by tcoppin           #+#    #+#             */
/*   Updated: 2015/03/21 12:02:49 by tcoppin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		is_del(char c, char ch)
{
	if (c == ch)
		return (1);
	return (0);
}

static int		find_nb_w(char *str, char ch)
{
	int result;

	result = 0;
	while (*str)
	{
		while (is_del(*str, ch))
			str++;
		if (*str)
			result++;
		while (!is_del(*str, ch) && *str)
			str++;
	}
	return (result);
}

static char		**split_func(char *str, int nb_words, int *i, char ch)
{
	int		i3;
	int		word_size;
	char	**result;

	if (!(result = malloc(sizeof(char*) * (nb_words + 1))))
		return (NULL);
	while (i[0] < nb_words)
	{
		while (is_del(str[i[1]], ch))
			i[1]++;
		word_size = 0;
		while (!is_del(str[i[1] + word_size], ch) && str[i[1] + word_size])
			word_size++;
		if (!(result[i[0]] = malloc(sizeof(char) * (word_size + 1))))
			return (NULL);
		i3 = -1;
		while (++i3 < word_size)
			result[i[0]][i3] = str[i[1] + i3];
		result[i[0]][i3] = '\0';
		i[1] += word_size;
		i[0]++;
	}
	result[i[0]] = 0;
	return (result);
}

char			**ft_strsplit(char const *s, char c)
{
	int i[2];

	if (s && c)
	{
		i[0] = 0;
		i[1] = 0;
		return (split_func((char*)s, find_nb_w((char*)s, c), i, c));
	}
	return (NULL);
}
