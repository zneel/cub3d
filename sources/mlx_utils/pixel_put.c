/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_put.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouvier <ebouvier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 17:21:07 by mhoyer            #+#    #+#             */
/*   Updated: 2023/09/26 15:15:46 by ebouvier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	my_mlx_pixel_put(t_img_data *buffer, int x, int y, int color)
{
	char	*dst;

	dst = buffer->addr + (y * buffer->line_length + x * (buffer->bit_per_pixel
				/ 8));
	*(unsigned int *)dst = color;
}
