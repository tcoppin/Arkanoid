/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoppin <tcoppin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/03 13:37:05 by tcoppin           #+#    #+#             */
/*   Updated: 2015/05/03 22:22:43 by tcoppin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arkanoid.h"

static void		map_parser2(t_map *map, char *line, int t[2], double y)
{
	char	**buf;
	double	x;

	x = -0.98;
	buf = ft_strsplit(line, ' ');
	ft_strdel(&line);
	map->map[t[1]] = (t_brick *)ft_memalloc(sizeof(t_brick) * map->width);
	while (buf[t[0]])
	{
		map->map[t[1]][t[0]].state = ft_atoi(buf[t[0]]);
		map->map[t[1]][t[0]].pos.x = x;
		map->map[t[1]][t[0]].pos.y = y;
		map->map[t[1]][t[0]].height = BRICK_H;
		map->map[t[1]][t[0]].width = BRICK_W;
		x += BRICK_OFFSET_X;
		t[0]++;
	}
	ft_free_tb(&buf);
}

static void		get_map_dimensions(char *file, int *height, int *width)
{
	char	*line;
	int		fd;
	int		i;

	i = 0;
	line = NULL;
	*height = 0;
	*width = 0;
	if ((fd = open(file, O_RDONLY)) == -1)
		ft_error(NO_MAP);
	while (get_next_line(fd, &line) > 0)
	{
		if (*height == 0)
		{
			while (line[i])
			{
				i++;
				*width += 1;
			}
		}
		ft_strdel(&line);
		*height += 1;
	}
	close(fd);
}

void			map_parser(t_map *map, char *filename)
{
	int		t[2];
	int		fd;
	char	*line;
	double	y;

	t[0] = 0;
	t[1] = 0;
	y = 1.1;
	get_map_dimensions(filename, &map->height, &map->width);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		ft_error(NO_MAP);
	map->map = (t_brick **)ft_memalloc(sizeof(t_brick *) * map->height + 1);
	while (get_next_line(fd, &line) > 0)
	{
		map_parser2(map, line, t, y);
		t[0] = 0;
		y -= BRICK_OFFSET_Y;
		t[1]++;
	}
	map->map[t[1]] = NULL;
	close(fd);
}

static void		add_lvl(t_lvl **lv, char *sc)
{
	t_lvl			*ns;
	t_lvl			*tp;

	ns = (t_lvl *)ft_memalloc((sizeof(t_lvl)));
	ns->fl = sc;
	ns->nt = NULL;
	ns->bf = NULL;
	if ((*lv))
	{
		tp = (*lv);
		while ((*lv)->nt)
			(*lv) = (*lv)->nt;
		(*lv)->nt = ns;
		ns->bf = (*lv);
		(*lv) = tp;
	}
	else
		(*lv) = ns;
}

void			parse_lvl(t_all *all, char *dir)
{
	DIR				*rp;
	struct dirent	*fc;

	if ((rp = opendir(dir)) != NULL)
	{
		while ((fc = readdir(rp)))
			if (!ft_strequ(fc->d_name, ".") && !ft_strequ(fc->d_name, ".."))
				add_lvl(&all->lv, ft_strdup(fc->d_name));
		if (closedir(rp) == -1)
			exit(-1);
	}
}
