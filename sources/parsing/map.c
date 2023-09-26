/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouvier <ebouvier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 09:43:00 by ebouvier          #+#    #+#             */
/*   Updated: 2023/09/26 11:49:32 by ebouvier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"
#include "lists.h"
#include "parsing.h"

static void	append_to_list(t_list **list, char *line)
{
	t_list	*newnode;
	char	*copy;

	copy = ft_strtrim(line, "\n");
	if (!copy)
		return ;
	newnode = ft_lstnew(copy);
	if (!newnode)
		return (free(copy));
	ft_lstadd_back(list, newnode);
}

void	parse_map_list(t_list **list, char *line, t_map *map)
{
	(void)map;
	append_to_list(list, line);
}
