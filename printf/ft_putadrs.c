/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putadrs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmouradi <kmouradi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 20:29:40 by kmouradi          #+#    #+#             */
/*   Updated: 2022/12/03 19:38:47 by kmouradi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putadrs(unsigned long long nbr, char x, int *len)
{
	char	*base;

	base = "0123456789abcdef";
	if (nbr > 15)
	{
		ft_putadrs(nbr / 16, x, len);
		ft_putadrs(nbr % 16, x, len);
	}
	else
		ft_putchar(base[nbr], len);
}
