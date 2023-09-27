/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_ft.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouvier <ebouvier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 10:29:27 by mhoyer            #+#    #+#             */
/*   Updated: 2023/09/27 15:03:27 by ebouvier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	close_game(t_game *game)
{
	(void)game;
	exit(0);
	return (0);
}

int	loop(t_game *game)
{
	// draw_ray(game, true);
	draw_obs(game);
	draw_grid(game);
	draw_ray(game, false);
	draw_player(game);
	mlx_put_image_to_window(game->mlx, game->win, game->buffer.img, 0, 0);
	mlx_destroy_image(game->mlx, game->buffer.img);
	game->buffer.img = mlx_new_image(game->mlx, game->x_win, game->y_win);
	game->buffer.addr = mlx_get_data_addr(game->buffer.img,
			&game->buffer.bit_per_pixel, &game->buffer.line_length,
			&game->buffer.endian);
	return (0);
}
