# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ngordobi <ngordobi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/10 11:52:23 by ngordobi          #+#    #+#              #
#    Updated: 2024/06/24 13:24:47 by ngordobi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				=	prueba

CC					=	gcc
CC_FLAGS			=	-Wall -Wextra -Werror -g3 -MMD

MLX					=	../mlx/libmlx_Linux.a
MLX_FLAGS			=	-L ../mlx/ -lmlx -lXext -lX11

SOURCES				=	prueba.c \

OBJECTS				=	$(SOURCES:%.c=%.o)

.SILENT:

all: 			$(NAME)

$(NAME):		$(OBJECTS)
				make -C ../mlx all
				$(CC) $(CC_FLAGS) $(OBJECTS) -o $(NAME) $(MLX_FLAGS)

clean:
				rm -rf ./*.o
				make -C ../mlx clean

fclean:			clean
				rm -rf $(NAME)

re:				fclean all
.PHONY:			all clean fclean re
