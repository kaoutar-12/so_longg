/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmouradi <kmouradi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 13:10:39 by kmouradi          #+#    #+#             */
/*   Updated: 2023/05/20 11:18:31 by kmouradi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_up(t_game *game)
{
	if (game->new_map[game->p_y][game->p_x] == 'P')
	{
		if ((game->new_map[game->p_y - 1][game->p_x] == '0'
			|| game->new_map[game->p_y - 1][game->p_x] == 'C'))
		{
			if (game->new_map[game->p_y - 1][game->p_x] == 'C')
				game->coli--;
			game->new_map[game->p_y - 1][game->p_x] = 'P';
			game->new_map[game->p_y][game->p_x] = '0';
			game->count_move++;
		}
		if (game->new_map[game->p_y - 1][game->p_x] == 'E' && game->coli == 0)
			exit(write(1, "YOU WIN", 7));
	}
}

void	ft_down(t_game *game)
{
	if (game->new_map[game->p_y + 1][game->p_x] == '0'
		|| game->new_map[game->p_y + 1][game->p_x] == 'C')
	{
		if (game->new_map[game->p_y + 1][game->p_x] == 'C')
			game->coli--;
		game->new_map[game->p_y + 1][game->p_x] = 'P';
		game->new_map[game->p_y][game->p_x] = '0';
		game->count_move++;
	}
	if (game->new_map[game->p_y + 1][game->p_x] == 'E' && game->coli == 0)
		exit(write(1, "YOU WIN", 7));
}

void	ft_right(t_game *game)
{
	if (game->new_map[game->p_y][game->p_x] == 'P')
	{
		if (game->new_map[game->p_y][game->p_x + 1] == '0'
			|| game->new_map[game->p_y][game->p_x + 1] == 'C')
		{
			if (game->new_map[game->p_y][game->p_x + 1] == 'C')
				game->coli--;
			game->new_map[game->p_y][game->p_x + 1] = 'P';
			game->new_map[game->p_y][game->p_x] = '0';
			game->count_move++;
		}
		if (game->new_map[game->p_y][game->p_x + 1] == 'E' && game->coli == 0)
			exit(write(1, "YOU WIN", 7));
	}
}

void	ft_left(t_game *game)
{
	if (game->new_map[game->p_y][game->p_x] == 'P')
	{
		if (game->new_map[game->p_y][game->p_x - 1] == '0'
			|| game->new_map[game->p_y][game->p_x - 1] == 'C')
		{
			if (game->new_map[game->p_y][game->p_x - 1] == 'C')
				game->coli--;
			game->new_map[game->p_y][game->p_x - 1] = 'P';
			game->new_map[game->p_y][game->p_x] = '0';
			game->count_move++;
		}
		if (game->new_map[game->p_y][game->p_x - 1] == 'E' && game->coli == 0)
			exit(write(1, "YOU WIN", 7));
	}
}
