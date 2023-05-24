/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmouradi <kmouradi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 09:51:19 by kmouradi          #+#    #+#             */
/*   Updated: 2023/05/24 09:25:38 by kmouradi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	printmsg1(void)
{
	ft_printf("xpm file empty!!!");
	exit(1);
}

void	xpm_to_img(t_game *game)
{
	game->p = mlx_xpm_file_to_image (game->mlx, "./thor.xpm", \
	&game->img_w, &game->img_h);
	game->c = mlx_xpm_file_to_image(game->mlx, "./thor_hammer.xpm", \
	&game->img_w, &game->img_h);
	game->w = mlx_xpm_file_to_image(game->mlx, "./wall.xpm", &game->img_w, \
	&game->img_h);
	game->e = mlx_xpm_file_to_image(game->mlx, "./exit.xpm", &game->img_w, \
	&game->img_h);
	game->f = mlx_xpm_file_to_image(game->mlx, "./floor.xpm", &game->img_w, \
	&game->img_h);
	if (!game->f || !game->p || !game->c || !game->w || !game->e)
		printmsg1();
}

void	img_to_win(t_game *game)
{
	game->j = -1;
	while (game->new_map[++game->j])
	{
		game->i = -1;
		while (game->new_map[game->j][++game->i])
		{
			mlx_put_image_to_window(game->mlx, game->mlx_win, \
				game->f, game->i * 50, game->j * 50);
			if (game->new_map[game->j][game->i] == '1')
				mlx_put_image_to_window(game->mlx, game->mlx_win, \
				game->w, game->i * 50, game->j * 50);
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

void	ft_find_player(t_game *game)
{
	game->j = -1;
	while (game->new_map[++game->j])
	{
		game->i = -1;
		while (game->new_map[game->j][++game->i])
		{
			if (game->new_map[game->j][game->i] == 'P')
			{
				game->p_x = game->i;
				game->p_y = game->j;
			}
		}
	}
}

int	ft_key(int keycode, t_game *game)
{
	int	s;

	if (keycode == 53)
		ft_close_game(game);
	ft_find_player(game);
	s = game->count_move;
	if (keycode == 13 || keycode == 126)
		ft_up(game);
	else if (keycode == 1 || keycode == 125)
		ft_down(game);
	else if (keycode == 0 || keycode == 123)
		ft_left(game);
	else if (keycode == 2 || keycode == 124)
		ft_right(game);
	if (s != game->count_move)
		printf("number of moves :%d\n", game->count_move);
	img_to_win(game);
	return (0);
}
