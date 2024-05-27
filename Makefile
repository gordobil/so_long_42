# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ngordobi <ngordobi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/27 13:03:33 by ngordobi          #+#    #+#              #
#    Updated: 2024/05/27 14:36:06 by ngordobi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long.a

CC = gcc
CCFLAGS = -Wall -Wextra -Werror
REMOVE = rm -f
LIBRARY = ar rc

SOURCES = so_long.c start.c map_load.c map_check.c map_check_aux.c \
			ft_putstr.c ft_print_map.c\

OBJECTS = $(SOURCES:.c=.o)

INCLUDE = so_long.h

all: $(NAME)

$(NAME): $(OBJECTS) $(INCLUDE)
	$(LIBRARY) $(NAME) $(OBJECTS)

$(OBJECTS): $(SOURCES)
	$(CC) $(CCFLAGS) -c $(SOURCES)

clean:
	$(REMOVE) $(OBJECTS)

fclean: clean
	$(REMOVE) $(NAME)

re: fclean all
.PHONY: all clean fclean re
