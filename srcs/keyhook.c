/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoppin <tcoppin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/03 14:20:42 by tcoppin           #+#    #+#             */
/*   Updated: 2015/05/04 20:05:32 by tcoppin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arkanoid.h"

void	ft_pause(t_all *all)
{
	ft_putnbr(all->pse);
	ft_putendl("");
	if (all->pse == 0)
	{
		all->pse = 1;
		all->speed_ball_x = all->ball.vspeed.x;
		all->speed_ball_y = all->ball.vspeed.y;
		all->ball.vspeed.x = 0;
		all->ball.vspeed.y = 0;
	}
}

void	ft_unpause(t_all *all)
{
	ft_putnbr(all->pse);
	ft_putendl("");
	if (all->pse == 1)
	{
		all->pse = 0;
		all->ball.vspeed.x = all->speed_ball_x;
		all->ball.vspeed.y = all->speed_ball_y;
		all->speed_ball_x = 0;
		all->speed_ball_y = 0;
	}
}

void	key_hook(t_all *all)
{
	glfwPollEvents();
	if (glfwGetKey(all->win.ptr, GLFW_KEY_LEFT) == GLFW_PRESS  && all->pse < 1)
		set_ship_pos(all, all->ship.pos.x - SHIP_SPEED);
	if (glfwGetKey(all->win.ptr, GLFW_KEY_RIGHT) == GLFW_PRESS && all->pse < 1)
		set_ship_pos(all, all->ship.pos.x + SHIP_SPEED);
	if (glfwGetKey(all->win.ptr, GLFW_KEY_PAGE_UP) == GLFW_PRESS
		&& all->cur > 0)
		ft_next_level(all);
	if (glfwGetKey(all->win.ptr, GLFW_KEY_SPACE) == GLFW_PRESS && all->cur < 2)
	{
		all->cur = 2;
		all->ball.vspeed.x = BALL_SPEED;
		all->ball.vspeed.y = BALL_SPEED;
	}
	if (glfwGetKey(all->win.ptr, GLFW_KEY_P) == GLFW_PRESS && all->pse == 0)
		ft_pause(all);
	if (glfwGetKey(all->win.ptr, GLFW_KEY_O) == GLFW_PRESS && all->pse == 1)
		ft_unpause(all);
}

void	key_callback(GLFWwindow *window, int key, int sc, int ac, int mod)
{
	(void)sc;
	(void)mod;
	if (key == GLFW_KEY_ESCAPE && ac == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);
}
