/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmouradi <kmouradi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 16:15:51 by kmouradi          #+#    #+#             */
/*   Updated: 2023/05/20 18:42:11 by kmouradi         ###   ########.fr       */
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
			exit(write(1, "Error\n", 7));
		fd = open (av[1], O_RDONLY);
		if (fd == -1)
			exit(write(1, "Error fd\n", 9));
		game->new_map = map_read(fd);
		if (map_size(game) == 1)
			if (map_close(game->new_map) == 1)
				if (ft_playable(game) == 1)
					if(valid_path(*game) == 1)
						ft_game(game);
	}
}
