/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoyer <mhoyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 19:31:48 by mhoyer            #+#    #+#             */
/*   Updated: 2023/09/28 19:32:18 by mhoyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
