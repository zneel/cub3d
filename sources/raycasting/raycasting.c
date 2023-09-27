/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouvier <ebouvier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 13:21:25 by mhoyer            #+#    #+#             */
/*   Updated: 2023/09/27 15:53:41 by ebouvier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#define RED 0xFF0000
#define GREEN 0x00FF00
#define BLUE 0x0000FF
#define WHITE 0xFFFFFF
#define BLACK 0x000000
#define YELLOW 0xFFFF00

void	draw_ray(t_game *game, t_bool calc)
{
	int		x;
	double	camera_x;
	double	ray_dir_x;
	double	ray_dir_y;
	int		map_x;
	int		map_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	int		step_x;
	int		step_y;
	int		hit;
	double	perp_wall_dist;
	int		side;
	int		line_height;
	int		draw_start;
	int		draw_end;
	int		color;

	x = 0;
	(void)calc;
	while (x < game->x_win)
	{
		color = RED;
		camera_x = 2.0f * x / (double)game->x_win - 1;
		ray_dir_x = game->player->dir_x + game->player->plane_x * camera_x;
		ray_dir_y = game->player->dir_y + game->player->plane_y * camera_x;
		map_x = (int)game->player->pos_x;
		map_y = (int)game->player->pos_y;
		if (ray_dir_x == 0)
			delta_dist_x = 1e30f;
		else
			delta_dist_x = fabs(1 / ray_dir_x);
		if (ray_dir_y == 0)
			delta_dist_y = 1e30f;
		else
			delta_dist_y = fabs(1 / ray_dir_y);
		hit = 0;
		if (ray_dir_x < 0)
		{
			step_x = -1;
			side_dist_x = (game->player->pos_x - map_x) * delta_dist_x;
		}
		else
		{
			step_x = 1;
			side_dist_x = (map_x + 1.0 - game->player->pos_x) * delta_dist_x;
		}
		if (ray_dir_y < 0)
		{
			step_y = -1;
			side_dist_y = (game->player->pos_y - map_y) * delta_dist_y;
		}
		else
		{
			step_y = 1;
			side_dist_y = (map_y + 1.0 - game->player->pos_y) * delta_dist_y;
		}
		while (!hit)
		{
			if (side_dist_x < side_dist_y)
			{
				side_dist_x += delta_dist_x;
				map_x += step_x;
				side = 0;
			}
			else
			{
				side_dist_y += delta_dist_y;
				map_y += step_y;
				side = 1;
			}
			if (game->map.map[map_y][map_x] == WALL
				|| game->map.map[map_y][map_x] == SPACE)
				hit = 1;
		}
		if (side == 0)
			perp_wall_dist = (side_dist_x - delta_dist_x);
		else
			perp_wall_dist = (side_dist_y - delta_dist_y);
		line_height = (int)(game->y_win / perp_wall_dist);
		draw_start = -line_height / 2 + game->y_win / 2;
		if (draw_start < 0)
			draw_start = 0;
		draw_end = line_height / 2 + game->y_win / 2;
		if (draw_end >= game->y_win)
			draw_end = game->y_win - 1;
		if (side == 1)
			color = (color >> 1) & 8355711;
		my_put_line(game, create_line(x, draw_start, x, draw_end), color);
		x++;
		my_put_line(game, create_line(game->player->x, game->player->y, map_x
				* SIZE_CASE, map_y * SIZE_CASE), 0xFF0000);
	}
}
