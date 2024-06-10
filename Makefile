# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ngordobi <ngordobi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/10 11:52:23 by ngordobi          #+#    #+#              #
#    Updated: 2024/06/10 13:24:49 by ngordobi         ###   ########.fr        #
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
				ft_count.c \
				ft_print_map.c \
				ft_putstr.c \

OBJECTS		=	$(SOURCES:%.c=%.o)

INCLUDE		=	so_long.h

MLX			=	./mlx/libmlx_Linux.a
MLX_FLAGS	=	-L mlx/ -lmlx -lXext -lX11



define SO_LONG
\033[0;31m



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
			echo "\n· Compilation complete."
			echo "$$SO_LONG"

clean:
	rm -rf $(OBJECTS)
	make -C ./mlx clean
	echo "\n· Objects correctly removed."

fclean: clean
	rm -rf $(NAME)
	echo "· Executable correctly removed."
		
re:			fclean all
.PHONY:		all clean fclean re