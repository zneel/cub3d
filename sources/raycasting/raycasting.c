/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouvier <ebouvier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 13:21:25 by mhoyer            #+#    #+#             */
/*   Updated: 2023/09/24 12:49:10 by ebouvier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_wall(t_game *game, float ray_angle, float size, int nb_ray)
{
	float	line_h;
	float	line_off;
	float	angle;
	int		w_line;
	t_line	line;

	angle = game->player.angle - ray_angle;
	if (angle < 0)
		angle += 2 * PI;
	if (angle > 2 * PI)
		angle -= 2 * PI;
	size *= cos(angle);
	line_h = (30 * game->y_win) / size;
	if (line_h > game->y_win)
		line_h = game->y_win;
	line_off = (game->y_win / 2) - (line_h / 2);
	w_line = (game->x_win / game->fov) + 1;
	line = create_line(nb_ray * w_line, line_off, nb_ray * w_line, line_off
		+ line_h);
	my_put_line_w(game, line, 0x006600, w_line);
}

float	cmp_dist(t_game *game, float angle, t_ray *ray)
{
	float	co_h[2];
	float	co_v[2];
	float	dist_h;
	float	dist_v;

	dist_h = check_h(game, &co_h[CO_X], &co_h[CO_Y], angle);
	dist_v = check_v(game, &co_v[CO_X], &co_v[CO_Y], angle);
	if (dist_h < dist_v)
	{
		ray->x = co_h[CO_X];
		ray->y = co_h[CO_Y];
		return (dist_h);
	}
	if (dist_v < dist_h)
	{
		ray->x = co_v[CO_X];
		ray->y = co_v[CO_Y];
		return (dist_v);
	}
	return (0);
}

void	draw_ray(t_game *game, t_bool calc)
{
	t_ray	ray;
	int		nb_ray;
	float	angle;
	float	dist_mem;

	nb_ray = -1;
	angle = game->player.angle - DEGREE * (game->fov / 2);
	if (angle < 0)
		angle += 2 * PI;
	if (angle > 2 * PI)
		angle -= 2 * PI;
	while (++nb_ray < game->fov)
	{
		dist_mem = cmp_dist(game, angle, &ray);
		if (dist_mem)
		{
			if (calc == true)
				draw_wall(game, angle, dist_mem, nb_ray);
			else
				my_put_line(game, create_line(game->player.center_x,
						game->player.center_y, ray.x, ray.y), 0x00FF00);
		}
		angle += DEGREE;
		if (angle < 0)
			angle += 2 * PI;
		if (angle > 2 * PI)
			angle -= 2 * PI;
	}
}
