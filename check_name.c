/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_name.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmouradi <kmouradi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 13:12:43 by kmouradi          #+#    #+#             */
/*   Updated: 2023/05/21 14:34:48 by kmouradi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_name(char *s)
{
	t_game	game;

	game.i = 0;
	game.i = ft_strlen(s);
	if (game.i > 5 && (s[game.i - 1] == 'r' && s[game.i - 2] == 'e' \
	&& s[game.i - 3] == 'b'\
	&& s[game.i - 4] == '.'))
		return (1);
	return (0);
}
