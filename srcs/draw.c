/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoppin <tcoppin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/03 14:33:15 by tcoppin           #+#    #+#             */
/*   Updated: 2015/05/04 00:56:38 by tcoppin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arkanoid.h"

static void		draw_ship(t_ship *ship)
{
	glBegin(GL_QUADS);
	glColor3ub(78, 78, 78);
	glVertex2d(ship->pos.x, ship->pos.y);
	glVertex2d(ship->pos.x, ship->pos.y - ship->height);
	glVertex2d(ship->pos.x + ship->width, ship->pos.y - ship->height);
	glVertex2d(ship->pos.x + ship->width, ship->pos.y);
	glEnd();
}

static void		draw_circle(double x, double y, double rayon, int aliasing)
{
	float	angle;
	int		i;

	i = 0;
	glBegin(GL_POLYGON);
	glColor3ub(190, 190, 190);
	while (i < aliasing)
	{
		angle = i * 2 * M_PI / aliasing;
		glVertex2f(x + (cos(angle) * rayon), y + (sin(angle) * rayon));
		i++;
	}
	glEnd();
}

static void		draw_one_brick(t_brick *brick)
{
	glBegin(GL_QUADS);
	if (brick->state != 9)
	{
		if (brick->state == 1)
			glColor3ub(125, 0, 0);
		else if (brick->state == 2)
			glColor3ub(0, 125, 0);
		else if (brick->state == 3)
			glColor3ub(0, 0, 125);
		else
			glColor3ub(125, 0, 125);
	}
	else
		glColor3ub(255, 255, 255);
	glVertex2d(brick->pos.x, brick->pos.y);
	glVertex2d(brick->pos.x, brick->pos.y - brick->height);
	glVertex2d(brick->pos.x + brick->width, brick->pos.y - brick->height);
	glVertex2d(brick->pos.x + brick->width, brick->pos.y);
	glEnd();
}

static void		draw_bricks(t_map *map)
{
	int i;
	int j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (map->map[i][j].state >= 1)
				draw_one_brick(&map->map[i][j]);
			j++;
		}
		i++;
	}
}

void			draw_all(t_all *all)
{
	draw_ship(&all->ship);
	draw_circle(all->ball.pos.x, all->ball.pos.y, all->ball.radius, 20);
	draw_bricks(&all->map);
	glfwSwapBuffers(all->win.ptr);
}
