# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ngordobi <ngordobi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/27 13:03:33 by ngordobi          #+#    #+#              #
#    Updated: 2024/06/04 13:16:34 by ngordobi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long.a

CC = gcc
CCFLAGS = -Wall -Wextra -Werror
REMOVE = rm -f
LIBRARY = ar rc

SOURCES = 1_so_long.c 2_check_file.c 3_load_map.c 4_check_map.c \
			5_check_map_aux.c ft_count.c ft_print_map.c ft_putstr.c \

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
