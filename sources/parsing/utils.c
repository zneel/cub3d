/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouvier <ebouvier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 13:59:40 by ebouvier          #+#    #+#             */
/*   Updated: 2023/09/26 14:00:00 by ebouvier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	get_x_max(t_list *list)
{
	int	max;

	max = 0;
	while (list)
	{
		if ((int)ft_strlen(list->content) > max)
			max = ft_strlen(list->content);
		list = list->next;
	}
	return (max);
}
