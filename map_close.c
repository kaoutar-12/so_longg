/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_close.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmouradi <kmouradi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 15:57:24 by kmouradi          #+#    #+#             */
/*   Updated: 2023/05/21 21:33:42 by kmouradi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_h(char **map)
{
	int	h;

	h = 0;
	while (map[h] != NULL)
		h++;
	return (h);
}

int	map_w(char **map)
{
	int	w;

	w = ft_strlen(map[0]);
	return (w);
}

int	map_close(char **map)
{
	t_game	game;
	int		last_colomn;
	int		last_row;

	game.i = -1;
	game.j = -1;
	last_row = map_h(map);
	last_colomn = map_w(map);
	while (map[++game.j])
	{
		game.i = -1;
		while (map[game.j][++game.i])
		{
			if (map[0][game.i] != '1' || map[game.j][0] != '1' || \
			map[game.j][last_colomn - 1] != '1' || \
			map[last_row - 1][game.i] != '1')
			{
				ft_printf("the map is not surrounded by walls.\n");
				return (0);
			}
		}
	}
	return (1);
}
