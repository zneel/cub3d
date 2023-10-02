/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_obstacle.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoyer <mhoyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 09:47:22 by mhoyer            #+#    #+#             */
/*   Updated: 2023/10/02 21:16:25 by mhoyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "minimap.h"

void	print_obs(t_img_data *minimap, int x_start, int y_start,
		unsigned int color)
{
	int	x;
	int	y;

	x = x_start;
	while (x <= x_start + SIZE_CASE)
	{
		y = y_start;
		while (y <= y_start + SIZE_CASE)
		{
			put_pixel(minimap, x, y, color);
			y++;
		}
		x++;
	}
}

void	draw_obs(t_game *game, t_img_data *minimap)
{
	int	x;
	int	x_start;
	int	y;
	int	y_start;

	x = (game->player->x - SIZE_MAP - SIZE_CASE) / SIZE_CASE - 1;
	x_start = (game->player->x - SIZE_MAP);
	while (++x < (game->player->x + SIZE_MAP) / SIZE_CASE)
	{
		y = (game->player->y - SIZE_MAP - SIZE_CASE) / SIZE_CASE - 1;
		y_start = (game->player->y - SIZE_MAP);
		while (++y < (game->player->y + SIZE_MAP) / SIZE_CASE)
		{
			if (y >= 0 && x >= 0 && x < game->map.x_max && y < game->map.y_max
				&& game->map.map[y][x] == WALL)
				print_obs(minimap, x * SIZE_CASE - x_start, y * SIZE_CASE
					- y_start, 0xFFFFFF);
			else if (y >= 0 && x >= 0 && x < game->map.x_max
				&& y < game->map.y_max && (game->map.map[y][x] == EMPTY
				|| (game->map.data.spawn.y == y
					&& game->map.data.spawn.x == x)))
				print_obs(minimap, x * SIZE_CASE - x_start, y * SIZE_CASE
					- y_start, 0x293133);
		}
	}
}
