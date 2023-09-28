/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_ft.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoyer <mhoyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 10:29:27 by mhoyer            #+#    #+#             */
/*   Updated: 2023/09/28 14:05:49 by mhoyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_background(t_game *game)
{
	int	x;
	int	y;
	
	x = -1;
	while (++x < game->x_win)
	{
		y = -1;
		while (++y < game->y_win)
		{
			my_mlx_pixel_put(&game->buffer, x, y, my_mlx_get_color(game->background, x, y));
		}
	}
}

int	close_game(t_game *game)
{
	free_exit(game);
	destroy_exit(game);
	exit(0);
}

int	loop(t_game *game)
{
	do_move(game);
	print_background(game);
	raycast(game);
	print_minimap(game, 0, 0);
	mlx_put_image_to_window(game->mlx, game->win, game->buffer.img, 0, 0);
	mlx_destroy_image(game->mlx, game->buffer.img);
	game->buffer.img = mlx_new_image(game->mlx, game->x_win, game->y_win);
	game->buffer.addr = mlx_get_data_addr(game->buffer.img,
			&game->buffer.bit_per_pixel, &game->buffer.line_length,
			&game->buffer.endian);
	return (0);
}
