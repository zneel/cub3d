/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_minimap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoyer <mhoyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 20:14:08 by mhoyer            #+#    #+#             */
/*   Updated: 2023/09/27 21:49:45 by mhoyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minimap.h"

void	print_obs(t_img_data *minimap, int x_start, int y_start, unsigned int color)
{
	int	x;
	int	y;

	x = x_start;
	while (x <= x_start + SIZE_CASE)
	{
		y = y_start;
		while (y <= y_start + SIZE_CASE)
		{
			my_mlx_pixel_put(minimap, x, y, color);
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

void	draw_player(t_game *game, t_img_data *minimap)
{
	int	x;
	int	y;

	x = game->player->x - SIZE_PLAYER / 2;
	while (x < game->player->x + SIZE_PLAYER / 2)
	{
		y = game->player->y;
		while (y < game->player->y + SIZE_PLAYER / 2)
		{
			my_mlx_pixel_put(minimap, x, y, 0xFF0000);
			y++;
		}
		x++;
	}
}

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

void	print_minimap(t_game *game, int to_x, int to_y)
{
	t_img_data	minimap;
	int			x;
	int			y;
	int			x_max;
	int			y_max;
	int			mem;

	minimap.img = mlx_new_image(game->mlx, game->map.x_max * SIZE_CASE, game->map.y_max * SIZE_CASE);
	minimap.addr = mlx_get_data_addr(minimap.img,
			&minimap.bit_per_pixel, &minimap.line_length,
			&minimap.endian);
	draw_obs(game, &minimap);
	draw_player(game, &minimap);
	draw_grid(game, &minimap);
	x = game->player->x - SIZE_MAP;
	x_max = game->player->x + SIZE_MAP;
	y_max = game->player->y + SIZE_MAP;
	if (x_max > game->map.x_max * SIZE_CASE)
		x_max = game->map.x_max * SIZE_CASE;
	if (y_max > game->map.y_max * SIZE_CASE)
		y_max = game->map.y_max * SIZE_CASE;
	if (x < 0)
		x = 0;
	mem = to_y;
	while (++x < x_max)
	{
		y = game->player->y - SIZE_MAP;
		if (y < 0)
			y = 0;
		to_y = mem;
		while (++y < y_max)
		{
			my_mlx_pixel_put(&game->buffer, to_x, to_y, my_mlx_get_color(minimap, x, y));
			to_y++;
		}
		to_x++;
	}
	//mlx_destroy_image(game->mlx, &minimap);
}