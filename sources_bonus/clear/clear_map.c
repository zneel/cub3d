/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouvier <ebouvier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 21:25:55 by ebouvier          #+#    #+#             */
/*   Updated: 2023/10/02 15:19:16 by ebouvier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	destroy_map_data(t_map_data data)
{
	if (data.no_bool > 1)
		free(data.no);
	if (data.so_bool > 1)
		free(data.so);
	if (data.ea_bool > 1)
		free(data.ea);
	if (data.we_bool > 1)
		free(data.we);
	data.ceiling = -1;
	data.floor = -1;
}

void	destroy_matrix(t_map_value **matrix, int y_max)
{
	int	y;

	y = 0;
	while (y < y_max)
		free(matrix[y++]);
	free(matrix);
}

void	destroy_map(t_map *map)
{
	destroy_map_data(map->data);
	if (map->map)
	{
		destroy_matrix(map->map, map->y_max);
		map->map = NULL;
	}
}
