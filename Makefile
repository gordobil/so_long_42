# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ngordobi <ngordobi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/27 13:03:33 by ngordobi          #+#    #+#              #
#    Updated: 2024/06/04 13:45:40 by ngordobi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long.a
mlx = mlx/libmlx.a

CC = gcc
CCFLAGS = -Wall -Wextra -Werror
mlxFLAGS = -I -g -L /usr/X11/lib -Lincludes -L./mlx -lmlx -Imlx -lXext -lX11 -lz -lm
REMOVE = rm -f
LIBRARY = ar rc

SOURCES = 1_so_long.c 2_check_file.c 3_load_map.c 4_check_map.c \
			5_check_map_aux.c ft_count.c ft_print_map.c ft_putstr.c \

OBJECTS = $(SOURCES:.c=.o)

INCLUDE = so_long.h

all: $(NAME)

maker:
	@make -C mlbx

$(NAME): $(OBJECTS) $(INCLUDE)
	$(LIBRARY) $(NAME) $(OBJECTS)

$(OBJECTS): $(SOURCES)
	$(CC) $(CCFLAGS) -c $(SOURCES)

clean:
	$(REMOVE) $(OBJECTS)

fclean: clean
	$(REMOVE) $(NAME)
	@make clean -C mlx

re: fclean all
.PHONY: all clean fclean re
