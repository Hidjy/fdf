# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: laime <laime@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/12/10 16:56:15 by laime             #+#    #+#              #
#    Updated: 2014/12/31 16:39:54 by laime            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
SRC = main.c fdf.c g.c g2.c g3.c get_next_line.c
HEADERS = fdf.h get_next_line.h
OBJ = $(SRC:.c=.o)
OPT = -Wall -Werror -Wextra
LIBS = -lm -L /usr/X11/lib -lmlx -lXext -lX11 -L libft -lft

all: $(NAME)

.PHONY: libft clean fclean re

$(NAME): libft
	@gcc $(OPT) -c $(SRC)
	@gcc -o $(NAME) $(OBJ) $(LIBS)

libft:
	@make -C libft fclean
	@make -C libft

clean:
	@/bin/rm -f $(OBJ) $(HEADERS:.h=.h.gch)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all
