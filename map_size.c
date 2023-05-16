/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_size.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmouradi <kmouradi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:50:08 by kmouradi          #+#    #+#             */
/*   Updated: 2023/05/16 18:16:42 by kmouradi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
int map_size(char **map)
{
	int j;
	j = 0;
	size_t first_line = ft_strlen(map[0]);
	while(map[j])
	{
		if (ft_strlen(map[j]) != first_line)
			return(0);
		j++;
	}
		return (1);
}