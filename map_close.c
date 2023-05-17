/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_close.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmouradi <kmouradi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 15:57:24 by kmouradi          #+#    #+#             */
/*   Updated: 2023/05/17 13:54:29 by kmouradi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
int map_h(char **map)
{
	int h = 0;
	while(map[h] != NULL)
		h++;
	return(h);
}
int map_w(char **map)
{
	int w = ft_strlen(map[0]);
	return (w);
}
int map_close(char **map)
{
	int i = 0;
	int j = 0;

	int last_row = map_h(map);
	int last_colomn = map_w(map);
	while (map[j])
	{
		i = 0;
		while(map[j][i])
		{
		 	if(map[0][i] != '1' || map[j][0] != '1' || map[j][last_colomn - 1] != '1' || map[last_row - 1][i] != '1')
				return(0);
			i++;
		}
		j++;
	}
	return(1);
}
