/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoppin <tcoppin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/03 14:16:10 by tcoppin           #+#    #+#             */
/*   Updated: 2015/05/03 16:05:43 by tcoppin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arkanoid.h"

void		ft_error(int er)
{
	if (er == CREATE_WINDOW)
		ft_putendl("glfwCreateWindow() fail");
	if (er == NO_MAP)
		ft_putendl("Map wasn't found");
	glfwTerminate();
	exit(EXIT_FAILURE);
}

void		error_callback(int error, const char *description)
{
	(void)error;
	ft_putstr_fd(description, 2);
}
