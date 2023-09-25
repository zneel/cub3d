/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouvier <ebouvier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 14:34:45 by ebouvier          #+#    #+#             */
/*   Updated: 2023/09/25 10:54:53 by ebouvier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "cub3d.h"

void	check_file(char *file);
typedef enum e_orientation
{
	NORTH,
	SOUTH,
	EAST,
	WEST,
}		t_orientation;

/**
 * @brief
 *
 * @param line
 * @param map
 */
t_bool	parse_textures(char *line, t_map *map);
t_bool	parse_ceiling_color(char *line, t_map *map);
t_bool	parse_floor_color(char *line, t_map *map);
int		parse_color(char *r, char *g, char *b);
void	parse_map_list(t_list **list, char *line, t_map *map);
#endif