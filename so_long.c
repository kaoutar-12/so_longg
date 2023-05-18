/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmouradi <kmouradi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 16:15:51 by kmouradi          #+#    #+#             */
/*   Updated: 2023/05/18 10:50:02 by kmouradi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_game	game;


	if (ac == 2)
	{
		if (check_name(av[1]) == 0)
		{
			exit(write(1, "Error\n", 7));
		}
		int fd = open (av[1], O_RDONLY);
		if (fd == -1)
		{
			exit(write(1, "Error fd\n", 9));
		}
		game.new_map = map_read(fd);
		if (map_size(game.new_map) == 0)
		{
			if (ft_playable(game.new_map) == 0)
			{
				if (map_close(game.new_map) == 0)
				{
					// puts(" fddfs ");
					game.mlx = mlx_init();
					game.mlx_win = mlx_new_window(game.mlx, 640, 640, "so_long");
					// game->data->addr = mlx_get_data_addr(game->data->img, &game->data->bits_per_pixel, &game->data->line_length,&game->data->endian);
					mlx_loop(game.mlx);

				}
			}
		}
	}
}
