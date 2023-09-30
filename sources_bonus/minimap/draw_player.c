/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoyer <mhoyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 08:49:15 by mhoyer            #+#    #+#             */
/*   Updated: 2023/09/29 13:35:33 by mhoyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minimap.h"

void	draw_triangle(t_img_data *minimap, t_triangle tri)
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
		draw_line(minimap, (t_vec2){(int)pixel_x, (int)pixel_y},
			(t_vec2){(int)tri.x_top, (int)tri.y_top}, 0xFF0000);
		pixel_x += delta_x;
		pixel_y += delta_y;
		pixels--;
	}
}

void	draw_player(t_game *game, t_img_data *minimap)
{
	t_triangle	tri;
	double		facing_direction;

	facing_direction = calculate_player_direction(game->player);
	tri.x_top = game->player->x + game->player->dir_x * 10;
	tri.y_top = game->player->y + game->player->dir_y * 10;
	tri.x_base1 = game->player->x - game->player->dir_x * 5
		+ cos(facing_direction + M_PI_2) * SIZE_PLAYER;
	tri.y_base1 = game->player->y - game->player->dir_y * 5
		+ sin(facing_direction + M_PI_2) * SIZE_PLAYER;
	tri.x_base2 = game->player->x - game->player->dir_x * 5
		- cos(facing_direction + M_PI_2) * SIZE_PLAYER;
	tri.y_base2 = game->player->y - game->player->dir_y * 5
		- sin(facing_direction + M_PI_2) * SIZE_PLAYER;
	draw_triangle(minimap, tri);
}
