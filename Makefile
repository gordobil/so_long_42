# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ngordobi <ngordobi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/10 11:52:23 by ngordobi          #+#    #+#              #
#    Updated: 2024/06/19 14:35:25 by ngordobi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				=	so_long
NAME_BONUS			=	so_long_bonus

CC					=	gcc
CC_FLAGS			=	-Wall -Wextra -Werror -g3 -MMD

UTILS				=	./utils/
FT_PRINTF			=	./utils/ft_printf/
BONUS				=	./bonus/

SOURCES				=	1_so_long.c \
						2_check_file.c \
						3_load_map.c \
						4_check_map.c \
						5_find_exit.c \
						6_mlx_move.c \

SOURCES_BONUS		=	$(BONUS)1_so_long_bonus.c \
						$(BONUS)2_check_file_bonus.c \
						$(BONUS)3_load_map_bonus.c \
						$(BONUS)4_check_map_bonus.c \
						$(BONUS)5_find_exit_bonus.c \
						$(BONUS)6_mlx_move_bonus.c \

SOURCES_UT			=	$(UTILS)ft_count.c \
						$(UTILS)ft_print_map.c \
						$(UTILS)ft_free_map.c \
						$(UTILS)ft_itoa.c \
						$(UTILS)ft_borders.c \
						$(UTILS)ft_characters_ret.c \
						$(UTILS)ft_start_coords.c \
						$(UTILS)mlx_load_sprites.c \
						$(UTILS)mlx_put_sprites.c \
						$(UTILS)mlx_put_map.c \
						$(UTILS)mlx_put_map_bonus.c \
						$(UTILS)mlx_close_window.c \

SOURCES_PF			=	$(FT_PRINTF)ft_printf.c \
						$(FT_PRINTF)ft_putchar.c \
						$(FT_PRINTF)ft_putstr.c \
						$(FT_PRINTF)ft_putnbr.c \
						$(FT_PRINTF)ft_putunbr.c \
						$(FT_PRINTF)ft_puthex.c \
						$(FT_PRINTF)ft_putptr.c \

OBJECTS				=	$(SOURCES:%.c=%.o)
OBJECTS_BONUS		=	$(SOURCES_BONUS:%.c=%.o)
OBJECTS_UT			=	$(SOURCES_UT:%.c=%.o)
OBJECTS_PF			=	$(SOURCES_PF:%.c=%.o)

INCLUDE				=	so_long.h

MLX					=	./mlx/libmlx_Linux.a
MLX_FLAGS			=	-L mlx/ -lmlx -lXext -lX11

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
bonus:			$(NAME_BONUS)

$(NAME):		$(OBJECTS) $(OBJECTS_UT) $(OBJECTS_PF) $(INCLUDE)
				make -C ./mlx all
				$(CC) $(CC_FLAGS) $(OBJECTS) $(OBJECTS_UT) $(OBJECTS_PF) -o $(NAME) $(MLX_FLAGS)
				mkdir ./objects/
				mkdir ./utils/objects/
				mkdir ./utils/ft_printf/objects/
				mv $(OBJECTS) ./objects/
				mv $(OBJECTS_UT) ./utils/objects/
				mv $(OBJECTS_PF) ./utils/ft_printf/objects/
				echo "\n\n··················· Compilation complete ···················"
				echo "$$SO_LONG"

$(NAME_BONUS):	$(OBJECTS_BONUS) $(OBJECTS_UT) $(OBJECTS_PF) $(INCLUDE)
				make -C ./mlx all
				$(CC) $(CC_FLAGS) $(OBJECTS_BONUS) $(OBJECTS_UT) $(OBJECTS_PF) -o $(NAME) $(MLX_FLAGS)
				mkdir ./objects/
				mkdir ./utils/objects/
				mkdir ./utils/ft_printf/objects/
				mv $(OBJECTS_BONUS) ./objects/
				mv $(OBJECTS_UT) ./utils/objects/
				mv $(OBJECTS_PF) ./utils/ft_printf/objects/
				echo "\n\n··············· Bonus compilation complete ···············"
				echo "$$SO_LONG_BONUS"

clean:
				rm -rf ./objects/
				rm -rf ./*.o
				rm -rf ./bonus/objects/
				rm -rf ./bonus/*.o
				rm -rf ./utils/objects/
				rm -rf ./utils/*.o
				rm -rf ./utils/ft_printf/objects/
				rm -rf ./utils/ft_printf/*.o
				make -C ./mlx clean
				echo "\n·······························"
				echo "\n· Objects correctly removed."

fclean:			clean
				rm -rf $(NAME) $(NAME_BONUS)
				echo "· Executable correctly removed."

nl:
				echo "\n·······························"

re:				fclean nl all
re bonus:		fclean nl bonus
.PHONY:			all bonus clean fclean nl re
