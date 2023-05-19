/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_size.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmouradi <kmouradi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:50:08 by kmouradi          #+#    #+#             */
/*   Updated: 2023/05/19 10:51:47 by kmouradi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_size(t_game *game)
{
	game->j = 1;
	game->data->first_line = ft_strlen(game->new_map[0]);
	while (game->new_map[game->j])
	{
		if (ft_strlen(game->new_map[game->j]) == game->data->first_line)
			return (1);
		game->j++;
	}
	return (0);
}
