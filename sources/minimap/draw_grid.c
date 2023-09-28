/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_grid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoyer <mhoyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 09:47:57 by mhoyer            #+#    #+#             */
/*   Updated: 2023/09/28 09:48:17 by mhoyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_grid(t_game *game, t_img_data *minimap)
{
	int	x;
	int	y;

	x = SIZE_CASE;
	while (x < game->map.x_max * SIZE_CASE)
	{
		y = 0;
		while (y < game->map.y_max * SIZE_CASE)
		{
			my_mlx_pixel_put(minimap, x, y, 0x606060);
			y++;
		}
		x += SIZE_CASE;
	}
	y = SIZE_CASE;
	while (y < game->map.y_max * SIZE_CASE)
	{
		x = 0;
		while (x < game->map.x_max * SIZE_CASE)
		{
			my_mlx_pixel_put(minimap, x, y, 0x606060);
			x++;
		}
		y += SIZE_CASE;
	}
}
