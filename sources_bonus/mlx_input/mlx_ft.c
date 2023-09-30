/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_ft.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoyer <mhoyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 10:29:27 by mhoyer            #+#    #+#             */
/*   Updated: 2023/09/29 13:23:22 by mhoyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

int	close_game(t_game *game)
{
	free_exit(game);
	destroy_exit(game);
	exit(0);
}

int	loop(t_game *game)
{
	do_move(game);
	print_background(game);
	raycast(game);
	print_minimap(game, 0, 0);
	mlx_put_image_to_window(game->mlx, game->win, game->buffer->img, 0, 0);
	return (0);
}
