/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_minimap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoyer <mhoyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 20:14:08 by mhoyer            #+#    #+#             */
/*   Updated: 2023/09/29 12:45:09 by mhoyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minimap.h"

void	init_minimap(t_game *game, t_img_data *minimap)
{
	draw_obs(game, minimap);
	draw_grid(game, minimap);
	draw_player(game, minimap);
}

void	init_for_print(t_game *game, int *x, int *x_max, int *y_max)
{
	*x = game->player->x - SIZE_MAP;
	*x_max = game->player->x + SIZE_MAP;
	*y_max = game->player->y + SIZE_MAP;
}

void	do_print(t_game *game, t_img_data *minimap, int to_x, int to_y)
{
	int	x;
	int	y;
	int	x_max;
	int	y_max;
	int	mem;

	init_for_print(game, &x, &x_max, &y_max);
	mem = to_y;
	while (++x < x_max)
	{
		y = game->player->y - SIZE_MAP;
		to_y = mem;
		while (++y < y_max)
		{
			if (x > 0 && y > 0 && x < game->map.x_max * SIZE_CASE
				&& y < game->map.y_max * SIZE_CASE)
				put_pixel(game->buffer, to_x, to_y,
					my_mlx_get_color(minimap, x, y));
			else
				put_pixel(game->buffer, to_x, to_y, 0x000000);
			to_y++;
		}
		to_x++;
	}
}

void	print_minimap(t_game *game, int to_x, int to_y)
{
	init_minimap(game, game->minimap);
	do_print(game, game->minimap, to_x, to_y);
}
