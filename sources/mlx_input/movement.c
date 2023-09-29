/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoyer <mhoyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 17:28:48 by mhoyer            #+#    #+#             */
/*   Updated: 2023/09/29 13:25:07 by mhoyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	reset_co(t_game *game)
{
	if (game->player->x < 0)
		game->player->x = game->map.x_max * SIZE_CASE;
	if (game->player->y < 0)
		game->player->y = game->map.y_max * SIZE_CASE;
	if (game->player->x > game->map.x_max * SIZE_CASE)
		game->player->x = 0;
	if (game->player->y > game->map.y_max * SIZE_CASE)
		game->player->y = 0;
}

void	key_w(t_game *game)
{
	game->player->x += game->player->dir_x * MOVE_SPEED;
	game->player->y += game->player->dir_y * MOVE_SPEED;
	reset_co(game);
	game->player->pos_x = game->player->x / SIZE_CASE;
	game->player->pos_y = game->player->y / SIZE_CASE;
}

void	key_s(t_game *game)
{
	game->player->x -= game->player->dir_x * MOVE_SPEED;
	game->player->y -= game->player->dir_y * MOVE_SPEED;
	reset_co(game);
	game->player->pos_x = game->player->x / SIZE_CASE;
	game->player->pos_y = game->player->y / SIZE_CASE;
}

void	key_d(t_game *game)
{
	double	facing_direction;

	facing_direction = calculate_player_direction(game->player);
	game->player->x += cos(facing_direction + M_PI_2) * MOVE_SPEED;
	game->player->y += sin(facing_direction + M_PI_2) * MOVE_SPEED;
	reset_co(game);
	game->player->pos_x = game->player->x / SIZE_CASE;
	game->player->pos_y = game->player->y / SIZE_CASE;
}

void	key_a(t_game *game)
{
	double	facing_direction;

	facing_direction = calculate_player_direction(game->player);
	game->player->x += cos(facing_direction - M_PI_2) * MOVE_SPEED;
	game->player->y += sin(facing_direction - M_PI_2) * MOVE_SPEED;
	reset_co(game);
	game->player->pos_x = game->player->x / SIZE_CASE;
	game->player->pos_y = game->player->y / SIZE_CASE;
}
