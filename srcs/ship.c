/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ship.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoppin <tcoppin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/03 14:48:54 by tcoppin           #+#    #+#             */
/*   Updated: 2015/05/03 17:30:46 by tcoppin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arkanoid.h"

void	set_ship_pos(t_all *all, double ret)
{
	if (ret > -1 && ret < 1 - all->ship.width)
	{
		all->ship.pos.x = ret;
		if (all->ball.vspeed.x == 0 && all->ball.vspeed.x == 0)
		{
			all->ball.pos.x = all->ship.pos.x + SHIP_W;
		}
	}
}
