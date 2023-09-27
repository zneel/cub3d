NAME	:= cub3D
CC 		:= cc
CFLAGS	:= -Wall -Wextra -Werror -I./includes -MMD
SRCS	:= sources/main.c \
		sources/helpers.c \
		sources/init/init.c \
		sources/parsing/parsing.c \
		sources/parsing/file.c \
		sources/parsing/scene.c \
		sources/parsing/textures.c \
		sources/parsing/colors.c \
		sources/parsing/map.c \
		sources/parsing/check.c \
		sources/parsing/debug.c \
		sources/parsing/utils.c \
		sources/parsing/flood_fill.c \
		sources/clear/clear_map.c \
		sources/minimap/print_minimap.c \
		sources/mlx_utils/pixel_put.c \
		sources/mlx_utils/line_put.c \
		sources/mlx_input/mlx_ft.c \
		sources/mlx_input/movement.c \
		sources/raycasting/raycasting.c

OBJS := $(SRCS:.c=.o)
DEPS := $(SRCS:.c=.d)

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

$(NAME): $(LIBRARY) $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) -o $(NAME) $(OBJS) $(LIBRARY) $(LIBS)
	@echo "Terminé!"

bonus: all

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIBRARY):
	make -j -sC $(MLX_PATH)
	make -j -sC $(LIBFT_PATH)

clean :
	rm -f $(OBJS)
	rm -f $(DEPS)
	make -sC mlx_linux clean
	make -sC libft clean
	@echo "Terminé!"

fclean : clean
	rm -f $(NAME)
	make -sC mlx_linux clean
	make -sC libft fclean
	@echo "Terminé!"

re : fclean all
.PHONY : all clean fclean re
