/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoyer <mhoyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 12:53:47 by mhoyer            #+#    #+#             */
/*   Updated: 2023/09/30 12:47:47 by mhoyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft.h"
# include "lists.h"
# include "mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <errno.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>

# define X_SCREEN 1280
# define Y_SCREEN 720
# define TEXT_WIDTH 64
# define TEXT_HEIGHT 64
# define SIZE_CASE 32    // ?
# define SIZE_PLAYER 4.0 // ?
# define RENDER_DIST 32  // ?
# define ROT_SPEED 4
# define MOVE_SPEED 3

typedef bool	t_bool;

typedef enum e_map_value
{
	EMPTY = 0,
	WALL,
	SPACE,
	PN,
	PS,
	PW,
	PE,
	ERR,
}				t_map_value;

typedef struct s_bren
{
	int			dx;
	int			dy;
	int			err;
	int			e2;
	int			sx;
	int			sy;
}				t_bren;

typedef struct s_vec2
{
	float		x;
	float		y;
}				t_vec2;

typedef struct s_vec3
{
	float		x;
	float		y;
	t_vec2		dir;
}				t_vec3;

typedef struct s_img_data
{
	void		*img;
	char		*addr;
	int			bit_per_pixel;
	int			line_length;
	int			endian;
	int			width;
	int			height;
}				t_img_data;

typedef struct s_triangle
{
	double		x_top;
	double		y_top;
	double		x_base1;
	double		y_base1;
	double		x_base2;
	double		y_base2;
}				t_triangle;

typedef struct s_player
{
	double		x;
	double		y;
	double		pos_x;
	double		pos_y;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
	t_bool		move[6];
}				t_player;

typedef struct s_raycast
{
	double		camera_x;
	double		ray_dir_x;
	double		ray_dir_y;
	int			map_x;
	int			map_y;
	double		side_dist_x;
	double		side_dist_y;
	double		delta_dist_x;
	double		delta_dist_y;
	int			step_x;
	int			step_y;
	int			side;
	int			line_height;
	int			draw_start;
	int			draw_end;
	t_bool		is_hit;
}				t_raycast;

typedef struct s_map_data
{
	char		*no;
	t_bool		no_bool;
	char		*so;
	t_bool		so_bool;
	char		*we;
	t_bool		we_bool;
	char		*ea;
	t_bool		ea_bool;
	int			floor;
	int			ceiling;
	t_vec3		spawn;
	t_map_value	dir;
}				t_map_data;

typedef struct s_texture
{
	t_img_data	no;
	t_img_data	so;
	t_img_data	we;
	t_img_data	ea;
}				t_texture;

typedef struct s_map
{
	t_map_value	**map;
	int			x_max;
	int			y_max;
	t_map_data	data;
}				t_map;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	int			x_win;
	int			y_win;
	t_img_data	background;
	t_img_data	*buffer;
	t_img_data	*minimap;
	t_texture	tex;
	t_map		map;
	t_player	*player;
}				t_game;

// init
void			init_player(t_game *game);
void			init_game(t_game *game);
void			init_map(t_map *map);
void			init_img(t_game *game);
void			init_pgrm_img(t_game *game);

// display utils
int				my_mlx_get_color(t_img_data *img, int x, int y);
void			put_pixel(t_img_data *img, int x, int y, int color);
void			draw_line(t_img_data *img, t_vec2 start, t_vec2 end, int color);

// display
void			raycast(t_game *game);
void			print_background(t_game *game);
void			print_texture(t_game *game, t_raycast casted, int x,
					double perp);
void			print_minimap(t_game *game, int to_x, int to_y);

// move
double			degree_to_radians(double degree);
double			calculate_player_direction(t_player *player);
void			key_right(t_game *game);
void			key_left(t_game *game);
void			key_w(t_game *game);
void			key_s(t_game *game);
void			key_d(t_game *game);
void			key_a(t_game *game);

// key input
int				close_game(t_game *game);
int				check_press(int key, t_game *game);
int				check_release(int key, t_game *game);
int				loop(t_game *game);

// parsing
t_bool			parse_cubfile(char *file, t_map *map);

// helpers
double			calculate_player_direction(t_player *player);
void			error_and_exit(char *str);
void			perror_and_exit(char *prefix);

// clear
void			destroy_map(t_map *map);
void			free_exit(t_game *game);
void			destroy_exit(t_game *game);
void			free_split(char **split);

#endif
