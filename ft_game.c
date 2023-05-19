/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmouradi <kmouradi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 09:51:19 by kmouradi          #+#    #+#             */
/*   Updated: 2023/05/19 10:18:12 by kmouradi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	xpm_to_img(t_game *game)
{
	game->p = mlx_xpm_file_to_image (game->mlx, "./new_ironman.xpm", \
	&game->img_w, &game->img_h);
	game->c = mlx_xpm_file_to_image(game->mlx, "./ironman_heart.xpm", \
	&game->img_w, &game->img_h);
	game->w = mlx_xpm_file_to_image(game->mlx, "./wall.xpm", &game->img_w, \
	&game->img_h);
	game->e = mlx_xpm_file_to_image(game->mlx, "./exit.xpm", &game->img_w, \
	&game->img_h);
	game->f = mlx_xpm_file_to_image(game->mlx, "./floor.xpm", &game->img_w, \
	&game->img_h);
}

void	img_to_win(t_game *game)
{
	game->j = -1;
	while (game->new_map[++game->j])
	{
		game->i = -1;
		while (game->new_map[game->j][++game->i])
		{
			if (game->new_map[game->j][game->i] == '1')
				mlx_put_image_to_window(game->mlx, game->mlx_win, \
				game->w, game->i * 50, game->j * 50);
			if (game->new_map[game->j][game->i] == '0')
				mlx_put_image_to_window(game->mlx, game->mlx_win, \
				game->f, game->i * 50, game->j * 50);
			if (game->new_map[game->j][game->i] == 'C')
				mlx_put_image_to_window(game->mlx, game->mlx_win, \
				game->c, game->i * 50, game->j * 50);
			if (game->new_map[game->j][game->i] == 'E')
				mlx_put_image_to_window(game->mlx, game->mlx_win, \
				game->e, game->i * 50, game->j * 50);
			if (game->new_map[game->j][game->i] == 'P')
				mlx_put_image_to_window(game->mlx, game->mlx_win, \
				game->p, game->i * 50, game->j * 50);
		}
	}
}

void	ft_game(t_game *game)
{
	game->mlx = mlx_init();
	game->mlx_win = mlx_new_window(game->mlx, ft_strlen(game->new_map[0]) * 50, \
	map_h(game->new_map) * 50, "so_long");
	xpm_to_img(game);
	img_to_win(game);
	mlx_loop(game->mlx);
}
