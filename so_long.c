/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmouradi <kmouradi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 16:15:51 by kmouradi          #+#    #+#             */
/*   Updated: 2023/05/24 09:24:50 by kmouradi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_game(t_game *game)
{
	game->count_move = 0;
	game->mlx = mlx_init();
	game->mlx_win = mlx_new_window(game->mlx, ft_strlen(game->new_map[0]) * 50, \
	map_h(game->new_map) * 50, "so_long");
	xpm_to_img(game);
	img_to_win(game);
	mlx_hook(game->mlx_win, 2, 0, ft_key, game);
	mlx_hook(game->mlx_win, 17, 0, ft_close_game, game);
	mlx_loop(game->mlx);
}

int	main(int ac, char **av)
{
	t_game	*game;
	t_data	data;
	int		fd;

	if (ac == 2)
	{
		game = malloc(sizeof(t_game));
		if (game == NULL)
			return (0);
		game->data = &data;
		if (check_name(av[1]) == 0)
			exit(0);
		fd = open (av[1], O_RDONLY);
		if (fd == -1)
			exit(write(1, "wrong fd!!!\n", 12));
		game->new_map = map_read(fd, game);
		if (map_size(game) == 1 && map_close(game->new_map) == 1
			&& ft_playable(game) == 1 && valid_path(game) == 1)
			ft_game(game);
	}
	else
		ft_printf("error wrong argument!!!");
	return (0);
}
