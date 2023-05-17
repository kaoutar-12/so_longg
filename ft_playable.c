/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_playable.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmouradi <kmouradi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 11:39:56 by kmouradi          #+#    #+#             */
/*   Updated: 2023/05/17 13:49:35 by kmouradi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
int ft_playable(char **map)
{
	int i = 0;
	int j = 0;
	int c = 0;
	int e = 0;
	int p = 0;
	while(map[j])
	{
		i = 0;
		while(map[j][i])
		{
			if(map[j][i] == 'C')
				c++;
			else if(map[j][i] == 'E')
				e++;
			else if(map[j][i] == 'P')
				p++;
			i++;
		}
		j++;
	}
	if (e != 1 || p != 1 || c < 1)
		return (1);
	else
		return (0);
}
