/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_put.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoyer <mhoyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 17:21:07 by mhoyer            #+#    #+#             */
/*   Updated: 2023/09/29 11:53:07 by mhoyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	put_pixel(t_img_data *img, int x, int y, int color)
{
	char	*pixel;

	if (x >= 0 && x < img->width && y >= 0 && y < img->height)
	{
		pixel = img->addr + (y * img->line_length + x * (img->bit_per_pixel
					/ 8));
		if (pixel >= img->addr && pixel + sizeof(color) <= img->addr
			+ (img->height * img->line_length + img->width * (img->bit_per_pixel
					/ 8)))
		{
			*(int *)pixel = color;
		}
	}
}
