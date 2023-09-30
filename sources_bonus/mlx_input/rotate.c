/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoyer <mhoyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 19:34:52 by mhoyer            #+#    #+#             */
/*   Updated: 2023/09/28 19:35:27 by mhoyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	key_right(t_game *game)
{
	t_player	old;
	t_player	*current;

	ft_memcpy(&old, game->player, sizeof(t_player));
	current = game->player;
	current->dir_x = current->dir_x * cos(degree_to_radians(ROT_SPEED))
		- current->dir_y * sin(degree_to_radians(ROT_SPEED));
	current->dir_y = old.dir_x * sin(degree_to_radians(ROT_SPEED))
		+ current->dir_y * cos(degree_to_radians(ROT_SPEED));
	current->plane_x = current->plane_x * cos(degree_to_radians(ROT_SPEED))
		- current->plane_y * sin(degree_to_radians(ROT_SPEED));
	current->plane_y = old.plane_x * sin(degree_to_radians(ROT_SPEED))
		+ current->plane_y * cos(degree_to_radians(ROT_SPEED));
}

void	key_left(t_game *game)
{
	t_player	old;
	t_player	*current;

	ft_memcpy(&old, game->player, sizeof(t_player));
	current = game->player;
	current->dir_x = current->dir_x * cos(degree_to_radians(-ROT_SPEED))
		- current->dir_y * sin(degree_to_radians(-ROT_SPEED));
	current->dir_y = old.dir_x * sin(degree_to_radians(-ROT_SPEED))
		+ current->dir_y * cos(degree_to_radians(-ROT_SPEED));
	current->plane_x = current->plane_x * cos(degree_to_radians(-ROT_SPEED))
		- current->plane_y * sin(degree_to_radians(-ROT_SPEED));
	current->plane_y = old.plane_x * sin(degree_to_radians(-ROT_SPEED))
		+ current->plane_y * cos(degree_to_radians(-ROT_SPEED));
}
