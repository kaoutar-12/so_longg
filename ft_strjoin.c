/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmouradi <kmouradi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 11:20:41 by kmouradi          #+#    #+#             */
/*   Updated: 2022/10/31 11:20:41 by kmouradi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;

	i = -1;
	if (s1 && s2)
	{
		str = (char *)malloc(sizeof(char) * \
		(ft_strlen(s1) + ft_strlen(s2) + 1));
		if (str == NULL)
			return (NULL);
		while (s1[++i] != '\0')
		{
			str[i] = s1[i];
		}
		i = 0;
		while (s2[i] != '\0')
		{
			str[ft_strlen(s1) + i] = s2[i];
			i++;
		}
		str[ft_strlen(s1) + ft_strlen(s2)] = '\0';
		return (str);
	}
	return (0);
}
