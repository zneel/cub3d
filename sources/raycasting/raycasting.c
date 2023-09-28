/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoyer <mhoyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 13:21:25 by mhoyer            #+#    #+#             */
/*   Updated: 2023/09/28 08:06:51 by mhoyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#define RED 0xFF0000
#define GREEN 0x00FF00
#define BLUE 0x0000FF
#define WHITE 0xFFFFFF
#define BLACK 0x000000
#define YELLOW 0xFFFF00

void	draw_ray(t_raycast casted, t_game *game, int x)
{
	int		color;
	double	perp_wall_dist;

	color = RED;
	if (casted.side == 0)
		perp_wall_dist = (casted.side_dist_x - casted.delta_dist_x);
	else
		perp_wall_dist = (casted.side_dist_y - casted.delta_dist_y);
	casted.line_height = (int)(game->y_win / perp_wall_dist);
	casted.draw_start = -casted.line_height / 2 + game->y_win / 2;
	if (casted.draw_start < 0)
		casted.draw_start = 0;
	casted.draw_end = casted.line_height / 2 + game->y_win / 2;
	if (casted.draw_end >= game->y_win)
		casted.draw_end = game->y_win - 1;
	if (casted.side == 1)
		color = (color >> 1) & 8355711;
	my_put_line(game, game->buffer, create_line(x, casted.draw_start, x, casted.draw_end),
		color);
}

void	calc_hit(t_raycast *cast, t_game *game)
{
	int	hit;

	hit = 0;
	while (!hit)
	{
		if (cast->side_dist_x < cast->side_dist_y)
		{
			cast->side_dist_x += cast->delta_dist_x;
			cast->map_x += cast->step_x;
			cast->side = 0;
		}
		else
		{
			cast->side_dist_y += cast->delta_dist_y;
			cast->map_y += cast->step_y;
			cast->side = 1;
		}
		if (game->map.map[cast->map_y][cast->map_x] == WALL
			|| game->map.map[cast->map_y][cast->map_x] == SPACE)
			hit = 1;
	}
}

void	calc_ray_dir(t_raycast *rc, t_game *game)
{
	if (rc->ray_dir_x < 0)
	{
		rc->step_x = -1;
		rc->side_dist_x = (game->player->pos_x - rc->map_x) * rc->delta_dist_x;
	}
	else
	{
		rc->step_x = 1;
		rc->side_dist_x = (rc->map_x + 1.0 - game->player->pos_x)
			* rc->delta_dist_x;
	}
	if (rc->ray_dir_y < 0)
	{
		rc->step_y = -1;
		rc->side_dist_y = (game->player->pos_y - rc->map_y) * rc->delta_dist_y;
	}
	else
	{
		rc->step_y = 1;
		rc->side_dist_y = (rc->map_y + 1.0 - game->player->pos_y)
			* rc->delta_dist_y;
	}
}

t_raycast	cast_ray(t_game *game, int x)
{
	t_raycast	rc;

	rc.camera_x = 2.0f * x / (double)game->x_win - 1;
	rc.ray_dir_x = game->player->dir_x + game->player->plane_x * rc.camera_x;
	rc.ray_dir_y = game->player->dir_y + game->player->plane_y * rc.camera_x;
	rc.map_x = (int)game->player->pos_x;
	rc.map_y = (int)game->player->pos_y;
	if (rc.ray_dir_x == 0)
		rc.delta_dist_x = 1e30f;
	else
		rc.delta_dist_x = fabs(1 / rc.ray_dir_x);
	if (rc.ray_dir_y == 0)
		rc.delta_dist_y = 1e30f;
	else
		rc.delta_dist_y = fabs(1 / rc.ray_dir_y);
	calc_ray_dir(&rc, game);
	calc_hit(&rc, game);
	return (rc);
}

void	raycast(t_game *game)
{
	int x;
	t_raycast casted;
	x = 0;
	while (++x < game->x_win)
	{
		casted = cast_ray(game, x);
		draw_ray(casted, game, x);
	}
}