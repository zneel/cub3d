/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hitbox.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoyer <mhoyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 21:19:18 by mhoyer            #+#    #+#             */
/*   Updated: 2023/10/02 21:30:45 by mhoyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	protection(t_game *game)
{
	if (!((int)(game->player->y / SIZE_CASE) < game->map.y_max
		&& (int)(game->player->x / SIZE_CASE) < game->map.x_max
			&& (int)(game->player->y / SIZE_CASE) >= 0 && (int)(game->player->x
				/ SIZE_CASE) >= 0))
		return (1);
	return (0);
}

int	is_wall(t_game *game, double old_x, double old_y)
{
	if (game->map.map[(int)game->player->y / SIZE_CASE][(int)game->player->x
		/ SIZE_CASE] == 1)
	{
		game->player->x = old_x;
		game->player->y = old_y;
		return (1);
	}
	return (0);
}

void	bot_side(t_game *game, double old_x, double old_y, double player_dir)
{
	if (player_dir < 180 && player_dir >= 90
		&& game->map.map[(int)game->player->pos_y][(int)game->player->pos_x
		- 1] == 1 && game->map.map[(int)game->player->pos_y
		+ 1][(int)game->player->pos_x] == 1)
	{
		game->player->x = old_x;
		game->player->y = old_y;
	}
	if (player_dir < 90 && player_dir >= 0
		&& game->map.map[(int)game->player->pos_y][(int)game->player->pos_x
		+ 1] == 1 && game->map.map[(int)game->player->pos_y
		+ 1][(int)game->player->pos_x] == 1)
	{
		game->player->x = old_x;
		game->player->y = old_y;
	}
}

void	top_side(t_game *game, double old_x, double old_y, double player_dir)
{
	if (player_dir < 0 && player_dir >= -90
		&& game->map.map[(int)game->player->pos_y][(int)game->player->pos_x
		+ 1] == 1 && game->map.map[(int)game->player->pos_y
		- 1][(int)game->player->pos_x] == 1)
	{
		game->player->x = old_x;
		game->player->y = old_y;
	}
	if (player_dir < -90 && player_dir >= -180
		&& game->map.map[(int)game->player->pos_y][(int)game->player->pos_x
		- 1] == 1 && game->map.map[(int)game->player->pos_y
		- 1][(int)game->player->pos_x] == 1)
	{
		game->player->x = old_x;
		game->player->y = old_y;
	}
}

void	hitbox(t_game *game, double old_x, double old_y, double player_dir)
{
	if (protection(game))
		return ;
	if (is_wall(game, old_x, old_y))
		return ;
	if (floor(game->player->y / SIZE_CASE) != floor(old_y / SIZE_CASE)
		&& floor(game->player->x / SIZE_CASE) != floor(old_x / SIZE_CASE)
		&& (game->map.map[(int)floor(game->player->y
					/ SIZE_CASE)][(int)floor(game->player->x
				/ SIZE_CASE)] == SPACE
		|| game->map.map[(int)floor(game->player->y
				/ SIZE_CASE)][(int)floor(game->player->x
		/ SIZE_CASE)] == EMPTY))
	{
		bot_side(game, old_x, old_y, player_dir);
		top_side(game, old_x, old_y, player_dir);
	}
}
