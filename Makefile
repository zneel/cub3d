NAME	:= cub3D
NAME_BNS := cub3D_bonus
CC 		:= cc
CFLAGS	:= -Wall -Wextra -Werror -I./includes -MMD
SRCS	:= sources/main.c \
		sources/helpers.c \
		sources/init/init.c \
		sources/init/init_image.c \
		sources/parsing/parsing.c \
		sources/parsing/file.c \
		sources/parsing/scene.c \
		sources/parsing/textures.c \
		sources/parsing/colors.c \
		sources/parsing/map.c \
		sources/parsing/check.c \
		sources/parsing/debug.c \
		sources/parsing/utils.c \
		sources/parsing/map_check.c \
		sources/parsing/player.c \
		sources/clear/clear_map.c \
		sources/clear/free_exit.c \
		sources/clear/destroy_exit.c \
		sources/display/print_background.c \
		sources/mlx_utils/get_color.c \
		sources/mlx_utils/pixel_put.c \
		sources/mlx_utils/line_put.c \
		sources/mlx_input/mlx_ft.c \
		sources/mlx_input/move_utils.c \
		sources/mlx_input/check_input.c \
		sources/mlx_input/rotate.c \
		sources/mlx_input/movement.c \
		sources/raycasting/print_texture.c \
		sources/raycasting/raycasting.c

SRCS_BNS := sources_bonus/main.c \
		sources_bonus/helpers.c \
		sources_bonus/init/init.c \
		sources_bonus/init/init_image.c \
		sources_bonus/parsing/parsing.c \
		sources_bonus/parsing/file.c \
		sources_bonus/parsing/scene.c \
		sources_bonus/parsing/textures.c \
		sources_bonus/parsing/colors.c \
		sources_bonus/parsing/map.c \
		sources_bonus/parsing/check.c \
		sources_bonus/parsing/debug.c \
		sources_bonus/parsing/utils.c \
		sources_bonus/parsing/map_check.c \
		sources_bonus/parsing/player.c \
		sources_bonus/clear/clear_map.c \
		sources_bonus/clear/free_exit.c \
		sources_bonus/clear/destroy_exit.c \
		sources_bonus/minimap/print_minimap.c \
		sources_bonus/minimap/draw_player.c \
		sources_bonus/minimap/draw_grid.c \
		sources_bonus/minimap/draw_obstacle.c \
		sources_bonus/display/print_background.c \
		sources_bonus/mlx_utils/get_color.c \
		sources_bonus/mlx_utils/pixel_put.c \
		sources_bonus/mlx_utils/line_put.c \
		sources_bonus/mlx_input/mlx_ft.c \
		sources_bonus/mlx_input/move_utils.c \
		sources_bonus/mlx_input/check_input.c \
		sources_bonus/mlx_input/hitbox.c \
		sources_bonus/mlx_input/rotate.c \
		sources_bonus/mlx_input/movement.c \
		sources_bonus/raycasting/print_texture.c \
		sources_bonus/raycasting/raycasting.c

OBJS := $(SRCS:.c=.o)
OBJS_BNS := $(SRCS_BNS:.c=.o)
DEPS := $(SRCS:.c=.d)
DEPS_BNS := $(SRCS_BNS:.c=.d)

INCLUDES := -Iincludes -Ilibft/includes -Imlx_linux
LIBS := -Llibft -lft -Lmlx_linux -lmlx -L/usr/lib -lXext -lX11 -lm -lz
LIBRARY := libft/libft.a mlx_linux/libmlx.a
MLX_PATH := mlx_linux
LIBFT_PATH := libft

ifeq ($(DEBUG), 1)
	CFLAGS+=-g3 -gdwarf-4
endif

ifeq ($(SAN), 1)
	CFLAGS+=-fsanitize=address -gdwarf-4
endif

ifeq ($(DEV), 1)
	CFLAGS+=-fsanitize=address -g3 -gdwarf-4
endif

all : $(NAME)

bonus : $(NAME_BNS)

$(NAME): $(LIBRARY) $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) -o $(NAME) $(OBJS) $(LIBRARY) $(LIBS)
	@echo "Terminé!"

$(NAME_BNS): $(LIBRARY) $(OBJS_BNS)
	$(CC) $(CFLAGS) $(INCLUDES) -o $(NAME_BNS) $(OBJS_BNS) $(LIBRARY) $(LIBS)
	@echo "Terminé!"

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIBRARY):
	make -j -sC $(MLX_PATH)
	make -j -sC $(LIBFT_PATH)

clean :
	rm -f $(OBJS)
	rm -f $(DEPS)
	rm -f $(OBJS_BNS)
	rm -f $(DEPS_BNS)
	make -sC mlx_linux clean
	make -sC libft clean
	@echo "Terminé!"

fclean : clean
	rm -f $(NAME)
	rm -f $(NAME)_bonus
	make -sC libft fclean
	@echo "Terminé!"

re : fclean all

-include $(DEPS)
-include $(DEPS_BNS)

.PHONY : all clean fclean re bonus
