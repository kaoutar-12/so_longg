/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmouradi <kmouradi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 16:04:06 by kmouradi          #+#    #+#             */
/*   Updated: 2023/05/24 08:13:29 by kmouradi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

int	check_surrounding(t_game *game, int posY, int posX)
{
	if ((game->path_map[posX - 1][posY] != '1'
		&& game->path_map[posX - 1][posY] != 'P')
		|| (game->path_map[posX + 1][posY] != '1'
		&& game->path_map[posX + 1][posY] != 'P')
		|| (game->path_map[posX][posY - 1] != '1'
		&& game->path_map[posX][posY - 1] != 'P')
		|| (game->path_map[posX][posY + 1] != '1'
		&& game->path_map[posX][posY + 1] != 'P'))
		return (0);
	return (1);
}

int	check_p(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->path_map && game->path_map[i])
	{
		j = 0;
		while (game->path_map[i][j])
		{
			if (game->path_map[i][j] == 'P')
			{
				if (check_surrounding(game, j, i) == 0)
					return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

void	fill_p(t_game *game, int posY, int posX)
{
	if (game->path_map[posX - 1][posY] == '0' || game->path_map[posX - 1][posY] == 'C' )
		game->path_map[posX - 1][posY] = 'P';
	if (game->path_map[posX + 1][posY] == '0' || game->path_map[posX + 1][posY] == 'C' )
		game->path_map[posX + 1][posY] = 'P';
	if (game->path_map[posX][posY - 1] == '0' || game->path_map[posX][posY - 1] == 'C' )
		game->path_map[posX][posY - 1] = 'P';
	if (game->path_map[posX][posY + 1] == '0' || game->path_map[posX][posY + 1] == 'C' )
		game->path_map[posX][posY + 1] = 'P';
}

void	find_p(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->path_map && game->path_map[i])
	{
		j = 0;
		while (game->path_map[i][j])
		{
			if (game->path_map[i][j] == 'P')
			{
				fill_p(game, j, i);
			}
			if (game->path_map[i][j] == 'E')
			{
				game->path_map[i][j] = '1';
			}
			j++;
		}
		i++;
	}
}

int	valid_path(t_game *game)
{
	int	j;
	int	i;

	while (check_p(game) == 0)
	{
		find_p(game);
	}
	i = 0;
	while (game->path_map && game->path_map[i])
	{
		j = 0;
		while (game->path_map[i][j])
		{
			if (game->path_map[i][j] == 'C' || game->path_map[i][j] == 'E')
			{
				ft_printf("wrong map\n");
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}
