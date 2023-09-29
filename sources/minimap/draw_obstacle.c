/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_obstacle.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoyer <mhoyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 09:47:22 by mhoyer            #+#    #+#             */
/*   Updated: 2023/09/29 11:57:09 by mhoyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
	int	y;

	y = 0;
	while (y < game->map.y_max)
	{
		x = 0;
		while (x < game->map.x_max)
		{
			if (game->map.map[y][x] == WALL || game->map.map[y][x] == SPACE)
				print_obs(minimap, x * SIZE_CASE, y * SIZE_CASE, 0xFFFFFF);
			else
				print_obs(minimap, x * SIZE_CASE, y * SIZE_CASE, 0x000000);
			x++;
		}
		y++;
	}
}
