/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoyer <mhoyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 07:32:12 by mhoyer            #+#    #+#             */
/*   Updated: 2023/09/29 12:17:31 by mhoyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	my_mlx_get_color(t_img_data *img, int x, int y)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bit_per_pixel
				/ 8));
	return (*(unsigned int *)dst);
}
