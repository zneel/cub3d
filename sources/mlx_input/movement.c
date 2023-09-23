/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoyer <mhoyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 17:28:48 by mhoyer            #+#    #+#             */
/*   Updated: 2023/09/16 17:33:01 by mhoyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	key_w(t_game *game)
{
	game->player.x += game->player.delta_x;
	game->player.y += game->player.delta_y;
}

void	key_a(t_game *game)
{
	game->player.angle -=0.1;
	if (game->player.angle <= 0)
		game->player.angle += 2 * PI;
	game->player.delta_x = cos(game->player.angle) * 5;
	game->player.delta_y = sin(game->player.angle) * 5;
}

void	key_s(t_game *game)
{
	game->player.x -= game->player.delta_x;
	game->player.y -= game->player.delta_y;
}

void	key_d(t_game *game)
{
	game->player.angle +=0.1;
	if (game->player.angle >= 2 * PI)
		game->player.angle -= 2 * PI;
	game->player.delta_x = cos(game->player.angle) * 5;
	game->player.delta_y = sin(game->player.angle) * 5;
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
	if (key == XK_Escape)
		close_game(game);
	return (0);
}