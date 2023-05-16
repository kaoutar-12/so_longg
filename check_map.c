/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmouradi <kmouradi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 15:57:24 by kmouradi          #+#    #+#             */
/*   Updated: 2023/05/16 11:40:13 by kmouradi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
int check_map(char **map)
{
	int f;
	int i = 0;
	int j = 0;
	f = 0;

	while (map[f])
		f++;
	while (map[j][i])
	{
		if (map[0][i] != '1' || map[j][ft_strlen(map[j-1])] != '1' || map[j][0] != '1' || map[f-1][i] != '1')
			return(0);
		i++;
		j++;
		f++;
	}
			return(1);
}
