/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoyer <mhoyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 16:58:28 by mhoyer            #+#    #+#             */
/*   Updated: 2023/09/28 13:55:22 by mhoyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_player(t_game *game)
{
	int i;

	i = -1;
	game->player = malloc(sizeof(t_player));
	// handle malloc error
	game->player->pos_x = game->map.data.spawn.x;
	game->player->pos_y = game->map.data.spawn.y;
	game->player->x = SIZE_CASE * game->player->pos_x;
	game->player->y = SIZE_CASE * game->player->pos_y;
	game->player->dir_x = game->map.data.spawn.dir.x;
	game->player->dir_y = game->map.data.spawn.dir.y;
	game->player->plane_x = 0;
	game->player->plane_y = 0.66;
	while (++i < 6)
	{
		game->player->move[i] = false;
	}
}

void	init_map(t_map *map)
{
	map->x_max = 0;
	map->y_max = 0;
	map->map = NULL;
	map->data = (t_map_data){NULL, false, NULL, false, NULL, false, NULL, false,
		-1, -1, (t_vec3){-1, -1, (t_vec2){0, 1}}};
}

void	init_background(t_game *game)
{
	int	x;
	int	y;

	y = -1;
	while (++y < game->y_win)
	{
		x = -1;
		while (++x < game->x_win)
		{
			if (y < game->y_win / 2)
				my_mlx_pixel_put(&game->background, x, y, game->map.data.floor);
			else
				my_mlx_pixel_put(&game->background, x, y,
					game->map.data.ceiling);
		}
	}
}

void	init_game(t_game *game)
{
	game->x_win = X_SCREEN;
	game->y_win = Y_SCREEN;
	game->mlx = mlx_init();
	if (!game->mlx)
		error_and_exit("mlx_init() failed.");
	game->win = mlx_new_window(game->mlx, game->x_win, game->y_win, "cub3D");
	game->background.img = mlx_new_image(game->mlx, game->x_win, game->y_win);
	game->background.addr = mlx_get_data_addr(game->background.img,
			&game->background.bit_per_pixel, &game->background.line_length,
			&game->background.endian);
	init_background(game);
	game->buffer.img = mlx_new_image(game->mlx, game->x_win, game->y_win);
	game->buffer.addr = mlx_get_data_addr(game->buffer.img,
			&game->buffer.bit_per_pixel, &game->buffer.line_length,
			&game->buffer.endian);
}
