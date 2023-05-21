/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_playable.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmouradi <kmouradi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 11:39:56 by kmouradi          #+#    #+#             */
/*   Updated: 2023/05/21 20:24:59 by kmouradi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_playable(t_game *game)
{
	game->i = -1;
	game->j = -1;
	game->coli = 0;
	game->ex = 0;
	game->pl = 0;
	while (game->new_map[++game->j])
	{
		game->i = -1;
		while (game->new_map[game->j][++game->i])
		{
			if (game->new_map[game->j][game->i] == 'C')
				game->coli++;
			else if (game->new_map[game->j][game->i] == 'E')
				game->ex++;
			else if (game->new_map[game->j][game->i] == 'P')
				game->pl++;
		}
	}
	if (game->ex != 1 || game->pl != 1 || game->coli < 1)
	{
		ft_printf("the number of exit or player or collectible is wrong\n");
		return (0);
	}
	else
		return (1);
}
