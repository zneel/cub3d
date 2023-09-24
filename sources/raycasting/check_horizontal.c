/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_horizontal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouvier <ebouvier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 17:35:30 by mhoyer            #+#    #+#             */
/*   Updated: 2023/09/24 12:49:00 by ebouvier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

float	check_h(t_game *game, float *hx, float *hy, float angle)
{
	t_ray	ray;
	int		chunk;
	int		mat_x;
	int		mat_y;
	int		mat_p;
	float	xo;
	float	yo;
	float	arc_tan;
	float	dist_h;

	ray.angle = angle;
	chunk = 0;
	arc_tan = -1 / tan(ray.angle);
	dist_h = 1000000;
	*hx = game->player.center_x;
	*hy = game->player.center_y;
	if (ray.angle > PI)
	{
		ray.y = (((int)game->player.center_y / SIZE_CASE) * SIZE_CASE) - 0.0001;
		ray.x = (game->player.center_y - ray.y) * arc_tan
			+ game->player.center_x;
		yo = -SIZE_CASE;
		xo = -yo * arc_tan;
	}
	if (ray.angle < PI)
	{
		ray.y = (((int)game->player.center_y / SIZE_CASE) * SIZE_CASE)
			+ SIZE_CASE;
		ray.x = (game->player.center_y - ray.y) * arc_tan
			+ game->player.center_x;
		yo = SIZE_CASE;
		xo = -yo * arc_tan;
	}
	if (ray.angle == 0 || ray.angle == PI)
	{
		ray.x = game->player.center_x;
		ray.y = game->player.center_y;
		chunk = RENDER_DIST;
	}
	while (chunk < RENDER_DIST)
	{
		mat_x = (int)(ray.x) / SIZE_CASE;
		mat_y = (int)(ray.y) / SIZE_CASE;
		mat_p = mat_y * game->d_map.x_max + mat_x;
		if (mat_p > 0 && mat_p < game->d_map.x_max * game->d_map.y_max
			&& game->d_map.array[mat_p] == '1')
		{
			*hx = ray.x;
			*hy = ray.y;
			dist_h = calc_dist(game->player.center_x, game->player.center_y,
				*hx, *hy /*, ray.angle*/);
			chunk = RENDER_DIST;
		}
		else
		{
			ray.x += xo;
			ray.y += yo;
			chunk++;
		}
	}
	return (dist_h);
}
