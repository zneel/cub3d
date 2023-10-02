/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouvier <ebouvier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 16:58:28 by mhoyer            #+#    #+#             */
/*   Updated: 2023/10/02 15:33:58 by ebouvier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_camera_plane(t_game *game)
{
	if (game->map.data.dir == PN)
	{
		game->player->plane_x = 2 * atan(0.66 / 1);
		game->player->plane_y = 0;
	}
	else if (game->map.data.dir == PS)
	{
		game->player->plane_x = -2 * atan(0.66 / 1);
		game->player->plane_y = 0;
	}
	else if (game->map.data.dir == PW)
	{
		game->player->plane_x = 0;
		game->player->plane_y = -2 * atan(0.66 / 1);
	}
	else if (game->map.data.dir == PE)
	{
		game->player->plane_x = 0;
		game->player->plane_y = 2 * atan(0.66 / 1);
	}
}

void	init_player(t_game *game)
{
	int	i;

	i = -1;
	game->player = malloc(sizeof(t_player));
	if (!game->player)
	{
		close_game(game);
		exit(1);
	}
	game->player->pos_x = game->map.data.spawn.x + 0.5;
	game->player->pos_y = game->map.data.spawn.y + 0.5;
	game->player->x = SIZE_CASE * game->player->pos_x;
	game->player->y = SIZE_CASE * game->player->pos_y;
	game->player->dir_x = game->map.data.spawn.dir.x;
	game->player->dir_y = game->map.data.spawn.dir.y;
	game->player->plane_x = 0;
	game->player->plane_y = 0.66;
	while (++i < 6)
		game->player->move[i] = false;
	set_camera_plane(game);
}

void	init_map(t_map *map)
{
	map->x_max = 0;
	map->y_max = 0;
	map->map = NULL;
	map->data = (t_map_data){NULL, 0, NULL, 0, NULL, 0, NULL, 0, 0, 0, -1, 0,
		(t_vec3){-1, -1, (t_vec2){0, 1}}, PN};
}

void	init_game(t_game *game)
{
	game->x_win = X_SCREEN;
	game->y_win = Y_SCREEN;
	game->mlx = mlx_init();
	if (!game->mlx)
		error_and_exit("mlx_init() failed.");
	init_pgrm_img(game);
}
