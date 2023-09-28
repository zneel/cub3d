/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouvier <ebouvier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 14:34:45 by ebouvier          #+#    #+#             */
/*   Updated: 2023/09/28 12:08:16 by ebouvier         ###   ########.fr       */
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
void	parse_map_list(t_list **list, char *line);
t_bool	is_scene_valid(t_map *map);
int		get_x_max(t_list *list);
t_bool	alloc_map(t_list *list, t_map *map);
t_bool	fill_map(t_list *list, t_map *map);
void	debug_parsing(t_map *map);
int		split_len(char **split);
t_bool	check_closed_map(t_map *map);

#endif