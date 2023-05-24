/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmouradi <kmouradi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 11:37:16 by kmouradi          #+#    #+#             */
/*   Updated: 2022/12/03 19:40:21 by kmouradi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_unsigned(unsigned int n, int *len)
{
	long	x;

	x = n;
	if (x > 9)
		ft_putnbr((x / 10), len);
	ft_putchar(((x % 10) + 48), len);
}
