/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoppin <tcoppin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/03 15:05:18 by tcoppin           #+#    #+#             */
/*   Updated: 2015/05/04 15:42:45 by tcoppin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arkanoid.h"

void		ft_print_shell(t_all *all, char *msg)
{
	glfwSetWindowShouldClose(all->win.ptr, GL_TRUE);
	ft_putendl(msg);
	ft_putstr("Score : ");
	ft_putnbr(all->score);
	ft_putchar('\n');
}

void		ft_next_level(t_all *all)
{
	if (all->lv->nt != NULL)
	{
		all->lv = all->lv->nt;
		all->cur = 0;
		all->life++;
		all->nb_lvl++;
		init_ball(&all->ball);
		init_ship(&all->ship);
	}
	else
		ft_print_shell(all, "Vous avez gagne !!");
}

void		aff_lvl(t_lvl *lv)
{
	while (lv)
	{
		ft_putendl(lv->fl);
		lv = lv->nt;
	}
}

void		ft_score(t_all *all)
{
	char	*s1;
	char	*s2;
	char	*s3;
	char	*score;
	char	*life;

	s1 = ft_itoa(all->score);
	s2 = ft_itoa(all->life);
	s3 = ft_itoa(all->nb_lvl);
	score = ft_strjoin("SCORE : ", s1);
	life = ft_strjoin("LIFE : ", s2);
	ft_print(-1, -0.95, score, GLUT_BITMAP_HELVETICA_18);
	ft_print(-0.1, -0.95, ft_strjoin("LEVEL : ", s3), GLUT_BITMAP_HELVETICA_18);
	ft_print(0.85, -0.95, life, GLUT_BITMAP_HELVETICA_18);
	ft_strdel(&life);
	ft_strdel(&score);
	ft_strdel(&s1);
	ft_strdel(&s2);
	ft_strdel(&s3);
}

void		ft_print(double x, double y, char *string, void *font)
{
	int	len;
	int	i;

	glRasterPos2f(x, y);
	len = ft_strlen(string);
	i = 0;
	while (i < len)
	{
		glutBitmapCharacter(font, string[i]);
		i++;
	}
}
