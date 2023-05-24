/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmouradi <kmouradi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 12:59:20 by kmouradi          #+#    #+#             */
/*   Updated: 2023/05/21 17:53:26 by kmouradi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_check(char s, va_list arg, int *len )
{
	if (s == 'c')
		ft_putchar((char)va_arg(arg, int), len);
	else if (s == 's')
		ft_putstr(va_arg(arg, char *), len);
	else if (s == 'p')
	{
		ft_putstr("0x", len);
		ft_putadrs(va_arg(arg, unsigned long long), s, len);
	}
	else if (s == 'd' || s == 'i')
		ft_putnbr(va_arg(arg, int), len);
	else if (s == 'u')
		ft_putnbr_unsigned(va_arg(arg, unsigned int), len);
	else if (s == 'x' || s == 'X')
		ft_puthexa(va_arg(arg, unsigned int), s, len);
	else if (s == '%')
		ft_putchar(s, len);
}

int	ft_printf(const char *s, ...)
{
	va_list	arg;
	int		len;
	int		i;

	len = 0;
	i = 0;
	va_start(arg, s);
	while (s[i] != '\0')
	{
		if (s[i] == '%' && s[i + 1] != '\0')
		{
			i++;
			ft_check(s[i], arg, &len);
		}
		else
			ft_putchar(s[i], &len);
		i++;
	}
	va_end (arg);
	return (len);
}
