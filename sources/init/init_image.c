/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoyer <mhoyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 08:05:16 by mhoyer            #+#    #+#             */
/*   Updated: 2023/10/02 14:21:28 by mhoyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_img(t_game *game)
{
	game->tex.no.img = mlx_xpm_file_to_image(game->mlx, game->map.data.no,
			&game->tex.no.width, &game->tex.no.height);
	game->tex.no.addr = mlx_get_data_addr(game->tex.no.img,
			&game->tex.no.bit_per_pixel, &game->tex.no.line_length,
			&game->tex.no.endian);
	game->tex.so.img = mlx_xpm_file_to_image(game->mlx, game->map.data.so,
			&game->tex.so.width, &game->tex.so.height);
	game->tex.so.addr = mlx_get_data_addr(game->tex.so.img,
			&game->tex.so.bit_per_pixel, &game->tex.so.line_length,
			&game->tex.so.endian);
	game->tex.we.img = mlx_xpm_file_to_image(game->mlx, game->map.data.we,
			&game->tex.we.width, &game->tex.we.height);
	game->tex.we.addr = mlx_get_data_addr(game->tex.we.img,
			&game->tex.we.bit_per_pixel, &game->tex.we.line_length,
			&game->tex.we.endian);
	game->tex.ea.img = mlx_xpm_file_to_image(game->mlx, game->map.data.ea,
			&game->tex.ea.width, &game->tex.ea.height);
	game->tex.ea.addr = mlx_get_data_addr(game->tex.ea.img,
			&game->tex.ea.bit_per_pixel, &game->tex.ea.line_length,
			&game->tex.ea.endian);
}

void	init_background(t_game *game)
{
	int	x;
	int	y;

	y = -1;
	while (++y < game->y_win)
	{
		x = -1;
		while (++x < game->x_win)
		{
			if (y < game->y_win / 2)
				put_pixel(&game->background, x, y, game->map.data.ceiling);
			else
				put_pixel(&game->background, x, y, game->map.data.floor);
		}
	}
}

void	init_pgrm_img(t_game *game)
{
	game->win = mlx_new_window(game->mlx, game->x_win, game->y_win, "cub3D");
	game->background.img = mlx_new_image(game->mlx, game->x_win, game->y_win);
	game->background.width = game->x_win;
	game->background.height = game->y_win;
	game->background.addr = mlx_get_data_addr(game->background.img,
			&game->background.bit_per_pixel, &game->background.line_length,
			&game->background.endian);
	init_background(game);
	game->buffer = malloc(sizeof(t_img_data));
	game->buffer->img = mlx_new_image(game->mlx, game->x_win, game->y_win);
	game->buffer->width = game->x_win;
	game->buffer->height = game->y_win;
	game->buffer->addr = mlx_get_data_addr(game->buffer->img,
			&game->buffer->bit_per_pixel, &game->buffer->line_length,
			&game->buffer->endian);
}
