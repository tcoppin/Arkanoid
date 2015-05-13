/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ball.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoppin <tcoppin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/03 14:48:39 by tcoppin           #+#    #+#             */
/*   Updated: 2015/05/03 22:30:14 by tcoppin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arkanoid.h"

static int		set_ball_pos(double *pos, double ret, double min, double max)
{
	if (ret < max && ret > min)
	{
		if (ret < -1)
			return (0);
		*pos = ret;
		return (1);
	}
	return (-1);
}

static void		ball_rebound(t_ball *ball, t_ship *ship)
{
	double mid_ship;
	double dx;

	mid_ship = ship->pos.x + (ship->width / 2);
	dx = mid_ship + ship->width / 2. - ball->pos.x;
	ball->vspeed.y *= -1;
	ball->vspeed.x = -dx * COEFF_D + SHIP_SPEED * COEFF_SPEED;
}

void			move_ball(t_all *all)
{
	int			ret;

	if ((ret = set_ball_pos(&all->ball.pos.y,
		all->ball.pos.y + all->ball.vspeed.y, -1.5, 1)) <= 0)
	{
		if (ret == -1)
			all->ball.vspeed.y = -all->ball.vspeed.y;
		else
		{
			init_ball(&all->ball);
			init_ship(&all->ship);
			if (--all->life == 0)
				ft_print_shell(all, "Vous avez perdu !!");
			all->cur = 1;
		}
	}
	if (set_ball_pos(&all->ball.pos.x,
		all->ball.pos.x + all->ball.vspeed.x, -1, 1) == -1)
		all->ball.vspeed.x = -all->ball.vspeed.x;
	if (check_ship_collision(&all->ball, &all->ship) == TRUE)
		ball_rebound(&all->ball, &all->ship);
	if (check_brick_collision(&all->ball, &all->map))
		all->score += 10;
}
