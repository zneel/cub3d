/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_grid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoyer <mhoyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 09:47:57 by mhoyer            #+#    #+#             */
/*   Updated: 2023/10/02 21:18:24 by mhoyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "minimap.h"

void	hor(t_game *game, t_img_data *minimap)
{
	int	x;
	int	x_start;
	int	y;
	int	y_start;

	y = (game->player->y - SIZE_MAP - SIZE_CASE) / SIZE_CASE - 1;
	y_start = (game->player->y - SIZE_MAP);
	while (++y < (game->player->y + SIZE_MAP) / SIZE_CASE)
	{
		x = (game->player->x - SIZE_MAP - SIZE_CASE);
		x_start = (game->player->x - SIZE_MAP);
		while (++x < (game->player->x + SIZE_MAP))
		{
			if (y >= 0 && x >= 0 && x < game->map.x_max * SIZE_CASE
				&& y < game->map.y_max)
				put_pixel(minimap, x - x_start, y * SIZE_CASE - y_start,
					0x808080);
		}
	}
}

void	vert(t_game *game, t_img_data *minimap)
{
	int	x;
	int	x_start;
	int	y;
	int	y_start;

	x = (game->player->x - SIZE_MAP - SIZE_CASE) / SIZE_CASE - 1;
	x_start = (game->player->x - SIZE_MAP);
	while (++x < (game->player->x + SIZE_MAP) / SIZE_CASE)
	{
		y = (game->player->y - SIZE_MAP - SIZE_CASE);
		y_start = (game->player->y - SIZE_MAP);
		while (++y < (game->player->y + SIZE_MAP))
		{
			if (y >= 0 && x >= 0 && x < game->map.x_max && y < game->map.y_max
				* SIZE_CASE)
				put_pixel(minimap, x * SIZE_CASE - x_start, y - y_start,
					0x808080);
		}
	}
}

void	draw_grid(t_game *game, t_img_data *minimap)
{
	hor(game, minimap);
	vert(game, minimap);
}
