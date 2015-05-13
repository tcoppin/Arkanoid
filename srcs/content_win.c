/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   content_win.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoppin <tcoppin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/03 14:27:31 by tcoppin           #+#    #+#             */
/*   Updated: 2015/05/04 15:42:34 by tcoppin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arkanoid.h"

void		init_frame(t_all *all)
{
	glfwGetFramebufferSize(all->win.ptr, &all->win.width, &all->win.height);
	all->win.ratio = all->win.width / (float)all->win.height;
	glViewport(0, 0, all->win.width, all->win.height);
}

void		content_win(t_all *all)
{
	char	*file;

	init_frame(all);
	glClear(GL_COLOR_BUFFER_BIT);
	if (!all->cur)
	{
		file = ft_strjoin(all->d_lvls, all->lv->fl);
		map_parser(&all->map, file);
		free(file);
	}
	move_ball(all);
	key_hook(all);
	ft_score(all);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-(all->win.ratio), all->win.ratio, -1.f, 1.f, 1.f, -1.f);
	glMatrixMode(GL_MODELVIEW);
	draw_all(all);
	if (ft_check_map(&all->map))
		ft_next_level(all);
}
