/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoyer <mhoyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 20:14:37 by mhoyer            #+#    #+#             */
/*   Updated: 2023/09/29 12:16:10 by mhoyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIMAP_H
# define MINIMAP_H

# include "cub3d.h"

# define SIZE_MAP 150

void			draw_obs(t_game *game, t_img_data *minimap);
void			draw_player(t_game *game, t_img_data *minimap);
void			draw_grid(t_game *game, t_img_data *minimap);

#endif