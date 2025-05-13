/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_func.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eakyurek <eakyurek@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 17:23:14 by eakyurek          #+#    #+#             */
/*   Updated: 2025/04/15 06:52:25 by eakyurek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n, unsigned int *count)
{
	char	c;

	if (n == -2147483648)
	{
		*count += write(1, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		*count += write(1, "-", 1);
		n = -n;
	}
	if (n > 9)
		ft_putnbr(n / 10, count);
	c = (n % 10) + '0';
	*count += write(1, &c, 1);
}

void	ft_putunbr(unsigned int n, unsigned int *count)
{
	char	c;

	if (n > 9)
		ft_putunbr(n / 10, count);
	c = (n % 10) + '0';
	*count += write(1, &c, 1);
}

void	ft_puthex(unsigned int n, char format_specifier, unsigned int *count)
{
	char	*hex;

	if (format_specifier == 'x')
		hex = "0123456789abcdef";
	else
		hex = "0123456789ABCDEF";
	if (n >= 16)
		ft_puthex(n / 16, format_specifier, count);
	*count += write(1, &hex[n % 16], 1);
}

void	ft_puthexs(unsigned long n, unsigned int *count)
{
	char	*hex;

	hex = "0123456789abcdef";
	if (n >= 16)
		ft_puthexs(n / 16, count);
	*count += write(1, &hex[n % 16], 1);
}

void	ft_putptr(void *ptr, unsigned int *count)
{
	if (!ptr)
	{
		*count += write(1, "(nil)", 5);
		return ;
	}
	*count += write(1, "0x", 2);
	ft_puthexs((unsigned long)ptr, count);
}
