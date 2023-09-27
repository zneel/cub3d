/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouvier <ebouvier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 17:28:48 by mhoyer            #+#    #+#             */
/*   Updated: 2023/09/27 15:40:12 by ebouvier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	key_w(t_game *game)
{
	game->player->x += game->player->dir_x * MOVE_SPEED;
	game->player->y += game->player->dir_y * MOVE_SPEED;
	game->player->pos_x = game->player->x / SIZE_CASE;
	game->player->pos_y = game->player->y / SIZE_CASE;
}

void	key_left(t_game *game)
{
	t_player	old;
	t_player	*current;

	ft_memcpy(&old, game->player, sizeof(t_player));
	current = game->player;
	current->dir_x = current->dir_x * cos(ROT_SPEED) - current->dir_y
		* sin(ROT_SPEED);
	current->dir_y = old.dir_x * sin(ROT_SPEED) + current->dir_y
		* cos(ROT_SPEED);
	current->plane_x = current->plane_x * cos(ROT_SPEED) - current->plane_y
		* sin(ROT_SPEED);
	current->plane_y = old.plane_x * sin(ROT_SPEED) + current->plane_y
		* cos(ROT_SPEED);
}

void	key_right(t_game *game)
{
	t_player	old;
	t_player	*current;

	ft_memcpy(&old, game->player, sizeof(t_player));
	current = game->player;
	current->dir_x = current->dir_x * cos(-ROT_SPEED) - current->dir_y
		* sin(-ROT_SPEED);
	current->dir_y = old.dir_x * sin(-ROT_SPEED) + current->dir_y
		* cos(-ROT_SPEED);
	current->plane_x = current->plane_x * cos(-ROT_SPEED) - current->plane_y
		* sin(-ROT_SPEED);
	current->plane_y = old.plane_x * sin(-ROT_SPEED) + current->plane_y
		* cos(-ROT_SPEED);
}

void	key_s(t_game *game)
{
	game->player->x -= game->player->dir_x * MOVE_SPEED;
	game->player->y -= game->player->dir_y * MOVE_SPEED;
	game->player->pos_x = game->player->x / SIZE_CASE;
	game->player->pos_y = game->player->y / SIZE_CASE;
}

void	key_a(t_game *game)
{
	game->player->x += game->player->dir_x * MOVE_SPEED;
	game->player->y -= game->player->dir_y * MOVE_SPEED;
	game->player->pos_x = game->player->x / SIZE_CASE;
	game->player->pos_y = game->player->y / SIZE_CASE;
}

void	key_d(t_game *game)
{
	game->player->x -= game->player->dir_x * MOVE_SPEED;
	game->player->y += game->player->dir_y * MOVE_SPEED;
	game->player->pos_x = game->player->x / SIZE_CASE;
	game->player->pos_y = game->player->y / SIZE_CASE;
}

int	check_input(int key, t_game *game)
{
	if (key == XK_w)
		key_w(game);
	if (key == XK_a)
		key_a(game);
	if (key == XK_s)
		key_s(game);
	if (key == XK_d)
		key_d(game);
	if (key == XK_Left)
		key_left(game);
	if (key == XK_Right)
		key_right(game);
	if (key == XK_Escape)
		close_game(game);
	return (0);
}
