/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_lenght_ray.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouvier <ebouvier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 17:41:44 by mhoyer            #+#    #+#             */
/*   Updated: 2023/09/24 12:49:44 by ebouvier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

float	calc_dist(float player_x, float player_y, float ray_x, float ray_y)
{
	return (sqrt((ray_x - player_x) * (ray_x - player_x) + (ray_y - player_y)
			* (ray_y - player_y)));
}
