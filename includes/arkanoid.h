/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arkanoid.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoppin <tcoppin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/03 13:27:17 by tcoppin           #+#    #+#             */
/*   Updated: 2015/05/04 20:01:48 by tcoppin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARKANOID_H
# define ARKANOID_H

# include <GLFW/glfw3.h>
# include <stdlib.h>
# include <fcntl.h>
# include <dirent.h>
# include "libft.h"
# include <GLUT/glut.h>

# define TRUE 1
# define FALSE 0

# define SHIP_SPEED 0.04
# define SHIP_W 0.15
# define SHIP_H 0.015
# define SHIP_OFFSET -0.85

# define BRICK_W 0.15
# define BRICK_H 0.04
# define BRICK_OFFSET_X 0.18
# define BRICK_OFFSET_Y 0.1

# define BALL_SIZE 0.03
# define BALL_SPEED 0.02

# define COEFF_D 0.05
# define COEFF_SPEED 0.2

typedef int		t_bool;

typedef struct	s_win
{
	GLFWwindow	*ptr;
	int			width;
	int			height;
	float		ratio;
}				t_win;

typedef struct	s_dpos
{
	double		x;
	double		y;
}				t_dpos;

typedef struct	s_ship
{
	t_dpos		pos;
	t_dpos		vdir;
	double		height;
	double		width;
}				t_ship;

typedef struct	s_ball
{
	t_dpos		pos;
	t_dpos		vspeed;
	double		radius;
	double		radius_pow_2;
}				t_ball;

typedef struct	s_brick
{
	int			state;
	t_dpos		pos;
	double		height;
	double		width;
}				t_brick;

typedef struct	s_map
{
	t_brick		**map;
	int			height;
	int			width;
}				t_map;

typedef struct	s_lvl
{
	struct s_lvl	*nt;
	struct s_lvl	*bf;
	char			*fl;
}				t_lvl;

typedef struct	s_all
{
	t_win		win;
	t_ship		ship;
	t_ball		ball;
	t_map		map;
	t_lvl		*lv;
	int			cur;
	int			life;
	int			score;
	char		*d_lvls;
	int			nb_lvl;
	int			pse;
	int			speed_ball_x;
	int			speed_ball_y;
}				t_all;

typedef enum	e_error
{
	CREATE_WINDOW = 1,
	NO_MAP,
}				t_error;

/*
** init.c
*/
void			init_ball(t_ball *ball);
void			init_ship(t_ship *ship);
void			init_all(t_all *all);

/*
** parse.c
*/
void			map_parser(t_map *map, char *filename);
void			parse_lvl(t_all *all, char *dir);

/*
** error.c
*/
void			ft_error(int er);
void			error_callback(int error, const char *description);

/*
** content_win.c
*/
void			init_frame(t_all *all);
void			content_win(t_all *all);

/*
** draw.c
*/
void			draw_all(t_all *all);

/*
** keyhook.c
*/
void			key_hook(t_all *all);
void			key_callback(GLFWwindow *window, int key,
				int sc, int ac, int mod);

/*
** ball.c
*/
void			move_ball(t_all *all);

/*
** ship.c
*/
void			set_ship_pos(t_all *all, double ret);

/*
** collision.c
*/
int				removeball_n_setnewvec(t_ball *ball, t_brick *brick);
t_bool			collision_xy_circle(double x, double y, t_ball *b);
t_bool			ball_is_in_brick(t_ball *ball, t_brick *brick);
t_bool			check_brick_collision(t_ball *ball, t_map *map);
t_bool			check_ship_collision(t_ball *ball, t_ship *ship);

/*
** map.c
*/
int				ft_check_map(t_map *map);

/*
** misc.c
*/
void			ft_print_shell(t_all *all, char *msg);
void			ft_next_level(t_all *all);
void			aff_lvl(t_lvl *lv);
void			ft_print(double x, double y, char *string, void *font);
void			ft_score(t_all *all);

#endif
