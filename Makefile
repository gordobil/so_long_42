# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ngordobi <ngordobi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/10 11:52:23 by ngordobi          #+#    #+#              #
#    Updated: 2024/06/18 14:53:38 by ngordobi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	so_long

CC			=	gcc
CC_FLAGS	=	-Wall -Wextra -Werror -g3 -MMD

FT_PRINTF	=	./ft_printf/

SOURCES		=	1_so_long.c \
				2_check_file.c \
				3_load_map.c \
				4_check_map.c \
				5_check_map_aux.c \
				6_mlx_move.c \
				mlx_load_sprites.c \
				mlx_put_sprites.c \
				mlx_put_map.c \
				mlx_close_window.c \
				ft_count.c \
				ft_print_map.c \
				ft_free_map.c \

SOURCES_PF	=	$(FT_PRINTF)ft_printf.c \
				$(FT_PRINTF)ft_putchar.c \
				$(FT_PRINTF)ft_putstr.c \
				$(FT_PRINTF)ft_putnbr.c \
				$(FT_PRINTF)ft_putunbr.c \
				$(FT_PRINTF)ft_puthex.c \
				$(FT_PRINTF)ft_putptr.c \

OBJECTS		=	$(SOURCES:%.c=%.o)
OBJECTS_PF	=	$(SOURCES_PF:%.c=%.o)

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

$(NAME):	$(OBJECTS) $(OBJECTS_PF) $(INCLUDE)
			make -C ./mlx all
			$(CC) $(CC_FLAGS) $(OBJECTS) $(OBJECTS_PF) -o $(NAME) $(MLX_FLAGS)
			mkdir ./objects/
			mv $(OBJECTS) $(OBJECTS_PF) ./objects/
			echo "\n\n··················· Compilation complete ···················"
			echo "$$SO_LONG"

clean:
			rm -rf ./objects/
			rm -rf ./*.o
			rm -rf ./ft_printf/*.o
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
