CC = cc

CFLAGS = -Wall -Wextra -Werror -I./includes -MMD -g3

SRC =	sources/main.c \
		sources/init/parsing.c \
		sources/init/init.c \
		sources/mlx_utils/pixel_put.c \
		sources/mlx_utils/line_put.c \
		sources/mlx_input/mlx_ft.c \
		sources/mlx_input/movement.c \
		sources/raycasting/check_horizontal.c \
		sources/raycasting/calc_lenght_ray.c \
		sources/raycasting/check_vertical.c \
		sources/raycasting/raycasting.c

OBJS = $(SRC:.c=.o)

DEPS = $(SRC:.c=.d)

NAME = cub3D

all : $(NAME)

$(NAME) : $(OBJS)
	@make -s -C libft all 
	@make -s -C minilibx-linux all 
	@$(CC) $(OBJS) ./libft/libft.a ./minilibx-linux/libmlx.a -lX11 -lm -lXext -o $(NAME)
	@echo "Terminé!"

bonus : all

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean :
	@rm -f $(OBJS)
	@rm -f $(DEPS)
	@make -s -C libft clean

fclean : clean
	@rm -f $(NAME)
	@make -s -C libft fclean
	@make -s -C minilibx-linux clean

re : fclean all

-include $(PREFD)

.PHONY : all clean fclean re
