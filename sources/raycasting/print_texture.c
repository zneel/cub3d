/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoyer <mhoyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 07:24:35 by mhoyer            #+#    #+#             */
/*   Updated: 2023/09/29 12:31:30 by mhoyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_img_data	*get_good_text(t_game *game, t_raycast cast)
{
	if (cast.side == 1)
	{
		if (cast.map_y < game->player->pos_y)
			return (&game->tex.no);
		return (&game->tex.so);
	}
	if (cast.map_x > game->player->pos_x)
		return (&game->tex.ea);
	return (&game->tex.we);
}

void	draw_text(t_game *game, t_raycast cast, int tex_x, int x)
{
	double	step;
	double	tex_pos;
	int		tex_y;
	int		y;
	int		color;

	step = 1.0 * TEXT_HEIGHT / cast.line_height;
	tex_pos = (cast.draw_start - game->y_win / 2 + cast.line_height / 2) * step;
	y = cast.draw_start - 1;
	while (++y < cast.draw_end)
	{
		tex_y = (int)tex_pos & (TEXT_HEIGHT - 1);
		tex_pos += step;
		color = my_mlx_get_color(get_good_text(game, cast), tex_x, tex_y);
		if (cast.side == 1)
			color = (color >> 1) & 8355711;
		put_pixel(game->buffer, x, y, color);
	}
}

void	print_texture(t_game *game, t_raycast cast, int x, double perp)
{
	int		tex_x;
	double	wall_x;

	if (cast.side == 0)
		wall_x = game->player->pos_y + perp * cast.ray_dir_y;
	else
		wall_x = game->player->pos_x + perp * cast.ray_dir_x;
	wall_x -= floor(wall_x);
	tex_x = (int)(wall_x * (double)TEXT_WIDTH);
	if (cast.side == 0 && cast.ray_dir_x > 0)
		tex_x = TEXT_WIDTH - tex_x - 1;
	if (cast.side == 1 && cast.ray_dir_y < 0)
		tex_x = TEXT_WIDTH - tex_x - 1;
	draw_text(game, cast, tex_x, x);
}
