/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmouradi <kmouradi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 16:15:51 by kmouradi          #+#    #+#             */
/*   Updated: 2023/05/16 18:43:47 by kmouradi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	char	**new_map;
	if (ac == 2)
	{
		puts("here 1");
		if (check_name(av[1]) == 0)
		{
			puts("here 2");
			exit(write(1, "Error\n", 7));
		}
		int fd = open (av[1], O_RDONLY);
		if (fd == -1)
		{
			exit(write(1, "Error fd\n", 9));
		}
		new_map = map_read(fd);
		if (ft_playable(new_map) == 1 && map_close(new_map) == 1 && map_size(new_map) == 1)
		{
			puts("Error");
		}
		puts("here");
	}
	// void	*mlx;
	// void	*mlx_win;

	// mlx = mlx_init();
	// mlx_win = mlx_new_window(mlx, 640, 640, "Kaoutar msatya");
	// mlx_loop(mlx);
}
