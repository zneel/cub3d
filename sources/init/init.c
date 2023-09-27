/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouvier <ebouvier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 16:58:28 by mhoyer            #+#    #+#             */
/*   Updated: 2023/09/27 16:04:49 by ebouvier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_player(t_game *game)
{
	game->player = malloc(sizeof(t_player));
	// handle malloc error
	game->player->pos_x = 9;
	game->player->pos_y = 2;
	game->player->x = SIZE_CASE * game->player->pos_x;
	game->player->y = SIZE_CASE * game->player->pos_y;
	game->player->dir_x = -1;
	game->player->dir_y = 0;
	game->player->plane_x = 0;
	game->player->plane_y = 0.66;
}

void	init_map(t_map *map)
{
	map->x_max = 0;
	map->y_max = 0;
	map->map = NULL;
	map->data = (t_map_data){NULL, NULL, NULL, NULL, -1, -1};
}

void	init_game(t_game *game)
{
	game->x_win = 1600;
	game->y_win = 1200;
	game->time = 0;
	game->old_time = 0;
	game->mlx = mlx_init();
	if (!game->mlx)
		error_and_exit("mlx_init() failed.");
	game->win = mlx_new_window(game->mlx, game->x_win, game->y_win, "cub3D");
	game->buffer.img = mlx_new_image(game->mlx, game->x_win, game->y_win);
	game->buffer.addr = mlx_get_data_addr(game->buffer.img,
			&game->buffer.bit_per_pixel, &game->buffer.line_length,
			&game->buffer.endian);
}
