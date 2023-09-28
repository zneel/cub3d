/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoyer <mhoyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 08:49:15 by mhoyer            #+#    #+#             */
/*   Updated: 2023/09/28 09:09:52 by mhoyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minimap.h"

void	draw_triangle(t_game *game, t_img_data *minimap, t_triangle tri)
{
	double	delta_x;
	double	delta_y;
	double	pixel_x;
	double	pixel_y;
	int		pixels;

	delta_x = tri.x_base2 - tri.x_base1;
	delta_y = tri.y_base2 - tri.y_base1;
	pixels = sqrt((delta_x * delta_x) + (delta_y * delta_y));
	delta_x /= pixels;
	delta_y /= pixels;
	pixel_x = tri.x_base1;
	pixel_y = tri.y_base1;
	while (pixels)
	{
		my_put_line(game, *minimap, create_line(pixel_x, pixel_y, tri.x_top, tri.y_top), 0xFF0000);
		pixel_x += delta_x;
		pixel_y += delta_y;
		pixels--;
	}
}

void	draw_player(t_game *game, t_img_data *minimap)
{
	t_triangle	tri;
	double	facing_direction;

	facing_direction = calculate_player_direction(game->player);
	tri.x_top = game->player->x + game->player->dir_x * 5;
	tri.y_top = game->player->y + game->player->dir_y * 5;
	tri.x_base1 = game->player->x - game->player->dir_x * 5 + cos(facing_direction + M_PI_2) * SIZE_PLAYER;
	tri.y_base1 = game->player->y - game->player->dir_y * 5 + sin(facing_direction + M_PI_2) * SIZE_PLAYER;
	tri.x_base2 = game->player->x - game->player->dir_x * 5 - cos(facing_direction + M_PI_2) * SIZE_PLAYER;
	tri.y_base2 = game->player->y - game->player->dir_y * 5 - sin(facing_direction + M_PI_2) * SIZE_PLAYER;
	draw_triangle(game, minimap, tri);
}
