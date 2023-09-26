/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_vertical.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouvier <ebouvier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 17:35:19 by mhoyer            #+#    #+#             */
/*   Updated: 2023/09/26 11:24:17 by ebouvier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

float	check_v(t_game *game, float *vx, float *vy, float angle)
{
	t_ray	ray;
	int		chunk;
	int		mat_x;
	int		mat_y;
	float	xo;
	float	yo;
	float	ntan;
	float	dist_v;

	ray.angle = angle;
	chunk = 0;
	ntan = -tan(ray.angle);
	dist_v = 1000000;
	*vx = game->player.center_x;
	*vy = game->player.center_y;
	if (ray.angle > P2 && ray.angle < P3)
	{
		ray.x = (((int)game->player.center_x / SIZE_CASE) * SIZE_CASE) - 0.0001;
		ray.y = (game->player.center_x - ray.x) * ntan + game->player.center_y;
		xo = -SIZE_CASE;
		yo = -xo * ntan;
	}
	if (ray.angle < P2 || ray.angle > P3)
	{
		ray.x = (((int)game->player.center_x / SIZE_CASE) * SIZE_CASE)
			+ SIZE_CASE;
		ray.y = (game->player.center_x - ray.x) * ntan + game->player.center_y;
		xo = SIZE_CASE;
		yo = -xo * ntan;
	}
	if (ray.angle == P2 || ray.angle == P3)
	{
		ray.x = game->player.center_x;
		ray.y = game->player.center_y;
		chunk = RENDER_DIST;
	}
	while (chunk < RENDER_DIST)
	{
		mat_x = (int)(ray.x) / SIZE_CASE;
		mat_y = (int)(ray.y) / SIZE_CASE;
		if (mat_x >= 0 && mat_x < game->map.x_max && mat_y >= 0
			&& mat_y < game->map.y_max && game->map.map[mat_y][mat_x] == WALL)
		{
			*vx = ray.x;
			*vy = ray.y;
			dist_v = calc_dist(game->player.center_x, game->player.center_y,
					*vx, *vy /*, ray.angle*/);
			chunk = RENDER_DIST;
		}
		else
		{
			ray.x += xo;
			ray.y += yo;
			chunk++;
		}
	}
	return (dist_v);
}
