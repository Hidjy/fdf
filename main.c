/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laime <laime@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/31 16:43:05 by laime             #+#    #+#             */
/*   Updated: 2014/12/31 16:45:39 by laime            ###   ########.fr       */
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

int		main(int ac, char **av)
{
	t_env	env;
	int		fd;

	if (ac != 2)
		stop("Please specify a file to open.");
	fd = open(av[1], O_RDONLY);
	parse_file(fd, &(env));
	env.mlx = mlx_init();
	if (env.mlx == NULL)
		return (0);
	env.width = WIDTH;
	env.height = HEIGHT;
	env.win = mlx_new_window(env.mlx, env.width, env.height, "Fdf");
	env.img = mlx_new_image(env.mlx, env.width, env.height);
	env.idata = mlx_get_data_addr(env.img, &(env.ibits), \
			&(env.isizeline), &(env.iendian));
	mlx_expose_hook(env.win, draw, &env);
	mlx_key_hook(env.win, key, &env);
	mlx_mouse_hook(env.win, mouse, &env);
	mlx_loop(env.mlx);
	return (0);
}

void	stop(char *str)
{
	ft_putendl(str);
	exit(3);
}
