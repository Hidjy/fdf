/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g2.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laime <laime@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/31 16:16:30 by laime             #+#    #+#             */
/*   Updated: 2014/12/31 16:30:53 by laime            ###   ########.fr       */
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

t_point	*pt_new(int x, int y, int z)
{
	t_point	*pt;

	pt = (t_point *)malloc(sizeof(t_point));
	pt->x = x;
	pt->y = y;
	pt->z = z;
	return (pt);
}

void	pt_set(t_point *pt, int x, int y, int z)
{
	pt->x = x;
	pt->y = y;
	pt->z = z;
}

int		zcolor(int z)
{
	if (z <= -4)
		return (0x3D8189);
	else if (z <= -2)
		return (0x4BB5C1);
	else if (z <= 0)
		return (0x7FC6BC);
	else if (z <= 1)
		return (0xffe58a);
	else if (z <= 4)
		return (0x71A12F);
	else if (z <= 6)
		return (0x557A23);
	else if (z <= 8)
		return (0x896A45);
	else if (z <= 10)
		return (0xA98458);
	else if (z <= 12)
		return (0xCAA986);
	else
		return (0xEDF7F2);
}

void	img_fill(t_env *env, int color)
{
	int		i;
	int		j;

	i = 0;
	while (i < env->width)
	{
		j = 0;
		while (j < env->height)
		{
			img_put_pixel(env, i, j, color);
			j++;
		}
		i++;
	}
}

t_point	pt_get(int x, int y, int z)
{
	t_point	pt;

	pt.x = x;
	pt.y = y;
	pt.z = z;
	return (pt);
}
