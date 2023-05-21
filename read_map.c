/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmouradi <kmouradi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 16:58:41 by kmouradi          #+#    #+#             */
/*   Updated: 2023/05/21 15:31:58 by kmouradi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**map_read(int fd, t_game *game)
{
	char	*s;
	char	*str;
	char	**map;

	s = ft_strdup("");
	str = get_next_line(fd);
	while (str != NULL)
	{
		s = ft_strjoin(s, str);
		free (str);
		str = get_next_line(fd);
	}
	map = ft_split(s, '\n');
	game->path_map = ft_split(s, '\n');
	// free (str);
	free (s);
	return (map);
}
