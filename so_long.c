/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmouradi <kmouradi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 16:15:51 by kmouradi          #+#    #+#             */
/*   Updated: 2023/05/18 21:32:57 by kmouradi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_game	game;
	t_data	data;

	if (ac == 2)
	{
		game.data = &data;
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
		if (map_size(&game) == 1)
		{
			if (map_close(game.new_map) == 1)
			{
				if (ft_playable(game.new_map) == 1)
				{
					// puts(" fddfs ");
					game.mlx = mlx_init();
					game.mlx_win = mlx_new_window(game.mlx, ft_strlen(game.new_map[0]) * 50, map_h(game.new_map) * 50, "so_long");
					// game.p = mlx_xpm_file_to_image (game.mlx, "./ironman.xpm", &game.img_w, &game.img_h);
					// game.c = mlx_xpm_file_to_image(game.mlx, "./ironman_heart.xpm", &game.img_w, &game.img_h);
					// game.w = mlx_xpm_file_to_image(game.mlx, "./wall.xpm", &game.img_w, &game.img_h);
					// game.e = mlx_xpm_file_to_image(game.mlx, "./exit.xpm", &game.img_w, &game.img_h);
					// game.f = mlx_xpm_file_to_image(game.mlx, "./floor.xpm", &game.img_w, &game.img_h);
					xpm_to_img(&game);
					int j = 0;
					while (game.new_map[j])
					{
						int i = 0;
						while (game.new_map[j][i])
						{
							if(game.new_map[j][i] == '1')
								mlx_put_image_to_window(game.mlx, game.mlx_win, game.w, i * 50, j * 50);
							if (game.new_map[j][i] == 'P')
								mlx_put_image_to_window(game.mlx, game.mlx_win, game.p, i * 50, j * 50);
							if (game.new_map[j][i] == 'C')
								mlx_put_image_to_window(game.mlx, game.mlx_win, game.c, i * 50, j * 50);
							if (game.new_map[j][i] == 'E')
								mlx_put_image_to_window(game.mlx, game.mlx_win, game.e, i * 50, j * 50);
							if (game.new_map[j][i] == '0')
								mlx_put_image_to_window(game.mlx, game.mlx_win, game.f, i * 50, j * 50);
							i++;
						}
						j++;
					}
					mlx_loop(game.mlx);
				}
			}
		}
	}
}
