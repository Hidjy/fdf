/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laime <laime@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/10 17:25:09 by laime             #+#    #+#             */
/*   Updated: 2014/12/16 16:36:36 by laime            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft/libft.h"
# include "g.h"

# define WIDTH 800
# define HEIGHT 600

void	stop(char *str);
void	parse_file(int fd, t_env *env);
int		draw(t_env *env);
int		key(int key, t_env *env);
int		mouse(int button, int x, int y, t_env *env);

#endif
