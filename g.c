/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laime <laime@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/14 17:37:01 by laime             #+#    #+#             */
/*   Updated: 2014/12/31 16:30:44 by laime            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <mlx.h>
#include <math.h>
#include "fdf.h"
#include "g.h"
#include "libft/libft.h"
#include "get_next_line.h"

void		img_put_pixel(t_env *env, int x, int y, int color)
{
	char			*data;
	unsigned int	value;

	data = env->idata;
	value = mlx_get_color_value(env->mlx, color);
	if (x > 0 && x < env->width && y > 0 && y < env->height)
		ft_memcpy(data + y * env->isizeline + x * (env->ibits / 8), &value, 3);
}

static void	img_put_hline(t_env *env, t_point *pt1, t_point *pt2, int color)
{
	int		i;

	i = pt1->x;
	while (i < pt2->x)
	{
		img_put_pixel(env, i, pt1->y + ((pt2->y - pt1->y) * \
					(i - pt1->x)) / (pt2->x - pt1->x), color);
		i++;
	}
}

static void	img_put_vline(t_env *env, t_point *pt1, t_point *pt2, int color)
{
	int		i;

	i = pt1->y;
	while (i < pt2->y)
	{
		img_put_pixel(env, pt1->x + ((pt2->x - pt1->x) * \
					(i - pt1->y)) / (pt2->y - pt1->y), i, color);
		i++;
	}
}

void		img_put_line(t_env *env, t_point *pt1, t_point *pt2, int color)
{
	if (fabs(pt1->x - pt2->x) > fabs(pt1->y - pt2->y))
	{
		if (pt1->x < pt2->x)
			img_put_hline(env, pt1, pt2, color);
		else
			img_put_hline(env, pt2, pt1, color);
	}
	else
	{
		if (pt1->y < pt2->y)
			img_put_vline(env, pt1, pt2, color);
		else
			img_put_vline(env, pt2, pt1, color);
	}
}

void		to_iso(t_point *pt, t_env *env)
{
	t_point		tmp;

	tmp.x = pt->x;
	tmp.y = pt->y;
	tmp.z = pt->z;
	pt->x = tmp.x * 2 - tmp.y * 2;
	pt->y = tmp.x + tmp.y - tmp.z * env->cz;
	pt->x *= env->c;
	pt->y *= env->c;
	pt->x += env->xoff;
	pt->y += env->yoff;
}
