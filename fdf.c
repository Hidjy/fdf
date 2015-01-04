/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laime <laime@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/10 17:21:38 by laime             #+#    #+#             */
/*   Updated: 2014/12/16 20:58:37 by laime            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <mlx.h>
#include "fdf.h"
#include "g.h"
#include "libft/libft.h"
#include "get_next_line.h"

void	lst_to_map(t_list *lst, t_env *env, int x, int y)
{
	int			**map;
	t_list		*tmp;
	t_point		*pt;
	int			i;

	i = 0;
	tmp = lst;
	map = (int **)malloc(sizeof(int *) * x);
	while (i < x)
	{
		map[i] = (int *)malloc(sizeof(int) * y);
		i++;
	}
	while (tmp)
	{
		pt = tmp->content;
		if (pt->x < x && pt->y < y)
			map[pt->x][pt->y] = pt->z;
		tmp = tmp->next;
	}
	env->map = map;
	env->c = 500 / (x + y);
	env->xoff = x * env->c * 2;
	env->yoff = y * env->c;
	env->cz = 1;
}

void	parse_file(int fd, t_env *env)
{
	int		i;
	int		j;
	t_list	*pts;
	char	*line;
	char	**lines;

	i = 0;
	pts = NULL;
	if (fd <= 0)
		stop("Error when openning file.");
	while (get_next_line(fd, &line))
	{
		lines = ft_strsplit(line, ' ');
		j = 0;
		while (lines[j] != NULL)
		{
			ft_lstadd(&pts, ft_lstnew(pt_new(j, i, \
				ft_atoi(lines[j])), sizeof(t_point)));
			j++;
		}
		i++;
	}
	env->mx = j;
	env->my = i;
	lst_to_map(pts, env, j, i);
}

int		draw(t_env *env)
{
	img_fill(env, 0);
	img_draw(env);
	mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
	return (0);
}

int		mouse(int button, int x, int y, t_env *env)
{
	(void)x;
	(void)y;
	if (button == 4)
		env->cz /= 1.01;
	else if (button == 5)
		env->cz *= 1.01;
	draw(env);
	return (0);
}

int		key(int key, t_env *env)
{
	if (key == 65307)
		stop("User exit.");
	else if (key == 65362)
		env->yoff -= 20;
	else if (key == 65364)
		env->yoff += 20;
	else if (key == 65361)
		env->xoff -= 20;
	else if (key == 65363)
		env->xoff += 20;
	else if (key == 65365)
		env->c *= 1.1;
	else if (key == 65366)
		env->c /= 1.1;
	else
		ft_putendl(ft_itoa(key));
	draw(env);
	return (0);
}
