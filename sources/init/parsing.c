/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoyer <mhoyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 13:12:12 by mhoyer            #+#    #+#             */
/*   Updated: 2023/09/16 17:05:29 by mhoyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

char	**alloc_matrice(t_list *lst)
{
	int		i;
	t_list	*tmp;
	char	**mat;

	i = 0;
	mat = malloc((ft_lstsize(lst) + 1) * sizeof(char *));
	if (!mat)
		return (NULL);
	while (lst)
	{
		if (lst->next)
			mat[i] = ft_strdup_gnl(lst->content, 0,
					ft_strlen(lst->content) - 1);
		else
			mat[i] = ft_strdup(lst->content);
		i++;
		tmp = lst;
		lst = lst->next;
		ft_lstdelone(tmp);
	}
	mat[i] = NULL;
	return (mat);
}

void	new_matrix(char *file, t_map_data *map)
{
	int		fd;
	t_list	*lst;
	char	*str_tmp;

	lst = NULL;
	str_tmp = NULL;
	map->y_max = 0;
	fd = open(file, O_RDONLY);
	str_tmp = get_next_line(fd);
	while (str_tmp)
	{
		ft_lstadd_back(&lst, ft_lstnew(str_tmp));
		free(str_tmp);
		str_tmp = get_next_line(fd);
		map->y_max++;
	}
	close(fd);
	map->map = alloc_matrice(lst);
	if (map->map && map->map[0])
		map->x_max = ft_strlen(map->map[0]);
}

void	new_array(t_game *game)
{
	int x;
	int y;
	int	i;

	y = 0;
	i = 0;
	game->d_map.array = malloc(sizeof(char) * (game->d_map.x_max * game->d_map.y_max + 1));
	while (game->d_map.map[y])
	{
		x = 0;
		while (game->d_map.map[y][x])
		{
			game->d_map.array[i] = game->d_map.map[y][x];
			i++;
			x++;
		}
		game->d_map.array[i] = '\0';
		y++;
	}
}
