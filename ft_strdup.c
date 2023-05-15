/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmouradi <kmouradi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 14:27:51 by kmouradi          #+#    #+#             */
/*   Updated: 2023/05/15 17:10:36 by kmouradi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	int		len;
	char	*v;

	i = 0;
	len = ft_strlen(s1);
	v = (char *)(malloc(sizeof(char) * len + 1));
	if (v == 0)
		return (0);
	while (i < len)
	{
		v[i] = s1[i];
		i++;
	}
	v[i] = '\0';
	return (v);
}
// int main()
// {
// 	printf("%s",strdup("sksk"));
// }
