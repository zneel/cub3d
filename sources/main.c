/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouvier <ebouvier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 14:49:03 by mhoyer            #+#    #+#             */
/*   Updated: 2023/09/24 21:31:41 by ebouvier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_mat(char **map)
{
	int	x;
	int	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			printf("%c", map[y][x]);
			x++;
		}
		printf("\n");
		y++;
	}
}

void	print_array(t_game game)
{
	int	i;

	i = 0;
	while (game.map.array[i])
	{
		if (i % game.map.x_max == 0)
			printf("\n");
		printf("%c", game.map.array[i]);
		i++;
	}
	printf("\n");
}

void	print_obs(t_game *game, int x_start, int y_start, unsigned int color)
{
	int	x;
	int	y;

	x = x_start;
	while (x <= x_start + SIZE_CASE)
	{
		y = y_start;
		while (y <= y_start + SIZE_CASE)
		{
			my_mlx_pixel_put(&game->buffer, x, y, color);
			y++;
		}
		x++;
	}
}

void	draw_obs(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map.map[y])
	{
		x = 0;
		while (game->map.map[y][x])
		{
			if (game->map.map[y][x] == '1')
				print_obs(game, x * SIZE_CASE, y * SIZE_CASE, 0xFFFFFF);
			else
				print_obs(game, x * SIZE_CASE, y * SIZE_CASE, 0x000000);
			x++;
		}
		y++;
	}
}

void	draw_player(t_game *game)
{
	int	x;
	int	y;

	x = game->player.x;
	while (x < game->player.x + SIZE_PLAYER)
	{
		y = game->player.y;
		while (y < game->player.y + SIZE_PLAYER)
		{
			my_mlx_pixel_put(&game->buffer, x, y, 0xFFFF00);
			y++;
		}
		x++;
	}
	game->player.center_x = game->player.x + SIZE_PLAYER / 2;
	game->player.center_y = game->player.y + SIZE_PLAYER / 2;
}

void	draw_grid(t_game *game)
{
	int	x;
	int	y;

	x = SIZE_CASE;
	while (x < game->map.x_max * SIZE_CASE)
	{
		y = 0;
		while (y < game->map.y_max * SIZE_CASE)
		{
			my_mlx_pixel_put(&game->buffer, x, y, 0x606060);
			y++;
		}
		x += SIZE_CASE;
	}
	y = SIZE_CASE;
	while (y < game->map.y_max * SIZE_CASE)
	{
		x = 0;
		while (x < game->map.x_max * SIZE_CASE)
		{
			my_mlx_pixel_put(&game->buffer, x, y, 0x606060);
			x++;
		}
		y += SIZE_CASE;
	}
}

void	init_cub3d(t_game *game)
{
	init_game(game);
	init_player(game);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		error_and_exit("Usage: ./cub3D <map.cub>");
	init_map(&game.map);
	if (!parse_cubfile(argv[1], &game.map))
		exit(1);
	destroy_map(&game.map);
	// print_mat(game.map.map);
	// print_array(game);
	// mlx_loop_hook(game.mlx, &loop, &game);
	// mlx_hook(game.win, KeyPress, KeyPressMask, &check_input, &game);
	// mlx_hook(game.win, 17, 0, &close_game, &game);
	// mlx_loop(game.mlx);
	return (0);
}
