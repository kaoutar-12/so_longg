/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_close_game.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmouradi <kmouradi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 11:48:09 by kmouradi          #+#    #+#             */
/*   Updated: 2023/05/24 09:23:25 by kmouradi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_close_game(t_game *game)
{
	int	j;

	j = 0;
	while (game->new_map[j])
	{
		free(game->new_map[j]);
		j++;
	}
	free (game->new_map);
	mlx_destroy_image(game->mlx, game->f);
	mlx_destroy_image(game->mlx, game->c);
	mlx_destroy_image(game->mlx, game->p);
	mlx_destroy_image(game->mlx, game->w);
	mlx_destroy_image(game->mlx, game->e);
	mlx_destroy_window(game->mlx, game->mlx_win);
	exit (0);
	return (0);
}
