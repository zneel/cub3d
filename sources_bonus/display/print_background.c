/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_background.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoyer <mhoyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 19:29:16 by mhoyer            #+#    #+#             */
/*   Updated: 2023/09/29 12:26:46 by mhoyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_background(t_game *game)
{
	int	x;
	int	y;

	x = -1;
	while (++x < game->x_win)
	{
		y = -1;
		while (++y < game->y_win)
		{
			put_pixel(game->buffer, x, y,
				my_mlx_get_color(&game->background, x, y));
		}
	}
}
