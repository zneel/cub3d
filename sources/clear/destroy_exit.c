/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoyer <mhoyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 10:35:21 by mhoyer            #+#    #+#             */
/*   Updated: 2023/10/02 14:21:38 by mhoyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	destroy_exit(t_game *game)
{
	mlx_destroy_image(game->mlx, game->tex.no.img);
	mlx_destroy_image(game->mlx, game->tex.so.img);
	mlx_destroy_image(game->mlx, game->tex.we.img);
	mlx_destroy_image(game->mlx, game->tex.ea.img);
	mlx_destroy_image(game->mlx, game->background.img);
	mlx_destroy_image(game->mlx, game->buffer->img);
	free(game->buffer);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
}
