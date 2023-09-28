/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouvier <ebouvier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 14:49:03 by mhoyer            #+#    #+#             */
/*   Updated: 2023/09/28 13:19:17 by ebouvier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_cub3d(t_game *game)
{
	init_game(game);
	init_player(game);
}

void	hook_input(t_game game)
{
	mlx_loop_hook(game.mlx, &loop, &game);
	mlx_hook(game.win, KeyPress, KeyPressMask, &check_input, &game);
	mlx_hook(game.win, 17, 0, &close_game, &game);
	mlx_loop(game.mlx);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		error_and_exit("Usage: ./cub3D <map.cub>");
	init_map(&game.map);
	if (!parse_cubfile(argv[1], &game.map))
		exit(1);
	init_cub3d(&game);
	hook_input(game);
	return (0);
}
