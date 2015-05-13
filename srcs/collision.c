/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoppin <tcoppin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/03 14:51:48 by tcoppin           #+#    #+#             */
/*   Updated: 2015/05/03 21:08:44 by tcoppin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arkanoid.h"

int			removeball_n_setnewvec(t_ball *ball, t_brick *brick)
{
	ball->vspeed.y = -ball->vspeed.y;
	if (brick->state != 9)
	{
		brick->state -= 1;
		return (1);
	}
	return (0);
}

t_bool		collision_xy_circle(double x, double y, t_ball *b)
{
	double d2;

	d2 = (x - b->pos.x) * (x - b->pos.x) + (y - b->pos.y) * (y - b->pos.y);
	if (d2 > b->radius_pow_2)
		return (FALSE);
	return (TRUE);
}

t_bool		ball_is_in_brick(t_ball *ball, t_brick *brick)
{
	double x;

	if (brick->state == 0)
		return (FALSE);
	x = brick->pos.x;
	while (x < brick->pos.x + brick->width)
	{
		if (collision_xy_circle(x, brick->pos.y, ball) == TRUE)
			return (TRUE);
		if (collision_xy_circle(x, brick->pos.y - brick->height, ball) == TRUE)
			return (TRUE);
		x += 0.01;
	}
	return (FALSE);
}

t_bool		check_brick_collision(t_ball *ball, t_map *map)
{
	int i;
	int j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (ball_is_in_brick(ball, &map->map[i][j]) == TRUE)
				return (removeball_n_setnewvec(ball, &map->map[i][j]));
			j++;
		}
		i++;
	}
	return (FALSE);
}

t_bool		check_ship_collision(t_ball *ball, t_ship *ship)
{
	double x;

	x = ship->pos.x;
	while (x < ship->pos.x + ship->width)
	{
		if (collision_xy_circle(x, ship->pos.y, ball) == TRUE)
			return (TRUE);
		if (collision_xy_circle(x, ship->pos.y - ship->height, ball) == TRUE)
			return (TRUE);
		x += 0.05;
	}
	return (FALSE);
}
