/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_put.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoyer <mhoyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 17:22:16 by mhoyer            #+#    #+#             */
/*   Updated: 2023/09/29 12:08:54 by mhoyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	sign(int a, int b)
{
	if (a < b)
		return (1);
	return (-1);
}

void	init_bresenham(t_bren *b, t_vec2 start, t_vec2 end)
{
	b->dx = fabs(end.x - start.x);
	b->sx = sign(start.x, end.x);
	b->dy = fabs(end.y - start.y);
	b->sy = sign(start.y, end.y);
	if (b->dx > b->dy)
		b->err = b->dx / 2;
	else
		b->err = -b->dy / 2;
}

void	draw_line(t_img_data *img, t_vec2 start, t_vec2 end, int color)
{
	t_bren	b;

	init_bresenham(&b, start, end);
	while (start.x != end.x || start.y != end.y)
	{
		put_pixel(img, start.x, start.y, color);
		b.e2 = b.err;
		if (b.e2 > -b.dx)
		{
			b.err -= b.dy;
			start.x += b.sx;
		}
		if (b.e2 < b.dy)
		{
			b.err += b.dx;
			start.y += b.sy;
		}
	}
}
