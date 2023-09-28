/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoyer <mhoyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 19:33:38 by mhoyer            #+#    #+#             */
/*   Updated: 2023/09/28 19:36:04 by mhoyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	degree_to_radians(double degree)
{
	return (degree * M_PI / 180);
}

double	calculate_player_direction(t_player *player)
{
	return (atan2(player->dir_y, player->dir_x));
}
