/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_name.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmouradi <kmouradi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 13:12:43 by kmouradi          #+#    #+#             */
/*   Updated: 2023/05/18 17:51:17 by kmouradi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_name(char *s)
{
	int	i;

	i = 0;
	i = ft_strlen(s);
	if (i > 5 && (s[i - 1] == 'r' && s[i - 2] == 'e' && s[i - 3] == 'b'\
	&& s[i - 4] == '.'))
		return (1);
	return (0);
}
