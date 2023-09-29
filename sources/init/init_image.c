/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoyer <mhoyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 08:05:16 by mhoyer            #+#    #+#             */
/*   Updated: 2023/09/29 11:34:10 by mhoyer           ###   ########.fr       */
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
