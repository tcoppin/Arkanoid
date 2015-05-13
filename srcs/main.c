/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoppin <tcoppin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/03 13:31:02 by tcoppin           #+#    #+#             */
/*   Updated: 2015/05/04 14:53:34 by tcoppin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arkanoid.h"

int		main(int ac, char **av)
{
	t_all	all;

	(void)ac;
	if (!av[1])
		all.d_lvls = "./levels/";
	else
	{
		all.d_lvls = ft_strjoin("./", av[1]);
		all.d_lvls = ft_strjoin_free(all.d_lvls, "/");
	}
	init_all(&all);
	while (!glfwWindowShouldClose(all.win.ptr))
		content_win(&all);
	glfwDestroyWindow(all.win.ptr);
	glfwTerminate();
	return (0);
}
