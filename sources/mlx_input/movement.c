/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouvier <ebouvier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 17:28:48 by mhoyer            #+#    #+#             */
/*   Updated: 2023/09/28 15:12:39 by ebouvier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	degree_to_radians(double degree)
{
	return (degree * M_PI / 180);
}

double	calculate_player_direction(t_player *player)
{
	return (atan2(player->dir_y, player->dir_x));
}

void	key_w(t_game *game)
{
	game->player->x += game->player->dir_x * MOVE_SPEED;
	game->player->y += game->player->dir_y * MOVE_SPEED;
	game->player->pos_x = game->player->x / SIZE_CASE;
	game->player->pos_y = game->player->y / SIZE_CASE;
}

void	key_right(t_game *game)
{
	t_player	old;
	t_player	*current;

	ft_memcpy(&old, game->player, sizeof(t_player));
	current = game->player;
	current->dir_x = current->dir_x * cos(degree_to_radians(ROT_SPEED))
		- current->dir_y * sin(degree_to_radians(ROT_SPEED));
	current->dir_y = old.dir_x * sin(degree_to_radians(ROT_SPEED))
		+ current->dir_y * cos(degree_to_radians(ROT_SPEED));
	current->plane_x = current->plane_x * cos(degree_to_radians(ROT_SPEED))
		- current->plane_y * sin(degree_to_radians(ROT_SPEED));
	current->plane_y = old.plane_x * sin(degree_to_radians(ROT_SPEED))
		+ current->plane_y * cos(degree_to_radians(ROT_SPEED));
}

void	key_left(t_game *game)
{
	t_player	old;
	t_player	*current;

	ft_memcpy(&old, game->player, sizeof(t_player));
	current = game->player;
	current->dir_x = current->dir_x * cos(degree_to_radians(-ROT_SPEED))
		- current->dir_y * sin(degree_to_radians(-ROT_SPEED));
	current->dir_y = old.dir_x * sin(degree_to_radians(-ROT_SPEED))
		+ current->dir_y * cos(degree_to_radians(-ROT_SPEED));
	current->plane_x = current->plane_x * cos(degree_to_radians(-ROT_SPEED))
		- current->plane_y * sin(degree_to_radians(-ROT_SPEED));
	current->plane_y = old.plane_x * sin(degree_to_radians(-ROT_SPEED))
		+ current->plane_y * cos(degree_to_radians(-ROT_SPEED));
}

void	key_s(t_game *game)
{
	game->player->x -= game->player->dir_x * MOVE_SPEED;
	game->player->y -= game->player->dir_y * MOVE_SPEED;
	game->player->pos_x = game->player->x / SIZE_CASE;
	game->player->pos_y = game->player->y / SIZE_CASE;
}

void	key_d(t_game *game)
{
	double	facing_direction;

	facing_direction = calculate_player_direction(game->player);
	game->player->x += cos(facing_direction + M_PI_2) * MOVE_SPEED;
	game->player->y += sin(facing_direction + M_PI_2) * MOVE_SPEED;
	game->player->pos_x = game->player->x / SIZE_CASE;
	game->player->pos_y = game->player->y / SIZE_CASE;
}

void	key_a(t_game *game)
{
	double	facing_direction;

	facing_direction = calculate_player_direction(game->player);
	game->player->x += cos(facing_direction - M_PI_2) * MOVE_SPEED;
	game->player->y += sin(facing_direction - M_PI_2) * MOVE_SPEED;
	game->player->pos_x = game->player->x / SIZE_CASE;
	game->player->pos_y = game->player->y / SIZE_CASE;
}

int	check_press(int key, t_game *game)
{
	if (key == XK_w)
		game->player->move[0] = true;
	if (key == XK_s)
		game->player->move[1] = true;
	if (key == XK_a)
		game->player->move[2] = true;
	if (key == XK_d)
		game->player->move[3] = true;
	if (key == XK_Left)
		game->player->move[4] = true;
	if (key == XK_Right)
		game->player->move[5] = true;
	if (key == XK_Escape)
		close_game(game);
	return (0);
}

int	check_release(int key, t_game *game)
{
	if (key == XK_w)
		game->player->move[0] = false;
	if (key == XK_s)
		game->player->move[1] = false;
	if (key == XK_a)
		game->player->move[2] = false;
	if (key == XK_d)
		game->player->move[3] = false;
	if (key == XK_Left)
		game->player->move[4] = false;
	if (key == XK_Right)
		game->player->move[5] = false;
	return (0);
}

void	do_move(t_game *game)
{
	if (game->player->move[0])
		key_w(game);
	if (game->player->move[1])
		key_s(game);
	if (game->player->move[2])
		key_a(game);
	if (game->player->move[3])
		key_d(game);
	if (game->player->move[4])
		key_left(game);
	if (game->player->move[5])
		key_right(game);
}
