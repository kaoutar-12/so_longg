/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmouradi <kmouradi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 12:37:17 by kmouradi          #+#    #+#             */
/*   Updated: 2023/05/21 17:53:40 by kmouradi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_puthexa(unsigned int nbr, char x, int *len)
{
	char	*base;

	if (x == 'x')
	base = "0123456789abcdef";
	else
	base = "0123456789ABCDEF";
	if (nbr > 15)
	{
		ft_puthexa(nbr / 16, x, len);
		ft_puthexa(nbr % 16, x, len);
	}
	else
		ft_putchar(base[nbr], len);
}
