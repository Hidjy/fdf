/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g3.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laime <laime@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/31 16:22:15 by laime             #+#    #+#             */
/*   Updated: 2014/12/31 16:31:04 by laime            ###   ########.fr       */
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

void	draw_square(t_env *env, t_point pt1, t_point pt2, t_point pt3)
{
	to_iso(&pt1, env);
	to_iso(&pt2, env);
	to_iso(&pt3, env);
	img_put_line(env, &pt1, &pt2, zcolor((pt1.z > pt2.z) ? pt1.z : pt2.z));
	img_put_line(env, &pt1, &pt3, zcolor((pt1.z > pt3.z) ? pt1.z : pt3.z));
}

void	img_draw(t_env *env)
{
	int		i;
	int		j;

	i = 0;
	while (i < env->mx - 1)
	{
		j = 0;
		while (j < env->my - 1)
		{
			draw_square(env, \
					pt_get(i, j, env->map[i][j]), \
					pt_get(i + 1, j, env->map[i + 1][j]), \
					pt_get(i, j + 1, env->map[i][j + 1]));
			draw_square(env, \
					pt_get(i + 1, j + 1, env->map[i + 1][j + 1]), \
					pt_get(i + 1, j, env->map[i + 1][j]), \
					pt_get(i, j + 1, env->map[i][j + 1]));
			j++;
		}
		i++;
	}
}
