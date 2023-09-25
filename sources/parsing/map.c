/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouvier <ebouvier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 09:43:00 by ebouvier          #+#    #+#             */
/*   Updated: 2023/09/25 10:54:47 by ebouvier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "lists.h"
#include "parsing.h"

t_bool	valid_char(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '1' && line[i] != '0' && line[i] != '2'
			&& line[i] != 'N' && line[i] != 'S' && line[i] != 'E'
			&& line[i] != 'W')
			return (false);
		i++;
	}
	return (true);
}

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
