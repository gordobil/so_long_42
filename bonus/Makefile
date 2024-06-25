# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ngordobi <ngordobi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/10 11:52:23 by ngordobi          #+#    #+#              #
#    Updated: 2024/06/24 12:44:27 by ngordobi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				=	so_long_bonus

CC					=	gcc
CC_FLAGS			=	-Wall -Wextra -Werror -g3 -MMD

UTILS				=	../utils/
FT_PRINTF			=	../utils/ft_printf/

MLX					=	../mlx/libmlx_Linux.a
MLX_FLAGS			=	-L ../mlx/ -lmlx -lXext -lX11

SOURCES				=	1_so_long_bonus.c \
						2_check_file_bonus.c \
						3_load_map_bonus.c \
						4_check_map_bonus.c \
						5_find_exit_bonus.c \
						6_mlx_move_bonus.c \

SOURCES_UT			=	$(UTILS)ft_count.c \
						$(UTILS)ft_print_map.c \
						$(UTILS)ft_free_map.c \
						$(UTILS)ft_itoa.c \
						$(UTILS)ft_borders.c \
						$(UTILS)ft_characters_ret.c \
						$(UTILS)ft_start_coords.c \
						$(UTILS)mlx_load_sprites.c \
						$(UTILS)mlx_put_sprites.c \
						$(UTILS)mlx_put_map_bonus.c \
						$(UTILS)mlx_put_messages.c \
						$(UTILS)mlx_close_window_bonus.c \
						$(UTILS)mlx_destroy_sprites.c \

SOURCES_PF			=	$(FT_PRINTF)ft_printf.c \
						$(FT_PRINTF)ft_putchar.c \
						$(FT_PRINTF)ft_putstr.c \
						$(FT_PRINTF)ft_putnbr.c \
						$(FT_PRINTF)ft_putunbr.c \
						$(FT_PRINTF)ft_puthex.c \
						$(FT_PRINTF)ft_putptr.c \

OBJECTS				=	$(SOURCES:%.c=%.o)
OBJECTS_UT			=	$(SOURCES_UT:%.c=%.o)
OBJECTS_PF			=	$(SOURCES_PF:%.c=%.o)

INCLUDE				=	../so_long.h

define SO_LONG_BONUS
\033[0;33m

  ██████  ▒█████      ██▓     ▒█████   ███▄    █   ▄████ 
▒██    ▒ ▒██▒  ██▒   ▓██▒    ▒██▒  ██▒ ██ ▀█   █  ██▒ ▀█▒
░ ▓██▄   ▒██░  ██▒   ▒██░    ▒██░  ██▒▓██  ▀█ ██▒▒██░▄▄▄░
  ▒   ██▒▒██   ██░   ▒██░    ▒██   ██░▓██▒  ▐▌██▒░▓█  ██▓
▒██████▒▒░ ████▓▒░   ░██████▒░ ████▓▒░▒██░   ▓██░░▒▓███▀▒
▒ ▒▓▒ ▒ ░░ ▒░▒░▒░    ░ ▒░▓  ░░ ▒░▒░▒░ ░ ▒░   ▒ ▒  ░▒   ▒ 
░ ░▒  ░ ░  ░ ▒ ▒░    ░ ░ ▒  ░  ░ ▒ ▒░ ░ ░░   ░ ▒░  ░   ░ 
░  ░  ░  ░ ░ ░ ▒       ░ ░   ░ ░ ░ ▒     ░   ░ ░ ░ ░   ░ 
      ░▄▄▄▄  ░ ▒█████   ███▄░   █░ █    ██   ██████    ░ 
      ▓█████▄ ▒██▒  ██▒ ██ ▀█   █  ██  ▓██▒▒██    ▒      
      ▒██▒ ▄██▒██░  ██▒▓██  ▀█ ██▒▓██  ▒██░░ ▓██▄        
      ▒██░█▀  ▒██   ██░▓██▒  ▐▌██▒▓▓█  ░██░  ▒   ██▒     
      ░▓█  ▀█▓░ ████▓▒░▒██░   ▓██░▒▒█████▓ ▒██████▒▒     
      ░▒▓███▀▒░ ▒░▒░▒░ ░ ▒░   ▒ ▒ ░▒▓▒ ▒ ▒ ▒ ▒▓▒ ▒ ░     
      ▒░▒   ░   ░ ▒ ▒░ ░ ░░   ░ ▒░░░▒░ ░ ░ ░ ░▒  ░ ░     
       ░    ░ ░ ░ ░ ▒     ░   ░ ░  ░░░ ░ ░ ░  ░  ░       
       ░          ░ ░           ░    ░           ░       
            ░                                            

$(END)
endef
export SO_LONG_BONUS

.SILENT:

all: 			$(NAME)

$(NAME):		$(OBJECTS) $(OBJECTS_UT) $(OBJECTS_PF) $(INCLUDE)
				make -C ../mlx all
				$(CC) $(CC_FLAGS) $(OBJECTS) $(OBJECTS_UT) $(OBJECTS_PF) -o $(NAME) $(MLX_FLAGS)
				mkdir ./objects/
				mkdir ../utils/objects/
				mkdir ../utils/ft_printf/objects/
				mv $(OBJECTS) ./objects/
				mv $(OBJECTS_UT) ../utils/objects/
				mv $(OBJECTS_PF) ../utils/ft_printf/objects/
				echo "\n\n················ Bonus compilation complete ················"
				echo "$$SO_LONG_BONUS"

clean:
				rm -rf ./objects/
				rm -rf ./*.o
				rm -rf ../utils/objects/
				rm -rf ../utils/*.o
				rm -rf ../utils/ft_printf/objects/
				rm -rf ../utils/ft_printf/*.o
				make -C ../mlx clean
				echo "\n·····································"
				echo "\n· Bonus objects correctly removed."

fclean:			clean
				rm -rf $(NAME)
				echo "· Bonus executable correctly removed."

nl:
				echo "\n·····································"

re:				fclean nl all
.PHONY:			all clean fclean nl re
