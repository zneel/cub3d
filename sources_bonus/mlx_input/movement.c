/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoyer <mhoyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 17:28:48 by mhoyer            #+#    #+#             */
/*   Updated: 2023/09/30 12:49:30 by mhoyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	hitbox(t_game *game, double old_x, double old_y)
{
	if (game->map.map[(int)game->player->y / SIZE_CASE][(int)game->player->x / SIZE_CASE] == 1)
	{
		game->player->x = old_x;
		game->player->y = old_y;
	}
}

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
	double	old_x;
	double	old_y;

	old_x = game->player->x;
	old_y = game->player->y;
	game->player->x += game->player->dir_x * MOVE_SPEED;
	game->player->y += game->player->dir_y * MOVE_SPEED;
	hitbox(game, old_x, old_y);
	reset_co(game);
	game->player->pos_x = game->player->x / SIZE_CASE;
	game->player->pos_y = game->player->y / SIZE_CASE;
}

void	key_s(t_game *game)
{
	double	old_x;
	double	old_y;

	old_x = game->player->x;
	old_y = game->player->y;
	game->player->x -= game->player->dir_x * MOVE_SPEED;
	game->player->y -= game->player->dir_y * MOVE_SPEED;
	hitbox(game, old_x, old_y);
	reset_co(game);
	game->player->pos_x = game->player->x / SIZE_CASE;
	game->player->pos_y = game->player->y / SIZE_CASE;
}

void	key_d(t_game *game)
{
	double	facing_direction;
	double	old_x;
	double	old_y;

	old_x = game->player->x;
	old_y = game->player->y;
	facing_direction = calculate_player_direction(game->player);
	game->player->x += cos(facing_direction + M_PI_2) * MOVE_SPEED;
	game->player->y += sin(facing_direction + M_PI_2) * MOVE_SPEED;
	hitbox(game, old_x, old_y);
	reset_co(game);
	game->player->pos_x = game->player->x / SIZE_CASE;
	game->player->pos_y = game->player->y / SIZE_CASE;
}

void	key_a(t_game *game)
{
	double	facing_direction;
	double	old_x;
	double	old_y;

	old_x = game->player->x;
	old_y = game->player->y;
	facing_direction = calculate_player_direction(game->player);
	game->player->x += cos(facing_direction - M_PI_2) * MOVE_SPEED;
	game->player->y += sin(facing_direction - M_PI_2) * MOVE_SPEED;
	hitbox(game, old_x, old_y);
	reset_co(game);
	game->player->pos_x = game->player->x / SIZE_CASE;
	game->player->pos_y = game->player->y / SIZE_CASE;
}
