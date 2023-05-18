/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_size.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmouradi <kmouradi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:50:08 by kmouradi          #+#    #+#             */
/*   Updated: 2023/05/18 15:24:48 by kmouradi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
int map_size(t_game *game)
{
	int j;

	j = 1;
	// printf("hna\n");
	// printf("%s\n", game->new_map[0]);
	// printf("%zu\n", ft_strlen(game->new_map[0]));
	game->data->first_line = ft_strlen(game->new_map[0]);
	// printf("hna\n");
	while(game->new_map[j])
	{
		if (ft_strlen(game->new_map[j]) == game->data->first_line)
			return(1);
		j++;
	}
	return (0);
}