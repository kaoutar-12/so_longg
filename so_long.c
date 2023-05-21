/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmouradi <kmouradi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 16:15:51 by kmouradi          #+#    #+#             */
/*   Updated: 2023/05/21 21:05:45 by kmouradi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_game	*game;
	t_data	data;
	int		fd;

	game = malloc(sizeof(t_game));
	if (ac == 2)
	{
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
}
