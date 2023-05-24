/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmouradi <kmouradi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 11:06:11 by kmouradi          #+#    #+#             */
/*   Updated: 2023/05/21 17:53:46 by kmouradi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(int n, int *len)
{
	long	x;

	x = n;
	if (x < 0)
	{
		ft_putchar('-', len);
			x *= -1;
	}
	if (x > 9)
		ft_putnbr((x / 10), len);
	ft_putchar(((x % 10) + 48), len);
}
