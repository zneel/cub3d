/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouvier <ebouvier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 16:58:28 by mhoyer            #+#    #+#             */
/*   Updated: 2023/09/26 16:19:38 by ebouvier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_player(t_game *game)
{
	game->player.x = SIZE_CASE + 19;
	game->player.y = SIZE_CASE + 19;
	game->player.angle = 0;
	game->player.delta_x = cos(game->player.angle) * 5;
	game->player.delta_y = sin(game->player.angle) * 5;
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
	game->x_win = 1900;
	game->y_win = 1000;
	game->fov = 60;
	game->mlx = mlx_init();
	if (!game->mlx)
		error_and_exit("mlx_init() failed.");
	game->win = mlx_new_window(game->mlx, game->x_win, game->y_win, "cub3D");
	game->buffer.img = mlx_new_image(game->mlx, game->x_win, game->y_win);
	game->buffer.addr = mlx_get_data_addr(game->buffer.img,
			&game->buffer.bit_per_pixel, &game->buffer.line_length,
			&game->buffer.endian);
}
