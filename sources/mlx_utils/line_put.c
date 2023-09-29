/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_put.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoyer <mhoyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 17:22:16 by mhoyer            #+#    #+#             */
/*   Updated: 2023/09/29 10:12:16 by mhoyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_line	create_line(float x1, float y1, float x2, float y2)
{
	t_line	line;

	line.x1 = x1;
	line.y1 = y1;
	line.x2 = x2;
	line.y2 = y2;
	return (line);
}

t_line	protect_line(t_game *game, t_line line)
{
	if (line.x1 < 0)
		line.x1 = 0;
	if (line.y1 < 0)
		line.y1 = 0;
	if (line.x2 < 0)
		line.x2 = 0;
	if (line.y2 < 0)
		line.y2 = 0;
	if (line.x1 > game->x_win)
		line.x1 = game->x_win;
	if (line.y1 > game->y_win)
		line.y1 = game->y_win;
	if (line.x2 > game->x_win)
		line.x2 = game->x_win;
	if (line.y2 > game->y_win)
		line.y2 = game->y_win;
	return (line);
}

void	my_put_line(t_game *game, t_img_data img, t_line line, int color)
{
	float	delta_x;
	float	delta_y;
	float	pixel_x;
	float	pixel_y;
	int		pixels;

	line = protect_line(game, line);
	delta_x = line.x2 - line.x1;
	delta_y = line.y2 - line.y1;
	pixels = sqrt((delta_x * delta_x) + (delta_y * delta_y));
	delta_x /= pixels;
	delta_y /= pixels;
	pixel_x = line.x1;
	pixel_y = line.y1;
	while (pixels)
	{
		my_mlx_pixel_put(&img, pixel_x, pixel_y, color + pixels);
		pixel_x += delta_x;
		pixel_y += delta_y;
		pixels--;
	}
}
