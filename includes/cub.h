/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoyer <mhoyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 12:53:47 by mhoyer            #+#    #+#             */
/*   Updated: 2023/09/20 13:27:01 by mhoyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <math.h>
# include <stdio.h>

# define SIZE_CASE 25
# define SIZE_PLAYER 4
# define RENDER_DIST 8

# define PI 3.1415926535
# define P2 PI / 2
# define P3 3 * PI / 2
# define DEGREE 0.0174533

typedef enum e_bool
{
	false,
	true,
}				t_bool;

typedef enum e_co
{
	CO_X,
	CO_Y,
}				t_co;

typedef struct s_img_data
{
	void		*img;
	char		*addr;
	int			bit_per_pixel;
	int			line_length;
	int			endian;
}				t_img_data;

typedef struct s_line
{
	float		x1;
	float		y1;
	float		x2;
	float		y2;
}				t_line;

typedef struct s_ray
{
	float		x;
	float		y;
	float		angle;
}				t_ray;

typedef struct s_player
{
	float		x;
	float		y;
	float		center_x;
	float		center_y;
	float		delta_x;
	float		delta_y;
	float		angle;
}				t_player;

typedef struct s_map_data
{
	char		**map;
	char		*array;
	int			x_max;
	int			y_max;
}				t_map_data;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	int			x_win;
	int			y_win;
	int			fov;
	t_img_data	buffer;
	t_map_data	d_map;
	t_player	player;
}				t_game;

// init
void			init_player(t_game *game);
void			init_game(t_game *game);

// display utils
void			my_mlx_pixel_put(t_img_data *buffer, int x, int y, int color);
t_line			create_line(float x1, float y1, float x2, float y2);
void			my_put_line(t_game *game, t_line line, int color);
void			my_put_line_w(t_game *game, t_line line, int color, int weight);

// display
void			draw_obs(t_game *game);
void			draw_player(t_game *game);
void			draw_grid(t_game *game);
void			draw_ray(t_game *game, t_bool calc);

// raycasting
float			calc_dist(float player_x, float player_y, float ray_x,
					float ray_y);
float			check_v(t_game *game, float *vx, float *vy, float angle);
float			check_h(t_game *game, float *hx, float *hy, float angle);

// key input
int				close_game(t_game *game);
int				check_input(int key, t_game *game);
int				loop(t_game *game);

// init data map
void			new_matrix(char *file, t_map_data *map);
void			new_array(t_game *game);

#endif
