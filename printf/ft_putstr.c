/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmouradi <kmouradi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 10:12:42 by kmouradi          #+#    #+#             */
/*   Updated: 2023/05/21 21:22:37 by kmouradi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr(char *s, int *len)
{
	int	i;

	i = 0;
	if (s == NULL)
	{
		ft_putstr("(null)", len);
	}
	if (s != NULL)
	{
		while (s[i] != '\0')
		{
			ft_putchar(s[i], len);
			i++;
		}
	}
}
