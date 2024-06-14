# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ngordobi <ngordobi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/10 11:52:23 by ngordobi          #+#    #+#              #
#    Updated: 2024/06/14 11:56:06 by ngordobi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	so_long

CC			=	gcc
CC_FLAGS	=	-Wall -Wextra -Werror -g3 -MMD

SOURCES		=	1_so_long.c \
				2_check_file.c \
				3_load_map.c \
				4_check_map.c \
				5_check_map_aux.c \
				6_mlx.c \
				7_mlx_move.c \
				mlx_put_sprites_1.c \
				mlx_put_sprites_2.c \
				mlx_put_map.c \
				mlx_close_window.c \
				ft_count.c \
				ft_print_map.c \
				ft_putstr.c \
				ft_free_map.c \

OBJECTS		=	$(SOURCES:%.c=%.o)

INCLUDE		=	so_long.h

MLX			=	./mlx/libmlx_Linux.a
MLX_FLAGS	=	-L mlx/ -lmlx -lXext -lX11



define SO_LONG
\033[0;33m

  ██████  ▒█████         ██▓     ▒█████   ███▄    █   ▄████ 
▒██    ▒ ▒██▒  ██▒      ▓██▒    ▒██▒  ██▒ ██ ▀█   █  ██▒ ▀█▒
░ ▓██▄   ▒██░  ██▒      ▒██░    ▒██░  ██▒▓██  ▀█ ██▒▒██░▄▄▄░
  ▒   ██▒▒██   ██░      ▒██░    ▒██   ██░▓██▒  ▐▌██▒░▓█  ██▓
▒██████▒▒░ ████▓▒░      ░██████▒░ ████▓▒░▒██░   ▓██░░▒▓███▀▒
▒ ▒▓▒ ▒ ░░ ▒░▒░▒░       ░ ▒░▓  ░░ ▒░▒░▒░ ░ ▒░   ▒ ▒  ░▒   ▒ 
░ ░▒  ░ ░  ░ ▒ ▒░       ░ ░ ▒  ░  ░ ▒ ▒░ ░ ░░   ░ ▒░  ░   ░ 
░  ░  ░  ░ ░ ░ ▒          ░ ░   ░ ░ ░ ▒     ░   ░ ░ ░ ░   ░ 
      ░      ░ ░            ░  ░    ░ ░           ░       ░ 
$(END)
endef
export SO_LONG

.SILENT:

all: 		$(NAME) 

$(NAME):	$(OBJECTS) $(INCLUDE)
			make -C ./mlx all
			$(CC) $(CC_FLAGS) $(OBJECTS) -o $(NAME) $(MLX_FLAGS)
			mkdir ./objects/
			mv $(OBJECTS) ./objects/
			echo "\n\n··················· Compilation complete ···················"
			echo "$$SO_LONG"

clean:
	rm -rf ./objects/
	make -C ./mlx clean
	echo "\n·······························"
	echo "\n· Objects correctly removed."

fclean: clean
	rm -rf $(NAME)
	echo "· Executable correctly removed."

nl:
	echo "\n·······························"

re:			fclean nl all
.PHONY:		all clean fclean re
