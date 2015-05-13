/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoppin <tcoppin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/29 13:50:58 by tcoppin           #+#    #+#             */
/*   Updated: 2015/05/03 22:56:43 by tcoppin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int		check_stock(char **stock, char ***line, char *buffer)
{
	char *ptr;

	if (*stock == NULL)
		*stock = ft_strnew(1);
	if (*stock)
		if ((ptr = ft_strchr(*stock, '\n')))
		{
			*ptr = '\0';
			**line = ft_strjoin(*stock, buffer);
			free(*stock);
			*stock = ft_strdup(ptr + 1);
			ft_bzero(buffer, BUFF_SIZE + 1);
			free(buffer);
			return (1);
		}
	return (0);
}

static int		check_tmp(char *tmp, char ***line, char **stock, char *buffer)
{
	if (tmp)
	{
		*tmp = '\0';
		**line = ft_strjoin(*stock, buffer);
		free(*stock);
		*stock = ft_strdup(tmp + 1);
		ft_bzero(buffer, BUFF_SIZE + 1);
		free(buffer);
		return (1);
	}
	return (-1);
}

static int		ft_return(int ret, char *stock, char ***line)
{
	if (ret < 0)
		return (-1);
	if (stock == NULL)
		return (0);
	**line = ft_strdup(stock);
	free(stock);
	return (0);
}

static int		ft_checkdown(char ***line, char **stock)
{
	if (*stock)
	{
		**line = ft_strdup(*stock);
		ft_strdel(*&stock);
		return (0);
	}
	else
		return (-1);
}

int				get_next_line(int const fd, char **line)
{
	static char *stock[256];
	char		*ptr;
	char		*tmp;
	char		*buffer;
	int			ret;

	buffer = ft_strnew(BUFF_SIZE + 1);
	if ((check_stock(&stock[fd], &line, buffer)) == 1)
		return (1);
	while ((ret = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		buffer[ret] = '\0';
		tmp = ft_strchr(buffer, '\n');
		if ((check_tmp(tmp, &line, &stock[fd], buffer)) == 1)
			return (1);
		ptr = stock[fd];
		stock[fd] = ft_strjoin(stock[fd], buffer);
		free(ptr);
	}
	if (ret < 0)
		return (ft_return(ret, stock[fd], &line));
	if ((ft_checkdown(&line, &stock[fd])) == 0)
		return (0);
	return (ft_return(ret, stock[fd], &line));
}
