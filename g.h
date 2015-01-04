/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g.h                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laime <laime@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/14 17:34:40 by laime             #+#    #+#             */
/*   Updated: 2014/12/30 21:30:41 by laime            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef G_H
# define G_H

# include "libft/libft.h"

typedef struct	s_point
{
	int			x;
	int			y;
	int			z;
}				t_point;

typedef struct	s_env
{
	void		*mlx;
	void		*win;
	int			width;
	int			height;
	void		*img;
	char		*idata;
	int			ibits;
	int			isizeline;
	int			iendian;
	int			**map;
	int			mx;
	int			my;
	double		c;
	int			xoff;
	int			yoff;
	double		cz;
}				t_env;

t_point			*pt_new(int x, int y, int z);
t_point			pt_get(int x, int y, int z);
void			img_put_pixel(t_env *env, int x, int y, int color);
void			img_put_line(t_env *env, t_point *pt1, t_point *pt2, int color);
void			img_draw(t_env *env);
void			img_fill(t_env *env, int color);
int				zcolor(int z);
void			to_iso(t_point *pt, t_env *env);

#endif
