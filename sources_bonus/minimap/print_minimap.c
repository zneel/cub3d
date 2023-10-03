/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_minimap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoyer <mhoyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 20:14:08 by mhoyer            #+#    #+#             */
/*   Updated: 2023/10/02 21:18:50 by mhoyer           ###   ########.fr       */
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
	*x = game->player->x / SIZE_MAP - SIZE_MAP;
	*x_max = game->player->x / SIZE_MAP + SIZE_MAP;
	*y_max = game->player->y / SIZE_MAP + SIZE_MAP;
}

void	do_print(t_game *game, t_img_data *minimap, int to_x, int to_y)
{
	int	x;
	int	y;

	x = to_x -1;
	while (++x < minimap->width)
	{
		y = to_y -1;
		while (++y < minimap->height)
			put_pixel(game->buffer, x, y, my_mlx_get_color(minimap, x, y));
	}
}

void	reset_minimap(t_img_data *minimap)
{
	int	x;
	int	y;

	x = -1;
	while (++x < minimap->width)
	{
		y = -1;
		while (++y < minimap->height)
			put_pixel(minimap, x, y, 0x000000);
	}
}

void	print_minimap(t_game *game, int to_x, int to_y)
{
	reset_minimap(game->minimap);
	init_minimap(game, game->minimap);
	do_print(game, game->minimap, to_x, to_y);
}
